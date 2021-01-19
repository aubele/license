#include "LicenseGeneration.h"
#include "DlgFileName.h"

#include "QGridLayout"
#include "QPushButton"
#include "QDialogButtonBox"
#include "QCheckBox"
#include "QNetworkInterface"
#include "QMessageBox"
#include "QShortcut"

#include "windows.h"


////////////////////////////////////////////////////////////////////////////////////
// ### CONSTRUCTOR ###


LicenseGeneration::LicenseGeneration(QWidget *parent)
	: QMainWindow(parent)
{
	controller = new LicenseController();
	// Add the entries for the duration list
	durationList = {
		{ 1, "1 Monat" },
		{ 3, "3 Monate" },
		{ 6, "6 Monate" },
		{ 12, "1 Jahr" }
	};

	// Setup gui
	ui.setupUi(this);
	setUpGui();
}


LicenseGeneration::~LicenseGeneration()
{
}


////////////////////////////////////////////////////////////////////////////////////
// ### GUI SETUP ###


void LicenseGeneration::setUpGui()
{
	this->setWindowTitle("Lizenzgenerator");
	this->setWindowIcon(QIcon(":/LicenseGeneration/Resources/key.png"));

	setUpWarnings();
	setUpButtonBox();
	setUpMacAddress();
	setUpFeatures();
	setUpDurations();
	setUpCustomerNumber();
	setUpEmailValidator();
}


void LicenseGeneration::setUpWarnings()
{
	// Make all warnings inivisible
	ui.lblFirstNameWarning->setVisible(false);
	ui.lblLastNameWarning->setVisible(false);
	ui.lblEmailWarning->setVisible(false);
	ui.lblCompanyWarning->setVisible(false);
	ui.lblMacWarning->setVisible(false);
	ui.lblFeatureWarning->setVisible(false);
}


void LicenseGeneration::setUpButtonBox()
{
	// Custom buttonbox outside of the designer, because we need custom buttons
	QDialogButtonBox* buttonBox = new QDialogButtonBox(this);
	QPushButton* generate = new QPushButton("Generieren", this);
	// Add a shortcut for generate
	QShortcut *shortcut = new QShortcut(QKeySequence("Return"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(onGenerateLicenseFile()));
	connect(generate, SIGNAL(clicked()), this, SLOT(onGenerateLicenseFile()));
	buttonBox->addButton(generate, QDialogButtonBox::AcceptRole);
	QPushButton* cancel = new QPushButton("Cancel", buttonBox);
	connect(cancel, SIGNAL(clicked()), qApp, SLOT(quit()));
	buttonBox->addButton(cancel, QDialogButtonBox::RejectRole);
	// Add to layout
	QGridLayout* gridLayout = static_cast<QGridLayout*>(ui.centralWidget->layout());
	gridLayout->addWidget(buttonBox, gridLayout->rowCount(), gridLayout->columnCount()-1);
}


void LicenseGeneration::setUpMacAddress()
{
	// Mask for mac address
	ui.macLine->setInputMask(">HH:HH:HH:HH:HH:HH;_");
}


void LicenseGeneration::setUpFeatures()
{
	// Add slots for checkboxes
	connect(ui.featureFullScreenBox, SIGNAL(stateChanged(int)), this, SLOT(onFeatureFullScreenChange(int)));
	onFeatureFullScreenChange(ui.featureFullScreenBox->isChecked());
	connect(ui.featureSpeedBox, SIGNAL(stateChanged(int)), this, SLOT(onFeatureSpeedChange(int)));
	onFeatureSpeedChange(ui.featureSpeedBox->isChecked());
	connect(ui.featureColorBox, SIGNAL(stateChanged(int)), this, SLOT(onFeatureColorChange(int)));
	onFeatureColorChange(ui.featureColorBox->isChecked());
	connect(ui.featureHistogramBox, SIGNAL(stateChanged(int)), this, SLOT(onFeatureHistogramChange(int)));
	onFeatureHistogramChange(ui.featureHistogramBox->isChecked());
}


void LicenseGeneration::setUpDurations()
{
	// Add durations for each entry in the list
	for (Duration duration : durationList)
	{
		ui.durationCombo->addItem(duration.name, QVariant(duration.number));
	}
	// Add slot for combobox
	connect(ui.durationCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onDurationChange(int)));
	// Call it once so the expiration date gets calculated
	onDurationChange(ui.durationCombo->currentIndex());
}


void LicenseGeneration::setUpCustomerNumber()
{
	// Generate customer number
	const QString custNumb = controller->generateCustomerNumber(5);
	// Edit label
	ui.lblEnterCustNumb->setText(custNumb);
}


void LicenseGeneration::setUpEmailValidator()
{
	// Beautful regex for an email address
	QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
	// Add validator
	QValidator *validator = new QRegularExpressionValidator(regex, this);
	ui.emailLine->setValidator(validator);
}


////////////////////////////////////////////////////////////////////////////////////
// ### SLOTS ###


void LicenseGeneration::onFeatureFullScreenChange(int state)
{
	// Set the feature in the controller
	if (state == Qt::Checked)
	{
		controller->setModelFeatureFullScreen(true);
	}
	else
	{
		controller->setModelFeatureFullScreen(false);
	}
}


void LicenseGeneration::onFeatureSpeedChange(int state)
{
	// Set the feature in the controller
	if (state == Qt::Checked)
	{
		controller->setModelFeatureSpeed(true);
	}
	else
	{
		controller->setModelFeatureSpeed(false);
	}
}


