/********************************************************************************
** Form generated from reading UI file 'DlgFileName.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGFILENAME_H
#define UI_DLGFILENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgFileName
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblToDo;
    QLineEdit *fileNameLine;
    QLabel *lblWarning;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *DlgFileName)
    {
        if (DlgFileName->objectName().isEmpty())
            DlgFileName->setObjectName(QStringLiteral("DlgFileName"));
        DlgFileName->resize(382, 123);
        verticalLayout = new QVBoxLayout(DlgFileName);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblToDo = new QLabel(DlgFileName);
        lblToDo->setObjectName(QStringLiteral("lblToDo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblToDo->sizePolicy().hasHeightForWidth());
        lblToDo->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lblToDo);

        fileNameLine = new QLineEdit(DlgFileName);
        fileNameLine->setObjectName(QStringLiteral("fileNameLine"));
        fileNameLine->setMaxLength(50);

        verticalLayout->addWidget(fileNameLine);

        lblWarning = new QLabel(DlgFileName);
        lblWarning->setObjectName(QStringLiteral("lblWarning"));
        sizePolicy.setHeightForWidth(lblWarning->sizePolicy().hasHeightForWidth());
        lblWarning->setSizePolicy(sizePolicy);
        lblWarning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(lblWarning);

        buttonBox = new QDialogButtonBox(DlgFileName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgFileName);

        QMetaObject::connectSlotsByName(DlgFileName);
    } // setupUi

    void retranslateUi(QWidget *DlgFileName)
    {
        DlgFileName->setWindowTitle(QApplication::translate("DlgFileName", "DlgFileName", Q_NULLPTR));
        lblToDo->setText(QApplication::translate("DlgFileName", "Bitte geben Sie einen Namen f\303\274r die zu generierende Lizenzdatei an:", Q_NULLPTR));
        lblWarning->setText(QApplication::translate("DlgFileName", "Der Dateiname darf nicht leer sein und keines der folgenden Zeichen \n"
"enthalten: \\  / : * ? \" < > |", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DlgFileName: public Ui_DlgFileName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGFILENAME_H
