#pragma once

#include "ui_DlgFileName.h"

#include <QDialog>


/**
* This is just a small dialog to offer the possibilty to enter a filename 
* for the licensefile.
*/
class DlgFileName : public QDialog
{
	Q_OBJECT

public:
	/**
	* Constructor, also setups the GUI
	*/
	DlgFileName(QWidget *parent = Q_NULLPTR);
	~DlgFileName();

	/**
	* Get the entered file name.
	* @return The entered file name.
	*/
	QString getFileName();

private:
	/**
	* Setup the whole GUI.
	* @see setUpButtonBox()
	*/
	void setUpGui();
	/**
	* Add signal slots to the button box.
	*/
	void setUpButtonBox();
	
	/**
	* Member for the ui-file from qt.
	*/
	Ui::DlgFileName ui;
	/**
	* Member for the entered file name.
	*/
	QString fileName;

private slots:
	/**
	* Slot for the ok-button. Checks if the input is valid and shows a warning if not.
	* Also sets the value and ends the dialog if everything is fine.
	*/
	void onSetFileName();
};
