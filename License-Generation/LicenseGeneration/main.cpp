#include "LicenseGeneration.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	// Basically just start the application
	QApplication a(argc, argv);
	LicenseGeneration w;
	w.show();
	return a.exec();
}
