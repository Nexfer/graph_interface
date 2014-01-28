/********************************************************************************
** Form generated from reading UI file 'vigenere.ui'
**
** Created: Fri Jan 24 07:58:28 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIGENERE_H
#define UI_VIGENERE_H

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

class Ui_vigenere
{
public:
    QLabel *vigenerelabel1;
    QPushButton *vigenereButton1;
    QLineEdit *vigenereLineT1;
    QLineEdit *vigenereLineKey;
    QLineEdit *vigenereLineT2;
    QPushButton *vigenereButton2;
    QLabel *vigenerelabel2;
    QTextEdit *vigeneretext;
    QLabel *vigenerelabel3;

    void setupUi(QDialog *vigenere)
    {
        if (vigenere->objectName().isEmpty())
            vigenere->setObjectName(QString::fromUtf8("vigenere"));
        vigenere->resize(400, 300);
        vigenerelabel1 = new QLabel(vigenere);
        vigenerelabel1->setObjectName(QString::fromUtf8("vigenerelabel1"));
        vigenerelabel1->setGeometry(QRect(20, 80, 121, 17));
        vigenereButton1 = new QPushButton(vigenere);
        vigenereButton1->setObjectName(QString::fromUtf8("vigenereButton1"));
        vigenereButton1->setGeometry(QRect(247, 120, 111, 31));
        vigenereLineT1 = new QLineEdit(vigenere);
        vigenereLineT1->setObjectName(QString::fromUtf8("vigenereLineT1"));
        vigenereLineT1->setGeometry(QRect(20, 100, 191, 27));
        vigenereLineKey = new QLineEdit(vigenere);
        vigenereLineKey->setObjectName(QString::fromUtf8("vigenereLineKey"));
        vigenereLineKey->setGeometry(QRect(20, 150, 191, 27));
        vigenereLineT2 = new QLineEdit(vigenere);
        vigenereLineT2->setObjectName(QString::fromUtf8("vigenereLineT2"));
        vigenereLineT2->setGeometry(QRect(20, 200, 191, 27));
        vigenereButton2 = new QPushButton(vigenere);
        vigenereButton2->setObjectName(QString::fromUtf8("vigenereButton2"));
        vigenereButton2->setGeometry(QRect(247, 170, 111, 31));
        vigenerelabel2 = new QLabel(vigenere);
        vigenerelabel2->setObjectName(QString::fromUtf8("vigenerelabel2"));
        vigenerelabel2->setGeometry(QRect(20, 130, 66, 17));
        vigeneretext = new QTextEdit(vigenere);
        vigeneretext->setObjectName(QString::fromUtf8("vigeneretext"));
        vigeneretext->setGeometry(QRect(50, 30, 301, 31));
        vigeneretext->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        vigenerelabel3 = new QLabel(vigenere);
        vigenerelabel3->setObjectName(QString::fromUtf8("vigenerelabel3"));
        vigenerelabel3->setGeometry(QRect(20, 180, 121, 17));

        retranslateUi(vigenere);

        QMetaObject::connectSlotsByName(vigenere);
    } // setupUi

    void retranslateUi(QDialog *vigenere)
    {
        vigenere->setWindowTitle(QApplication::translate("vigenere", "\320\250\320\270\321\204\321\200 \320\222\320\270\320\266\320\265\320\275\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
        vigenerelabel1->setText(QApplication::translate("vigenere", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        vigenereButton1->setText(QApplication::translate("vigenere", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        vigenereButton2->setText(QApplication::translate("vigenere", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        vigenerelabel2->setText(QApplication::translate("vigenere", "\320\232\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        vigeneretext->setHtml(QApplication::translate("vigenere", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\237\321\200\320\276\320\277\320\270\321\210\320\270\321\202\320\265 \320\277\320\276\320\273\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        vigenerelabel3->setText(QApplication::translate("vigenere", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vigenere: public Ui_vigenere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIGENERE_H
