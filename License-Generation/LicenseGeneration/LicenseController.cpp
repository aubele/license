#include "LicenseController.h"
#include "LicenseFileWriter.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "QTextStream"

// Crypto++ Library
#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

#include <rsa.h>
#include <osrng.h>
#include <base64.h>
#include <files.h>

using namespace CryptoPP;


LicenseController::LicenseController()
{
	model = new LicenseModel();
}


LicenseController::~LicenseController()
{
}


////////////////////////////////////////////////////////////////////////////////////
// ### OTHER OPERATIONS ###


QString LicenseController::generateCustomerNumber(int length)
{
	QString randomCustNumb = "";

	// Initialize random seed
	srand(time(NULL));

	for (int i = 0; i < length; i++)
	{
		// Generate secret number between 1 and 10
		int randNumb = rand() % 10;
		randomCustNumb.insert(i, QString::number(randNumb));
	}
	// Set it in the model since this does not get changed in the view and only
	// gets called one time
	model->setCustomerNumber(randomCustNumb);
	return randomCustNumb;
}


QDate LicenseController::calculateExpirationDate(int duration)
{
	// Get todays date
	QDate today = QDate::currentDate();
	// Add the duration in months
	QDate expirationDate = today.addMonths(duration);
	// Set it in the model since this gets called everytime the expiration date
	// gets changed
	model->setExpirationDate(expirationDate);

	return expirationDate;
}


////////////////////////////////////////////////////////////////////////////////////
// ### MODEL ###


void LicenseController::setModelFirstName(const QString& firstName)
{
	model->setFirstName(firstName);
}


void LicenseController::setModelLastName(const QString& lastName)
{
	model->setLastName(lastName);
}


void LicenseController::setModelEmail(const QString& email)
{
	model->setEmail(email);
}


void LicenseController::setModelCompany(const QString& company)
{
	model->setCompany(company);
}


void LicenseController::setModelMac(const QString& mac)
{
	model->setMac(mac);
}


void LicenseController::setModelFeatureFullScreen(bool fullScreen)
{
	model->setFeatureFullScreen(fullScreen);
}


void LicenseController::setModelFeatureSpeed(bool speed)
{
	model->setFeatureSpeed(speed);
}


void LicenseController::setModelFeatureColor(bool color)
{
	model->setFeatureColor(color);
}


void LicenseController::setModelFeatureHistogram(bool histogram)
{
	model->setFeatureHistogram(histogram);
}


void LicenseController::setModelDuration(int duration)
{
	model->setDuration(duration);
}


////////////////////////////////////////////////////////////////////////////////////
// ### FILE OPERATIONS ###


void LicenseController::generateLicense(QString filePath, QString fileName)
{
	// License path
	QString licenseFilePath = filePath + fileName + ".lic";
	// Write the license file
	writeLicenseFile(licenseFilePath);

	// Then log it
	logLicenseFile("./License.log", licenseFilePath, fileName);

	// Data from the license file
	QByteArray licenseDataInBytes = getFileTextAsByteArray(licenseFilePath);
	// Signature path
	QString signaturePath = filePath + fileName + ".sig";
	// Write the signature
	writeSignatureForLicense(licenseDataInBytes, signaturePath);
}


void LicenseController::writeLicenseFile(QString licenseFilePath)
{
	/*
	## Aufbau ##
	[Klasse]
	Attribut-Keyword=Attribut-Wert
	z.B.
	[Customer]
	firstname=Thomas
	lastname=Minz
	email=tho.minz@bmw.de
	company=BMW Sales
	customerNumber=32456

	[Product]
	fullScreen=1
	speed=0
	color=0
	histogram=1
	duration=6
	expirationDate=12.08.2018

	[Licensing]
	mac=60:A4:4C:2F:8F:42
	key=134FSD45...
	*/
	LicenseFileWriter* writer = new LicenseFileWriter();
	writer->createHeader("Customer");
	// Firstname string
	writer->createEntry("Customer", model->getKeyWordFirstName(), model->getFirstName());
	// Lastname string
	writer->createEntry("Customer", model->getKeyWordLastName(), model->getLastName());
	// Email string
	writer->createEntry("Customer", model->getKeyWordEmail(), model->getEmail());
	// Company string
	writer->createEntry("Customer", model->getKeyWordCompany(), model->getCompany());
	// Customernumber string
	writer->createEntry("Customer", model->getKeyWordCustomerNumber(), model->getCustomerNumber());

	writer->createHeader("Product");
	// Feature fullscreen bool
	writer->createEntry("Product", model->getKeyWordFullScreen(), model->getFeatureFullScreen());
	// Feature speed bool
	writer->createEntry("Product", model->getKeyWordSpeed(), model->getFeatureSpeed());
	// Feature color bool
	writer->createEntry("Product", model->getKeyWordColor(), model->getFeatureColor());
	// Feature histogram bool
	writer->createEntry("Product", model->getKeyWordHistogram(), model->getFeatureHistogram());
	// Duration int
	writer->createEntry("Product", model->getKeyWordDuration(), model->getDuration());
	// Expirationdate QDate
	writer->createEntry("Product", model->getKeyWordExpirationDate(), model->getExpirationDate());

	writer->createHeader("Licensing");
	// Mac string
	writer->createEntry("Licensing", model->getKeyWordMac(), model->getMac());

	// Write file
	writer->write(licenseFilePath);
	delete writer;
}


QByteArray LicenseController::getFileTextAsByteArray(QString filePath)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return QByteArray();
	// Just return the whole text
	return file.readAll();
}


void LicenseController::logLicenseFile(QString logFilePath, QString licenseFilePath, QString licenseFileName)
{
	// Open log file
	QFile file(logFilePath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
		return;
	QTextStream out(&file);

	// Write
	QDateTime now;
	out << "Das Lizenzfile " << licenseFileName << " wurde am " << now.currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
		<< " erstellt und folgende Daten wurden eingetragen: " << endl;
	out << getFileTextAsByteArray(licenseFilePath);
}


////////////////////////////////////////////////////////////////////////////////////
// ### RSA SIGNATURE ###


void LicenseController::writeSignatureForLicense(QByteArray licenseDataInBytes, QString signaturePath)
{
	AutoSeededRandomPool rng;

	// Read private key
	CryptoPP::ByteQueue bytes;
	FileSource file("privkey.txt", true, new Base64Decoder);
	file.TransferTo(bytes);
	bytes.MessageEnd();
	RSA::PrivateKey privateKey;
	privateKey.Load(bytes);

	// Sign message
	RSASSA_PKCS1v15_SHA_Signer privkey(privateKey);
	SecByteBlock sbbSignature(privkey.SignatureLength());
	privkey.SignMessage(
		rng,
		(byte const*)licenseDataInBytes.data(),
		licenseDataInBytes.size(),
		sbbSignature);

	// Save the signature with cryptopp library, cause then verifing is easier
	// Therefore we need the filepath as char
	QByteArray baSignaturePath = signaturePath.toLatin1();
	const char* cSignaturePath = baSignaturePath.data();
	FileSink sinksig(cSignaturePath);
	sinksig.Put(sbbSignature, sbbSignature.size());
}
