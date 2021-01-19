#pragma once

#include "ui_LicenseGeneration.h"
#include "LicenseController.h"

#include <QMainWindow>


/**
* Struct for the duration combo box, contains a number to calculate the 
* expiration date and a string, which gets displayed.
*/
struct Duration {
	int number;
	QString name;
};

/**
* This class is responsible for creating the view, call the right methods in the
* controller and validating the user input.
*/
class LicenseGeneration : public QMainWindow
{
	Q_OBJECT

public:
	/**
	* Constructor, also initializes the controller and the GUI.
	* @see setUpGui()
	*/
	LicenseGeneration(QWidget *parent = Q_NULLPTR);
	~LicenseGeneration();

private:
	/**
	* Setup the whole GUI.
	* @see setUpWarnings()
	* @see setUpButtonBox()
	* @see setUpKeyButton()
	* @see setUpMacAddress()
	* @see setUpFeatures()
	* @see setUpDurations()
	* @see setUpCustomerNumber()
	* @see setUpEmailValidator()
	*/
	void setUpGui();
	/**
	* Sets all the warnings for wrong input to invisible.
	*/
	void setUpWarnings();
	/**
	* Creates a custom button box with generate and cancel.
	*/
	void setUpButtonBox();
	/**
	* Sets the input mask for the mac address textline.
	*/
	void setUpMacAddress();
	/**
	* Creates all the checkboxes for the features with fitting warning label.
	*/
	void setUpFeatures();
	/**
	* Setup the combobox with all the durations.
	*/
	void setUpDurations();
	/**
	* Creates and displays a customer Number.
	*/
	void setUpCustomerNumber();
	/**
	* Setups the validator for the email textline with regex.
	*/
	void setUpEmailValidator();

	/**
	* Check if all the input is fine according to the validators.
	* @see isFirstNameInputValid()
	* @see isLastNameInputValid()
	* @see isEmailInputValid()
	* @see isCompanyInputValid()
	* @see isMacInputValid()
	* @see isFeatureInputValid()
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool validateInput();
	/**
	* Check if the input for the firstname is fine.
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool isFirstNameInputValid();
	/**
	* Check if the input for the lastname is fine.
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool isLastNameInputValid();
	/**
	* Check if the input for the email is fine.
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool isEmailInputValid();
	/**
	* Check if the input for the company is fine.
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool isCompanyInputValid();
	/**
	* Check if the input for the mac-address is fine.
	* @return True if the input is fine according to the validators, false if not.
	*/
	bool isMacInputValid();
	/**
	* Check if the at least one feature is checked.
	* @return True if at least one feature is checked, false if not.
	*/
	bool isFeatureInputValid();

	/**
	* Set all the values in the model through the controller to contain the pattern.
	*/
	void setAllValues();
	/**
	* Ask the user if he has a valid keypair, before generating the license.
	* @return True if the user says he has a valid keypair, else false.
	*/
	bool showKeyQuestion();

	/**
	* Member for the ui-file from qt.
	*/
	Ui::LicenseGenerationClass ui;
	/**
	* Member for the controller.
	*/
	LicenseController* controller;
	/**
	* List of all valuable durations.
	*/
	QList<Duration> durationList;

private slots:
	/**
	* Slot if the checkbox for the fullscreen feature gets changed. Sets the corresponding
	* value in the controller.
	*/
	void onFeatureFullScreenChange(int state);
	/**
	* Slot if the checkbox for the speed feature gets changed. Sets the corresponding
	* value in the controller.
	*/
	void onFeatureSpeedChange(int state);
	/**
	* Slot if the checkbox for the color feature gets changed. Sets the corresponding
	* value in the controller.
	*/
	void onFeatureColorChange(int state);
	/**
	* Slot if the checkbox for the histogram feature gets changed. Sets the corresponding
	* value in the controller.
	*/
	void onFeatureHistogramChange(int state);

	/**
	* Slot for the generate license button. Goes through all nessecary steps to create a license file. 
	* it validates the input, asks the user about the keypair, sets the data in the model, asks about 
	* a filename and then calls the appropiate function in the controller to generate the license file.
	* @see validateInput()
	* @see showKeyQuestion()
	* @see setAllValues()
	*/
	void onGenerateLicenseFile();
	/**
	* Slot for the duration combobox, if a new value gets selected, it calculates the new 
	* expiration date and adjusts the label.
	*/
	void onDurationChange(int index);
};