void LicenseGeneration::onFeatureColorChange(int state)
{
	// Set the feature in the controller
	if (state == Qt::Checked)
	{
		controller->setModelFeatureColor(true);
	}
	else
	{
		controller->setModelFeatureColor(false);
	}
}


void LicenseGeneration::onFeatureHistogramChange(int state)
{
	// Set the feature in the controller
	if (state == Qt::Checked)
	{
		controller->setModelFeatureHistogram(true);
	}
	else
	{
		controller->setModelFeatureHistogram(false);
	}
}


void LicenseGeneration::onDurationChange(int index)
{
	// First calculate and set the expiraton date
	QDate expirationDate = controller->calculateExpirationDate(ui.durationCombo->itemData(index).toInt());
	// Then adjust the label
	ui.lblExpirationDate->setText("Resultierendes Ablaufdatum: " + expirationDate.toString("dd.MM.yyyy"));
}


void LicenseGeneration::onGenerateLicenseFile()
{
	// First check if all the input is valid
	if (validateInput())
	{
		// Ask the user if he has a keypair
		if (showKeyQuestion())
		{
			// Then set all the values in the model through the controller
			setAllValues();
			// Open dialog for a filename
			DlgFileName dlgFileName(this);
			if (dlgFileName.exec() == QDialog::Accepted)
			{
				// This is always the directory where the files get stored
				QString filePath = "./GeneratedLicense/";
				// Get the entered filename
				QString fileName = dlgFileName.getFileName();
				// Generate the license file and the signature
				controller->generateLicense(filePath, fileName);
			}
		}
	}
}


bool LicenseGeneration::showKeyQuestion()
{
	// Question for the user
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(ui.centralWidget,
		"Keypaar vorhanden?",
		"Zum Erstellen der Signatur benoetigt es ein gueltiges Keypaar.\n"
		"\n"
		"Bitte stellen Sie sicher, dass sich in dem Ordern dieser Anwendung zwei Dateien "
		"mit dem Namen 'privKey.txt' und 'pubKey.txt' befinden.",
		QMessageBox::Ok | QMessageBox::Cancel);
	if (reply == QMessageBox::Ok)
	{
		return true;
	}
	return false;
}


////////////////////////////////////////////////////////////////////////////////////
// ### VALUES ####


// Sets all values for the licensefile
void LicenseGeneration::setAllValues()
{
	controller->setModelFirstName(ui.firstNameLine->text());
	controller->setModelLastName(ui.lastNameLine->text());
	controller->setModelEmail(ui.emailLine->text());
	controller->setModelCompany(ui.companyLine->text());
	controller->setModelMac(ui.macLine->text());
	// Features are already set through signal slot
	controller->setModelDuration(ui.durationCombo->currentData().toInt());
	// Expirationdate is already set, when calculating it (when the combobox entry get changed from the user)
	// Customernumber is already set on setup in the controller since it does not get changed
}


////////////////////////////////////////////////////////////////////////////////////
// ### VALIDATE INPUT ###


bool LicenseGeneration::validateInput()
{
	// Check the input from all necessary fields
	bool firstName = isFirstNameInputValid();
	bool lastName = isLastNameInputValid();
	bool email = isEmailInputValid();
	bool company = isCompanyInputValid();
	bool mac = isMacInputValid();
	bool feature = isFeatureInputValid();

	// All fine?
	if (firstName && lastName && email && company && mac && feature)
	{
		return true;
	}
	return false;
}


bool LicenseGeneration::isFirstNameInputValid()
{
	// Just invalid if nothing got entered
	if (ui.firstNameLine->text().isEmpty())
	{
		ui.lblFirstNameWarning->setVisible(true);
		return false;
	}
	ui.lblFirstNameWarning->setVisible(false);
	return true;
}


bool LicenseGeneration::isLastNameInputValid()
{
	// Just invalid if nothing got entered
	if (ui.lastNameLine->text().isEmpty())
	{
		ui.lblLastNameWarning->setVisible(true);
		return false;
	}
	ui.lblLastNameWarning->setVisible(false);
	return true;
}


bool LicenseGeneration::isEmailInputValid()
{
	// Check email validator
	if (!ui.emailLine->hasAcceptableInput())
	{
		ui.lblEmailWarning->setVisible(true);
		return false;
	}
	ui.lblEmailWarning->setVisible(false);
	return true;
}


bool LicenseGeneration::isCompanyInputValid()
{
	// Just invalid if nothing got entered
	if (ui.companyLine->text().isEmpty())
	{
		ui.lblCompanyWarning->setVisible(true);
		return false;
	}
	ui.lblCompanyWarning->setVisible(false);
	return true;
}


bool LicenseGeneration::isMacInputValid()
{
	// Check input mask
	if (!ui.macLine->hasAcceptableInput())
	{
		ui.lblMacWarning->setVisible(true);
		return false;
	}
	ui.lblMacWarning->setVisible(false);
	return true;
}


bool LicenseGeneration::isFeatureInputValid() 
{
	// Is atleast one feature checked?
	QList<QCheckBox*> checkList = ui.features->findChildren<QCheckBox*>();
	for (QCheckBox* featureBox : checkList)
	{
		if (featureBox->isChecked())
		{
			ui.lblFeatureWarning->setVisible(false);
			return true;
		}
	}
	ui.lblFeatureWarning->setVisible(true);
	return false;
}
