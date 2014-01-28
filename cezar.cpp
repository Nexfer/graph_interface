#include "cezar.h"
#include "ui_cezar.h"
#include <stdio.h>
#include <math.h>
#include <QtGui>

cezar::cezar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cezar)
{
    ui->setupUi(this);
    QObject::connect(ui->cezarButton1, SIGNAL(clicked()), this, SLOT(Encrypt()));
    QObject::connect(ui->cezarButton2, SIGNAL(clicked()), this, SLOT(Decrypt()));
    QObject::connect(ui->helpButton, SIGNAL(clicked()), this, SLOT(HelpMsg()));
}

cezar::~cezar()
{
    delete ui;
}

int cezar::fsize(FILE *f)
{
    int n;
    fseek(f,0,SEEK_END);
    n = ftell(f);
    fseek(f,0,SEEK_SET);
    return n;
}

int cezar::Encrypt()
{
    char *ARG1,*ARG2,*ARG3;

    ARG3 = (ui->cezarLineKey->text()).toAscii().data();

    FILE *f1,*f2;
    int i,n,j,k;
    char tmp;
    j = strlen(ARG3);
    for(i=0;i<j;i++)
    {
        k=ARG3[i]-'0';
        if(k < 0 || k > 9)
        {
            QMessageBox::information(this,"Error","The key should be a number");
            return 1;
        }
    }

    k=0;
    for(i=0;i<j;i++)
    {
        k += (ARG3[i]-'0') * pow(10,j-i-1);
    }

    ARG1 = (ui->cezarLineT1->text()).toAscii().data();
    if((f1 = fopen(ARG1,"r")) == NULL)
    {
        QMessageBox::information(this,"Error","Couldn't open file");
        return 1;
    }

    n = fsize(f1);

    ARG2 = (ui->cezarLineT2->text()).toAscii().data();
    f2 = fopen(ARG2,"w");
    for(i=0;i<n;i++)
    {
        fscanf(f1,"%c",&tmp);
        j = tmp;
        if((j >= 65 && j <= 90) || (j >= 97 && j <= 122))
        {
            if(j >= 65 && j <= 90)
                j -= 65;
            else if(j >= 97 && j <= 122)
                j -= 71;
            j += k;
            while(j > 51)
                j -= 52;
            if(j >= 0 && j <= 25)
                j += 65;
            else if(j >= 26 && j <= 51)
                j += 71;
        }
        tmp = j;
        fprintf(f2,"%c",tmp);
    }
    fclose(f2);
    fclose(f1);
    QMessageBox::information(this,"Message","Encrypted");
    return 0;
}

int cezar::Decrypt()
{
    char *ARG1,*ARG2,*ARG3;

    ARG3 = (ui->cezarLineKey->text()).toAscii().data();

    FILE *f1,*f2;
    int i,n,j;
    char tmp;
    int k;
    j = strlen(ARG3);
    for(i=0;i<j;i++)
    {
        k=ARG3[i]-'0';
        if(k < 0 || k > 9)
        {
            QMessageBox::information(this,"Error","The key should be a number");
            return 1;
        }
    }

    k=0;
    for(i=0;i<j;i++)
    {
        k += (ARG3[i]-'0') * pow(10,j-i-1);
    }

    ARG1 = (ui->cezarLineT1->text()).toAscii().data();
    if((f1 = fopen(ARG1,"r")) == NULL)
    {
        QMessageBox::information(this,"Error","Couldn't open file");
        return 1;
    }

    n = fsize(f1);

    ARG2 = (ui->cezarLineT2->text()).toAscii().data();
    f2 = fopen(ARG2,"w");
    for(i=0;i<n;i++)
    {
        fscanf(f1,"%c",&tmp);
        j = tmp;
        if((j >= 65 && j <= 90) || (j >= 97 && j <= 122))
        {
            if(j >= 65 && j <= 90)
                j -= 65;
            else if(j >= 97 && j <= 122)
                j -= 71;
            j -= k;
            while(j < 0)
                j += 52;
            if(j >= 0 && j <= 25)
                j += 65;
            else if(j >= 26 && j <= 51)
                j += 71;
        }
        tmp = j;
        fprintf(f2,"%c",tmp);
    }
    fclose(f2);
    fclose(f1);
    QMessageBox::information(this,"Message","Decrypted");
    return 0;
}

void cezar::HelpMsg()
{
    QString str = "A number should be input in a field 'key'\n";
    QMessageBox::information(this,"Help",str);
}
