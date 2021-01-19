#pragma once

#include "QString"
#include "QPair"
#include "QList"
#include "QDate"


/**
* This class is offering a dynamic approach on writing a licensefile, it is possible to create 
* a file with the following structure:
*
* [Header]
* entry1 (keyword=value)
* entry2 (keyword=value)
* entry3 (keyword=value)
*
* Therefore the data, which gets set through the public methods, get saved in a QList of QPairs.
* The firs value in this QPair is always the header name, all the entries below this header get 
* saved in the second value of the QPair, which is a QList with two QStrings, a keyword to identify
* the entry again and the specified value for this keyword.
*
* To use this class correctly, you first need to set the data through the specified methods. When 
* finished you can call the write method, to write all the data in the speicified path.
*/
class LicenseFileWriter
{
public:
	LicenseFileWriter();
	~LicenseFileWriter();

	/**
	* Creates a new header in licenseFileData.
	* @param header The name of the new header.
	*/
	void createHeader(QString header);
	/**
	* Creates a entry for the specified header, consisting of keyword and value.
	* @param header The name for the header.
	* @param keyword The name for the keyword.
	* @param value The specified value for the keyword.
	*/
	void createEntry(QString header, QString keyword, QString value);
	/**
	*Overloaded method for int values.
	* @see createEntry()
	*/
	void createEntry(QString header, QString keyword, int value);
	/**
	* Overloaded method for boolean values.
	* @see createEntry()
	*/
	void createEntry(QString header, QString keyword, bool value);
	/**
	* Overloaded method for QDate values.
	* @see createEntry()
	*/
	void createEntry(QString header, QString keyword, QDate value);

	/**
	* Writes the data in licenseFileData into a file, which is specified through the 
	* parameter.
	* @param filePath The path to the file.
	* @return True if the file is accessible.
	*/
	bool write(QString filePath);

private:
	/**
	* Member where all the data gets stored, when the write-method is called, all the 
	* data stored here gets written in the file.
	*/
	QList<QPair<QString, QList<QString>>> licenseFileData;
};