/********************************************************************************
** Form generated from reading UI file 'LicenseGeneration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSEGENERATION_H
#define UI_LICENSEGENERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LicenseGenerationClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *email;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *emailLine;
    QLabel *lblEmailWarning;
    QWidget *lastName;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lastNameLine;
    QLabel *lblLastNameWarning;
    QWidget *firstName;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *firstNameLine;
    QLabel *lblFirstNameWarning;
    QWidget *time;
    QVBoxLayout *verticalLayout;
    QComboBox *durationCombo;
    QLabel *lblExpirationDate;
    QWidget *mac;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *macLine;
    QLabel *lblMacWarning;
    QWidget *company;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *companyLine;
    QLabel *lblCompanyWarning;
    QWidget *features;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *featureFullScreenBox;
    QCheckBox *featureSpeedBox;
    QCheckBox *featureColorBox;
    QCheckBox *featureHistogramBox;
    QLabel *lblFeatureWarning;
    QLabel *lblLastName;
    QLabel *lblEnterCustNumb;
    QLabel *lblCustomerNumber;
    QLabel *lblMac;
    QLabel *lblEmail;
    QLabel *lblFirstName;
    QLabel *lblCompany;
    QLabel *lblFeatures;
    QLabel *lblDuration;

    void setupUi(QMainWindow *LicenseGenerationClass)
    {
        if (LicenseGenerationClass->objectName().isEmpty())
            LicenseGenerationClass->setObjectName(QStringLiteral("LicenseGenerationClass"));
        LicenseGenerationClass->resize(458, 509);
        centralWidget = new QWidget(LicenseGenerationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(12);
        gridLayout->setContentsMargins(9, -1, -1, -1);
        email = new QWidget(centralWidget);
        email->setObjectName(QStringLiteral("email"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(email);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        emailLine = new QLineEdit(email);
        emailLine->setObjectName(QStringLiteral("emailLine"));

        verticalLayout_2->addWidget(emailLine);

        lblEmailWarning = new QLabel(email);
        lblEmailWarning->setObjectName(QStringLiteral("lblEmailWarning"));
        lblEmailWarning->setEnabled(true);
        lblEmailWarning->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));

        verticalLayout_2->addWidget(lblEmailWarning);


        gridLayout->addWidget(email, 3, 2, 1, 1);

        lastName = new QWidget(centralWidget);
        lastName->setObjectName(QStringLiteral("lastName"));
        sizePolicy.setHeightForWidth(lastName->sizePolicy().hasHeightForWidth());
        lastName->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(lastName);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lastNameLine = new QLineEdit(lastName);
        lastNameLine->setObjectName(QStringLiteral("lastNameLine"));

        verticalLayout_4->addWidget(lastNameLine);

        lblLastNameWarning = new QLabel(lastName);
        lblLastNameWarning->setObjectName(QStringLiteral("lblLastNameWarning"));
        lblLastNameWarning->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));

        verticalLayout_4->addWidget(lblLastNameWarning);


        gridLayout->addWidget(lastName, 2, 2, 1, 1);

        firstName = new QWidget(centralWidget);
        firstName->setObjectName(QStringLiteral("firstName"));
        sizePolicy.setHeightForWidth(firstName->sizePolicy().hasHeightForWidth());
        firstName->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(firstName);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        firstNameLine = new QLineEdit(firstName);
        firstNameLine->setObjectName(QStringLiteral("firstNameLine"));

        verticalLayout_3->addWidget(firstNameLine);

        lblFirstNameWarning = new QLabel(firstName);
        lblFirstNameWarning->setObjectName(QStringLiteral("lblFirstNameWarning"));
        lblFirstNameWarning->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));

        verticalLayout_3->addWidget(lblFirstNameWarning);


        gridLayout->addWidget(firstName, 1, 2, 1, 1);

        time = new QWidget(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        sizePolicy.setHeightForWidth(time->sizePolicy().hasHeightForWidth());
        time->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(time);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        durationCombo = new QComboBox(time);
        durationCombo->setObjectName(QStringLiteral("durationCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(durationCombo->sizePolicy().hasHeightForWidth());
        durationCombo->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(durationCombo);

        lblExpirationDate = new QLabel(time);
        lblExpirationDate->setObjectName(QStringLiteral("lblExpirationDate"));
        sizePolicy.setHeightForWidth(lblExpirationDate->sizePolicy().hasHeightForWidth());
        lblExpirationDate->setSizePolicy(sizePolicy);
        lblExpirationDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblExpirationDate);


        gridLayout->addWidget(time, 11, 2, 1, 1);

        mac = new QWidget(centralWidget);
        mac->setObjectName(QStringLiteral("mac"));
        sizePolicy.setHeightForWidth(mac->sizePolicy().hasHeightForWidth());
        mac->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(mac);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        macLine = new QLineEdit(mac);
        macLine->setObjectName(QStringLiteral("macLine"));

        verticalLayout_6->addWidget(macLine);

        lblMacWarning = new QLabel(mac);
        lblMacWarning->setObjectName(QStringLiteral("lblMacWarning"));
        lblMacWarning->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));

        verticalLayout_6->addWidget(lblMacWarning);


        gridLayout->addWidget(mac, 5, 2, 1, 1);

        company = new QWidget(centralWidget);
        company->setObjectName(QStringLiteral("company"));
        sizePolicy.setHeightForWidth(company->sizePolicy().hasHeightForWidth());
        company->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(company);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        companyLine = new QLineEdit(company);
        companyLine->setObjectName(QStringLiteral("companyLine"));

        verticalLayout_5->addWidget(companyLine);

        lblCompanyWarning = new QLabel(company);
        lblCompanyWarning->setObjectName(QStringLiteral("lblCompanyWarning"));
        lblCompanyWarning->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));
        lblCompanyWarning->setWordWrap(true);

        verticalLayout_5->addWidget(lblCompanyWarning);


        gridLayout->addWidget(company, 4, 2, 1, 1);

        features = new QWidget(centralWidget);
        features->setObjectName(QStringLiteral("features"));
        sizePolicy.setHeightForWidth(features->sizePolicy().hasHeightForWidth());
        features->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(features);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        featureFullScreenBox = new QCheckBox(features);
        featureFullScreenBox->setObjectName(QStringLiteral("featureFullScreenBox"));

        verticalLayout_7->addWidget(featureFullScreenBox);

        featureSpeedBox = new QCheckBox(features);
        featureSpeedBox->setObjectName(QStringLiteral("featureSpeedBox"));

        verticalLayout_7->addWidget(featureSpeedBox);

        featureColorBox = new QCheckBox(features);
        featureColorBox->setObjectName(QStringLiteral("featureColorBox"));

        verticalLayout_7->addWidget(featureColorBox);

        featureHistogramBox = new QCheckBox(features);
        featureHistogramBox->setObjectName(QStringLiteral("featureHistogramBox"));

        verticalLayout_7->addWidget(featureHistogramBox);

        lblFeatureWarning = new QLabel(features);
        lblFeatureWarning->setObjectName(QStringLiteral("lblFeatureWarning"));
        lblFeatureWarning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout_7->addWidget(lblFeatureWarning);


        gridLayout->addWidget(features, 8, 2, 1, 1);

        lblLastName = new QLabel(centralWidget);
        lblLastName->setObjectName(QStringLiteral("lblLastName"));
        lblLastName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblLastName, 2, 0, 1, 1);

        lblEnterCustNumb = new QLabel(centralWidget);
        lblEnterCustNumb->setObjectName(QStringLiteral("lblEnterCustNumb"));
        sizePolicy.setHeightForWidth(lblEnterCustNumb->sizePolicy().hasHeightForWidth());
        lblEnterCustNumb->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lblEnterCustNumb, 16, 2, 1, 1);

        lblCustomerNumber = new QLabel(centralWidget);
        lblCustomerNumber->setObjectName(QStringLiteral("lblCustomerNumber"));

        gridLayout->addWidget(lblCustomerNumber, 16, 0, 1, 1);

        lblMac = new QLabel(centralWidget);
        lblMac->setObjectName(QStringLiteral("lblMac"));
        lblMac->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblMac, 5, 0, 1, 1);

        lblEmail = new QLabel(centralWidget);
        lblEmail->setObjectName(QStringLiteral("lblEmail"));
        lblEmail->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblEmail, 3, 0, 1, 1);

        lblFirstName = new QLabel(centralWidget);
        lblFirstName->setObjectName(QStringLiteral("lblFirstName"));
        lblFirstName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblFirstName, 1, 0, 1, 1);

        lblCompany = new QLabel(centralWidget);
        lblCompany->setObjectName(QStringLiteral("lblCompany"));
        lblCompany->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblCompany, 4, 0, 1, 1);

        lblFeatures = new QLabel(centralWidget);
        lblFeatures->setObjectName(QStringLiteral("lblFeatures"));
        lblFeatures->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblFeatures, 8, 0, 1, 1);

        lblDuration = new QLabel(centralWidget);
        lblDuration->setObjectName(QStringLiteral("lblDuration"));
        lblDuration->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(lblDuration, 11, 0, 1, 1);

        LicenseGenerationClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(firstNameLine, lastNameLine);
        QWidget::setTabOrder(lastNameLine, emailLine);
        QWidget::setTabOrder(emailLine, companyLine);
        QWidget::setTabOrder(companyLine, macLine);
        QWidget::setTabOrder(macLine, featureFullScreenBox);
        QWidget::setTabOrder(featureFullScreenBox, featureSpeedBox);
        QWidget::setTabOrder(featureSpeedBox, featureColorBox);
        QWidget::setTabOrder(featureColorBox, featureHistogramBox);
        QWidget::setTabOrder(featureHistogramBox, durationCombo);

        retranslateUi(LicenseGenerationClass);

        QMetaObject::connectSlotsByName(LicenseGenerationClass);
    } // setupUi

    void retranslateUi(QMainWindow *LicenseGenerationClass)
    {
        LicenseGenerationClass->setWindowTitle(QApplication::translate("LicenseGenerationClass", "LicenseGeneration", Q_NULLPTR));
        lblEmailWarning->setText(QApplication::translate("LicenseGenerationClass", "Die eingegebene Email-Adresse ist nicht korrekt!", Q_NULLPTR));
        lblLastNameWarning->setText(QApplication::translate("LicenseGenerationClass", "Bitte geben Sie einen Nachnamen an!", Q_NULLPTR));
        lblFirstNameWarning->setText(QApplication::translate("LicenseGenerationClass", "Bitte geben Sie einen Vornamen an!", Q_NULLPTR));
        lblExpirationDate->setText(QApplication::translate("LicenseGenerationClass", "Resultierendes Ablaufdatum: ", Q_NULLPTR));
        lblMacWarning->setText(QApplication::translate("LicenseGenerationClass", "Bitte geben Sie eine vollst\303\244ndige MAC-Adresse an!", Q_NULLPTR));
        lblCompanyWarning->setText(QApplication::translate("LicenseGenerationClass", "Bitte geben Sie eine Firma an! Wenn Sie die Lizenz privat nutzen wollen, geben Sie 'privat' an!", Q_NULLPTR));
        featureFullScreenBox->setText(QApplication::translate("LicenseGenerationClass", "Vollbildmodus", Q_NULLPTR));
        featureSpeedBox->setText(QApplication::translate("LicenseGenerationClass", "Abspielgeschwindigkeit", Q_NULLPTR));
        featureColorBox->setText(QApplication::translate("LicenseGenerationClass", "Videofarben", Q_NULLPTR));
        featureHistogramBox->setText(QApplication::translate("LicenseGenerationClass", "Histogramme", Q_NULLPTR));
        lblFeatureWarning->setText(QApplication::translate("LicenseGenerationClass", "Bitte waehlen Sie minderstens ein Feature aus!", Q_NULLPTR));
        lblLastName->setText(QApplication::translate("LicenseGenerationClass", "Nachname:", Q_NULLPTR));
        lblEnterCustNumb->setText(QApplication::translate("LicenseGenerationClass", "Placeholder", Q_NULLPTR));
        lblCustomerNumber->setText(QApplication::translate("LicenseGenerationClass", "Kundennummer:", Q_NULLPTR));
        lblMac->setText(QApplication::translate("LicenseGenerationClass", "MAC-Adresse:", Q_NULLPTR));
        lblEmail->setText(QApplication::translate("LicenseGenerationClass", "Email-Adresse:", Q_NULLPTR));
        lblFirstName->setText(QApplication::translate("LicenseGenerationClass", "Vorname:", Q_NULLPTR));
        lblCompany->setText(QApplication::translate("LicenseGenerationClass", "Firma:", Q_NULLPTR));
        lblFeatures->setText(QApplication::translate("LicenseGenerationClass", "Features:", Q_NULLPTR));
        lblDuration->setText(QApplication::translate("LicenseGenerationClass", "Lizenzdauer:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LicenseGenerationClass: public Ui_LicenseGenerationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEGENERATION_H
