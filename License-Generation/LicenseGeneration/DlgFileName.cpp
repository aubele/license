#include "DlgFileName.h"

#include "QPushButton"
#include "QDialogButtonBox"


DlgFileName::DlgFileName(QWidget *parent)
	: QDialog(parent)
{
	// Setup GUI
	ui.setupUi(this);
	setUpGui();
}


DlgFileName::~DlgFileName()
{
}


void DlgFileName::setUpGui()
{
	this->setWindowTitle("Dateiname angeben");
	this->setWindowIcon(QIcon(":/LicenseGeneration/Resources/key.png"));

	ui.lblWarning->setVisible(false);

	setUpButtonBox();
}


void DlgFileName::setUpButtonBox()
{
	// Edit signal slots from the buttonbox
	QDialogButtonBox* buttonBox = ui.buttonBox;
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(onSetFileName()));
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}


QString DlgFileName::getFileName()
{
	return fileName;
}


void DlgFileName::onSetFileName()
{
	// Check if the filename is legit according to the windowos guidelines
	if (ui.fileNameLine->text().contains("\\") || ui.fileNameLine->text().contains("/") ||
		ui.fileNameLine->text().contains(":") || ui.fileNameLine->text().contains("*") ||
		ui.fileNameLine->text().contains("?") || ui.fileNameLine->text().contains("\"") ||
		ui.fileNameLine->text().contains("<") || ui.fileNameLine->text().contains(">") ||
		ui.fileNameLine->text().contains("|") || ui.fileNameLine->text().isEmpty())
	{
		// Show warning
		ui.lblWarning->setVisible(true);
	}
	else
	{
		ui.lblWarning->setVisible(false);
		// Set the entered filename
		fileName = ui.fileNameLine->text();
		// End dialog
		this->accept();
	}
}
