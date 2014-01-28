/********************************************************************************
** Form generated from reading UI file 'cezar.ui'
**
** Created: Fri Jan 24 07:16:56 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CEZAR_H
#define UI_CEZAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_cezar
{
public:
    QTextEdit *cezartext;
    QLineEdit *cezarLineT1;
    QLineEdit *cezarLineKey;
    QLineEdit *cezarLineT2;
    QLabel *cezarlabel1;
    QLabel *cezarlabel2;
    QLabel *cezarlabel3;
    QPushButton *cezarButton1;
    QPushButton *cezarButton2;
    QPushButton *helpButton;

    void setupUi(QDialog *cezar)
    {
        if (cezar->objectName().isEmpty())
            cezar->setObjectName(QString::fromUtf8("cezar"));
        cezar->resize(400, 300);
        cezartext = new QTextEdit(cezar);
        cezartext->setObjectName(QString::fromUtf8("cezartext"));
        cezartext->setGeometry(QRect(50, 30, 301, 31));
        cezartext->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        cezarLineT1 = new QLineEdit(cezar);
        cezarLineT1->setObjectName(QString::fromUtf8("cezarLineT1"));
        cezarLineT1->setGeometry(QRect(20, 100, 191, 27));
        cezarLineKey = new QLineEdit(cezar);
        cezarLineKey->setObjectName(QString::fromUtf8("cezarLineKey"));
        cezarLineKey->setGeometry(QRect(20, 150, 191, 27));
        cezarLineT2 = new QLineEdit(cezar);
        cezarLineT2->setObjectName(QString::fromUtf8("cezarLineT2"));
        cezarLineT2->setGeometry(QRect(20, 200, 191, 27));
        cezarlabel1 = new QLabel(cezar);
        cezarlabel1->setObjectName(QString::fromUtf8("cezarlabel1"));
        cezarlabel1->setGeometry(QRect(20, 80, 121, 17));
        cezarlabel2 = new QLabel(cezar);
        cezarlabel2->setObjectName(QString::fromUtf8("cezarlabel2"));
        cezarlabel2->setGeometry(QRect(20, 130, 66, 17));
        cezarlabel3 = new QLabel(cezar);
        cezarlabel3->setObjectName(QString::fromUtf8("cezarlabel3"));
        cezarlabel3->setGeometry(QRect(20, 180, 121, 17));
        cezarButton1 = new QPushButton(cezar);
        cezarButton1->setObjectName(QString::fromUtf8("cezarButton1"));
        cezarButton1->setGeometry(QRect(247, 120, 111, 31));
        cezarButton2 = new QPushButton(cezar);
        cezarButton2->setObjectName(QString::fromUtf8("cezarButton2"));
        cezarButton2->setGeometry(QRect(247, 170, 111, 31));
        helpButton = new QPushButton(cezar);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(360, 30, 21, 27));

        retranslateUi(cezar);

        QMetaObject::connectSlotsByName(cezar);
    } // setupUi

    void retranslateUi(QDialog *cezar)
    {
        cezar->setWindowTitle(QApplication::translate("cezar", "\320\250\320\270\321\204\321\200 \320\246\320\265\320\267\320\260\321\200\321\217", 0, QApplication::UnicodeUTF8));
        cezartext->setHtml(QApplication::translate("cezar", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\237\321\200\320\276\320\277\320\270\321\210\320\270\321\202\320\265 \320\277\320\276\320\273\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cezarlabel1->setText(QApplication::translate("cezar", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        cezarlabel2->setText(QApplication::translate("cezar", "\320\232\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        cezarlabel3->setText(QApplication::translate("cezar", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        cezarButton1->setText(QApplication::translate("cezar", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        cezarButton2->setText(QApplication::translate("cezar", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("cezar", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cezar: public Ui_cezar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CEZAR_H
