#include "LicenseFileWriter.h"

#include "QFile"
#include "QTextStream"


LicenseFileWriter::LicenseFileWriter()
{
}

LicenseFileWriter::~LicenseFileWriter()
{
}

void LicenseFileWriter::createHeader(QString header)
{
	// Just append a new header
	licenseFileData.append(QPair<QString, QList<QString>>("[" + header + "]", QList<QString>()));
}

void LicenseFileWriter::createEntry(QString header, QString keyword, QString value)
{
	for (int i = 0; i < licenseFileData.length(); i++)
	{
		// First search the right header
		QPair<QString, QList<QString>> listEntry = licenseFileData.at(i);
		if (listEntry.first.compare("[" + header + "]") == 0)
		{
			// Then add the entry to the header
			QList<QString> valueList = listEntry.second;
			valueList.append(keyword + "=" + value);
			licenseFileData.replace(i, QPair<QString, QList<QString>>(listEntry.first, valueList));
			return;
		}
	}
}

void LicenseFileWriter::createEntry(QString header, QString keyword, int value)
{
	// Just call the method with the converted parameter
	createEntry(header, keyword, QString::number(value));
}

void LicenseFileWriter::createEntry(QString header, QString keyword, bool value)
{
	// Just call the method with the converted parameter
	createEntry(header, keyword, QString::number(value));
}

void LicenseFileWriter::createEntry(QString header, QString keyword, QDate value)
{
	// Just call the method with the converted parameter
	createEntry(header, keyword, value.toString("dd.MM.yyyy"));
}

bool LicenseFileWriter::write(QString filePath)
{
	// Open the file
	QFile file(filePath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;
	QTextStream out(&file);

	for (QPair<QString, QList<QString>> listEntry : licenseFileData)
	{
		// Write the header
		out << listEntry.first << "\n";
		// And then all the entries for this header
		for (QString headerEntry : listEntry.second)
		{
			out << headerEntry;
			out << "\n";
		}
		out << "\n";
	}
	return true;
}
