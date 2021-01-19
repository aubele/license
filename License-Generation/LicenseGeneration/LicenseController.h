#pragma once

#include "LicenseModel.h"

#include "QFile"


/**
* This class is responsible to create a valid license file, therefore it uses cryptographic
* operations to gurantee a correct signature. Also sets the data in the model.
*/
class LicenseController
{
public:
	/**
	* Constructor, also initializes the model.
	*/
	LicenseController();
	~LicenseController();

	/**
	* Generates a random customer number with various digits.
	* @param length The length of the customer number.
	* @return The customer number.
	*/
	QString generateCustomerNumber(int length);
	/**
	* Calculates a expiration date, takes the current date and adds the param duration in months.
	* @param duration The duration to the expiration date in months.
	* @return The calculated expiration date.
	*/
	QDate calculateExpirationDate(int duration);

	// All those methods just set values in the model
	void setModelFirstName(const QString& firstName);
	void setModelLastName(const QString& lastName);
	void setModelEmail(const QString& email);
	void setModelCompany(const QString& company);
	void setModelMac(const QString& mac);
	void setModelFeatureFullScreen(bool fullScreen);
	void setModelFeatureSpeed(bool speed);
	void setModelFeatureColor(bool color);
	void setModelFeatureHistogram(bool histogram);
	void setModelDuration(int duration);

	/**
	* Writes the license file, logs it it the specified logfile and creates the signature for 
	* the license.
	* @param filePath The path to the license file.
	* @param fileName The name of the license file.
	* @see writeLicenseFile()
	* @see logLicenseFile()
	* @see getFileTextAsByteArray()
	* @see writeSignatureForLicense()
	*/
	void generateLicense(QString filePath, QString fileName);
	/**
	* Creates a LicenseFileWriter and writes all the data from the model into the specified file.
	* @param licenseFilePath Path to the file, which gets written.
	*/
	void writeLicenseFile(QString licenseFilePath);
	/**
	* Gets the whole text from the specified file as QByteArray. Empty on error.
	* @param filePath Path to the file.
	* @return The whole text from the file.
	*/
	QByteArray getFileTextAsByteArray(QString filePath);
	/**
	* Writes the license string from createLicenseString() into a logfile.
	* @param filePath The path to the log file.
	* @param licenseFileName The name of the license file.
	*/
	void logLicenseFile(QString logFilePath, QString licenseFilePath, QString licenseFileName);

	/**
	* Creates the RSA-Signature for the licensefile with the CrpytoPP library.
	* @param licenseDataInBytes The string written in the license file as QByteArray for converting reasons.
	* @param signaturePath Path to the signaturefile
	* @return The Signature as a CryptoPP object.
	*/
	void writeSignatureForLicense(QByteArray licenseDataInBytes, QString signaturePath);

private:
	/**
	* Private member for the data from the license.
	*/
	LicenseModel* model;
};
