/********************************************************************************
** Form generated from reading UI file 'stegano.ui'
**
** Created: Fri Jan 24 08:46:37 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEGANO_H
#define UI_STEGANO_H

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

class Ui_stegano
{
public:
    QLabel *steganolabel2;
    QLineEdit *steganoLineT2;
    QLineEdit *steganoLineT1;
    QLabel *steganolabel1;
    QLineEdit *steganoLineText;
    QPushButton *steganoButton2;
    QLabel *steganolabel3;
    QTextEdit *steganotext;
    QPushButton *steganoButton1;
    QPushButton *helpButton;

    void setupUi(QDialog *stegano)
    {
        if (stegano->objectName().isEmpty())
            stegano->setObjectName(QString::fromUtf8("stegano"));
        stegano->resize(400, 300);
        steganolabel2 = new QLabel(stegano);
        steganolabel2->setObjectName(QString::fromUtf8("steganolabel2"));
        steganolabel2->setGeometry(QRect(20, 130, 121, 17));
        steganoLineT2 = new QLineEdit(stegano);
        steganoLineT2->setObjectName(QString::fromUtf8("steganoLineT2"));
        steganoLineT2->setGeometry(QRect(20, 200, 191, 27));
        steganoLineT1 = new QLineEdit(stegano);
        steganoLineT1->setObjectName(QString::fromUtf8("steganoLineT1"));
        steganoLineT1->setGeometry(QRect(20, 100, 191, 27));
        steganolabel1 = new QLabel(stegano);
        steganolabel1->setObjectName(QString::fromUtf8("steganolabel1"));
        steganolabel1->setGeometry(QRect(20, 80, 121, 17));
        steganoLineText = new QLineEdit(stegano);
        steganoLineText->setObjectName(QString::fromUtf8("steganoLineText"));
        steganoLineText->setGeometry(QRect(20, 150, 191, 27));
        steganoButton2 = new QPushButton(stegano);
        steganoButton2->setObjectName(QString::fromUtf8("steganoButton2"));
        steganoButton2->setGeometry(QRect(247, 170, 111, 31));
        steganolabel3 = new QLabel(stegano);
        steganolabel3->setObjectName(QString::fromUtf8("steganolabel3"));
        steganolabel3->setGeometry(QRect(20, 180, 121, 17));
        steganotext = new QTextEdit(stegano);
        steganotext->setObjectName(QString::fromUtf8("steganotext"));
        steganotext->setGeometry(QRect(50, 30, 301, 31));
        steganotext->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        steganoButton1 = new QPushButton(stegano);
        steganoButton1->setObjectName(QString::fromUtf8("steganoButton1"));
        steganoButton1->setGeometry(QRect(247, 120, 111, 31));
        helpButton = new QPushButton(stegano);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(360, 30, 21, 27));
        steganoLineText->raise();
        steganolabel2->raise();
        steganoLineT2->raise();
        steganoLineT1->raise();
        steganolabel1->raise();
        steganoButton2->raise();
        steganolabel3->raise();
        steganotext->raise();
        steganoButton1->raise();
        helpButton->raise();
        QWidget::setTabOrder(steganoLineT1, steganoLineText);
        QWidget::setTabOrder(steganoLineText, steganoLineT2);
        QWidget::setTabOrder(steganoLineT2, steganoButton1);
        QWidget::setTabOrder(steganoButton1, steganoButton2);
        QWidget::setTabOrder(steganoButton2, steganotext);

        retranslateUi(stegano);

        QMetaObject::connectSlotsByName(stegano);
    } // setupUi

    void retranslateUi(QDialog *stegano)
    {
        stegano->setWindowTitle(QApplication::translate("stegano", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", 0, QApplication::UnicodeUTF8));
        steganolabel2->setText(QApplication::translate("stegano", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        steganolabel1->setText(QApplication::translate("stegano", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        steganoButton2->setText(QApplication::translate("stegano", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        steganolabel3->setText(QApplication::translate("stegano", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        steganotext->setHtml(QApplication::translate("stegano", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\237\321\200\320\276\320\277\320\270\321\210\320\270\321\202\320\265 \320\277\320\276\320\273\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        steganoButton1->setText(QApplication::translate("stegano", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("stegano", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class stegano: public Ui_stegano {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEGANO_H
