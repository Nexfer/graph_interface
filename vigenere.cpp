#include "vigenere.h"
#include "ui_vigenere.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <QtGui>

vigenere::vigenere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vigenere)
{
    ui->setupUi(this);
    QObject::connect(ui->vigenereButton1, SIGNAL(clicked()), this, SLOT(Encrypt()));
    QObject::connect(ui->vigenereButton2, SIGNAL(clicked()), this, SLOT(Decrypt()));
}

vigenere::~vigenere()
{
    delete ui;
}

int vigenere::fsize(FILE *f)
{
    int size;
    fseek(f,0,SEEK_END);
    size = ftell(f)-1;
    fseek(f,0,SEEK_SET);
    return size;
}
int vigenere::innum(char a)
{
    if(a >= 65 && a <= 90)
        a -= 65;
    else if(a >= 97 && a <= 122)
        a -= 71;
    return a;
}
int vigenere::inchar(char a)
{
    if(a >= 0 && a <= 25)
        a += 65;
    else if(a >= 26 && a <= 51)
        a += 71;
    return a;
}
int vigenere::Encrypt()
{
    char *ARG1,*ARG2,*ARG3;
        FILE *f1,*f2,*f3;
        int n,m,i,j;
        char *temp;
        char *smb;

        ARG1 = (ui->vigenereLineT1->text()).toAscii().data();
        if((f1 = fopen(ARG1,"r")) == NULL)
        {
            QMessageBox::information(this,"Error","Couldn't open file");
            return 1;
        }
        n = fsize(f1);

        ARG3 = (ui->vigenereLineKey->text()).toAscii().data();
        if((f3 = fopen(ARG3,"r")) == NULL)
        {
            QMessageBox::information(this,"Error","Couldn't open file");
            return 1;
        }
        m = fsize(f3);

        if(m > n)
        {
            fclose(f1);
            fclose(f3);
            QMessageBox::information(this,"Error","The length of key wouldn't be longer than a source text");
            return 1;
        }
        temp = (char*)malloc(n*sizeof(char));
        for(i=0;i<m;i++)
            fscanf(f3,"%c",&temp[i]);
        for(i=m,j=0;i<n;i++,j++)
            temp[i] = temp[j];
        smb = (char*)malloc(n*sizeof(char));
        for(i=0;i<n;i++)
            fscanf(f1,"%c",&smb[i]);
        for(i=0;i<n;i++)
        {
            if(smb[i] >= 65 && smb[i] <= 90 || smb[i] >= 97 && smb[i] <= 122)
            {
                smb[i] = innum(smb[i]);
                if(temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122)
                {
                    temp[i] = innum(temp[i]);
                    smb[i] = smb[i] + temp[i];
                    if(smb[i] > 51)
                        smb[i] -= 52;
                }
                smb[i] = inchar(smb[i]);
            }
        }

        ARG2 = (ui->vigenereLineT2->text()).toAscii().data();
        f2 = fopen(ARG2,"w");

        smb[n] = '\n';
        for(i=0;i<=n;i++)
            fprintf(f2,"%c",smb[i]);
        free(temp);
        free(smb);
        fclose(f3);
        fclose(f2);
        fclose(f1);

        return 0;
}

int vigenere::Decrypt()
{
    char *ARG1,*ARG2,*ARG3;
        FILE *f1,*f2,*f3;
        int n,m,i,j;
        char *temp;
        char *smb;

        ARG1 = (ui->vigenereLineT1->text()).toAscii().data();
        f1 = fopen(ARG1,"r");
        n = fsize(f1);

        ARG3 = (ui->vigenereLineKey->text()).toAscii().data();
        f3 = fopen(ARG3,"r");
        m = fsize(f3);

        if(m > n)
        {
            fclose(f1);
            fclose(f3);
            QMessageBox::information(this,"Error","The length of key wouldn't be longer than a source text");
            return 1;
        }
        temp = (char*)malloc(n*sizeof(char));
        for(i=0;i<m;i++)
            fscanf(f3,"%c",&temp[i]);
        for(i=m,j=0;i<n;i++,j++)
            temp[i] = temp[j];
        smb = (char*)malloc(n*sizeof(char));
        for(i=0;i<n;i++)
            fscanf(f1,"%c",&smb[i]);
        for(i=0;i<n;i++)
        {
            if(smb[i] >= 65 && smb[i] <= 90 || smb[i] >= 97 && smb[i] <= 122)
            {
                smb[i] = innum(smb[i]);
                if(temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122)
                {
                    temp[i] = innum(temp[i]);
                    smb[i] = smb[i] - temp[i];
                    if(smb[i] < 0)
                        smb[i] += 52;
                }
                smb[i] = inchar(smb[i]);
            }
        }

        ARG2 = (ui->vigenereLineT2->text()).toAscii().data();
        f2 = fopen(ARG2,"w");

        smb[n] = '\n';
        for(i=0;i<=n;i++)
            fprintf(f2,"%c",smb[i]);
        free(temp);
        free(smb);
        fclose(f3);
        fclose(f2);
        fclose(f1);
        return 0;
}
