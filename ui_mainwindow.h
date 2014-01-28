/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 24 07:09:25 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *cezarButton;
    QPushButton *vigenereButton;
    QPushButton *desButton;
    QPushButton *steganoButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 191, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cezarButton = new QPushButton(layoutWidget);
        cezarButton->setObjectName(QString::fromUtf8("cezarButton"));

        verticalLayout->addWidget(cezarButton);

        vigenereButton = new QPushButton(layoutWidget);
        vigenereButton->setObjectName(QString::fromUtf8("vigenereButton"));

        verticalLayout->addWidget(vigenereButton);

        desButton = new QPushButton(layoutWidget);
        desButton->setObjectName(QString::fromUtf8("desButton"));

        verticalLayout->addWidget(desButton);

        steganoButton = new QPushButton(layoutWidget);
        steganoButton->setObjectName(QString::fromUtf8("steganoButton"));

        verticalLayout->addWidget(steganoButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \321\210\320\270\321\204\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        cezarButton->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200 \320\246\320\265\320\267\320\260\321\200\321\217", 0, QApplication::UnicodeUTF8));
        vigenereButton->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200 \320\222\320\270\320\266\320\265\320\275\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
        desButton->setText(QApplication::translate("MainWindow", "DES", 0, QApplication::UnicodeUTF8));
        steganoButton->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \321\210\320\270\321\204\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
