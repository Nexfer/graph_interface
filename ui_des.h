/********************************************************************************
** Form generated from reading UI file 'des.ui'
**
** Created: Tue Jan 28 14:09:30 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DES_H
#define UI_DES_H

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

class Ui_des
{
public:
    QLabel *deslabel2;
    QLineEdit *desLineT2;
    QLineEdit *desLineT1;
    QLabel *deslabel1;
    QLineEdit *desLineKey;
    QPushButton *desButton2;
    QLabel *deslabel3;
    QTextEdit *destext;
    QPushButton *desButton1;

    void setupUi(QDialog *des)
    {
        if (des->objectName().isEmpty())
            des->setObjectName(QString::fromUtf8("des"));
        des->resize(400, 300);
        deslabel2 = new QLabel(des);
        deslabel2->setObjectName(QString::fromUtf8("deslabel2"));
        deslabel2->setGeometry(QRect(20, 130, 66, 17));
        desLineT2 = new QLineEdit(des);
        desLineT2->setObjectName(QString::fromUtf8("desLineT2"));
        desLineT2->setGeometry(QRect(20, 200, 191, 27));
        desLineT1 = new QLineEdit(des);
        desLineT1->setObjectName(QString::fromUtf8("desLineT1"));
        desLineT1->setGeometry(QRect(20, 100, 191, 27));
        deslabel1 = new QLabel(des);
        deslabel1->setObjectName(QString::fromUtf8("deslabel1"));
        deslabel1->setGeometry(QRect(20, 80, 121, 17));
        desLineKey = new QLineEdit(des);
        desLineKey->setObjectName(QString::fromUtf8("desLineKey"));
        desLineKey->setGeometry(QRect(20, 150, 191, 27));
        desButton2 = new QPushButton(des);
        desButton2->setObjectName(QString::fromUtf8("desButton2"));
        desButton2->setGeometry(QRect(247, 170, 111, 31));
        deslabel3 = new QLabel(des);
        deslabel3->setObjectName(QString::fromUtf8("deslabel3"));
        deslabel3->setGeometry(QRect(20, 180, 121, 17));
        destext = new QTextEdit(des);
        destext->setObjectName(QString::fromUtf8("destext"));
        destext->setGeometry(QRect(50, 30, 301, 31));
        destext->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        desButton1 = new QPushButton(des);
        desButton1->setObjectName(QString::fromUtf8("desButton1"));
        desButton1->setGeometry(QRect(247, 120, 111, 31));
        QWidget::setTabOrder(desLineT1, desLineKey);
        QWidget::setTabOrder(desLineKey, desLineT2);
        QWidget::setTabOrder(desLineT2, desButton1);
        QWidget::setTabOrder(desButton1, desButton2);
        QWidget::setTabOrder(desButton2, destext);

        retranslateUi(des);

        QMetaObject::connectSlotsByName(des);
    } // setupUi

    void retranslateUi(QDialog *des)
    {
        des->setWindowTitle(QApplication::translate("des", "DES", 0, QApplication::UnicodeUTF8));
        deslabel2->setText(QApplication::translate("des", "\320\232\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        deslabel1->setText(QApplication::translate("des", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        desButton2->setText(QApplication::translate("des", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        deslabel3->setText(QApplication::translate("des", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        destext->setHtml(QApplication::translate("des", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\237\321\200\320\276\320\277\320\270\321\210\320\270\321\202\320\265 \320\277\320\276\320\273\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        desButton1->setText(QApplication::translate("des", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class des: public Ui_des {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DES_H
