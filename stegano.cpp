#include "stegano.h"
#include "ui_stegano.h"
#include <stdio.h>
#include <QtGui>

stegano::stegano(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stegano)
{
    ui->setupUi(this);
    QObject::connect(ui->steganoButton1, SIGNAL(clicked()), this, SLOT(Encrypt()));
    QObject::connect(ui->steganoButton2, SIGNAL(clicked()), this, SLOT(Decrypt()));
    QObject::connect(ui->helpButton, SIGNAL(clicked()), this, SLOT(HelpMsg()));
}

stegano::~stegano()
{
    delete ui;
}

int stegano::fsize(FILE *f)
{
    int n;
    fseek(f,0,SEEK_END);
    n = ftell(f);
    fseek(f,0,SEEK_SET);
    return n;
}

int stegano::Encrypt()
{
    char *ARG1,*ARG2,*ARG3;
        FILE *fmsg,*fpic,*fenc;
        int i,j,k,size,offset;
        unsigned char pic_tmp,msg_tmp;

        ARG3 = (ui->steganoLineText->text()).toAscii().data();
        if((fmsg = fopen(ARG3,"r")) == NULL)
        {
            QMessageBox::information(this,"Error","Couldn't open file");
            return 1;
        }
        size = fsize(fmsg);

        ARG1 = (ui->steganoLineT1->text()).toAscii().data();
        if((fpic = fopen(ARG1,"r")) == NULL)
        {
            QMessageBox::information(this,"Error","Couldn't open file");
            return 1;
        }

        ARG2 = (ui->steganoLineT2->text()).toAscii().data();
        fenc = fopen(ARG2,"w");

        fseek(fpic,10,SEEK_SET);
        offset = fgetc(fpic);
        fseek(fpic,0,SEEK_SET);

        for(i=0;i<offset;i++)
        {
            pic_tmp=fgetc(fpic);
                fputc(pic_tmp,fenc);
        }
        //Вставляем в картинку размер сообщения
        for(j = 6,k = 192;j >= 0;j = j - 2,k = k / 4)
        {
            pic_tmp = fgetc(fpic);
            pic_tmp = pic_tmp & 252 | ((size & k) >> j);
            fputc(pic_tmp,fenc);
        }
        ///////////////////////////////////////
        for(i = 1;i <= size; i++)
        {
            msg_tmp = fgetc(fmsg);
            for(j = 6,k = 192;j >= 0;j = j - 2,k = k / 4)
            {
                pic_tmp = fgetc(fpic);
                pic_tmp = pic_tmp & 252 | ((msg_tmp & k) >> j);
                fputc(pic_tmp,fenc);
            }
        }
        while(!feof(fpic))
        {
            pic_tmp = fgetc(fpic);
            fputc(pic_tmp,fenc);
        }
        fclose(fenc);
        fclose(fpic);
        fclose(fmsg);
        QMessageBox::information(this,"Message","Encrypted");
        return 0;
}

int stegano::Decrypt()
{
    char *ARG1,*ARG2;
        FILE *fmsg,*fenc;
        int i,j,size,offset;
        unsigned char pic_tmp,msg_tmp,tmp;

        ARG1 = (ui->steganoLineT1->text()).toAscii().data();
        if((fenc = fopen(ARG1,"r")) == NULL)
        {
            QMessageBox::information(this,"Error","Couldn't open file");
            return 1;
        }

        ARG2 = (ui->steganoLineT2->text()).toAscii().data();
        fmsg = fopen(ARG2,"w");

        fseek(fenc,10,SEEK_SET);
        offset = fgetc(fenc);
        fseek(fenc,0,SEEK_SET);

        for(i=0;i<offset;i++)
        {
            pic_tmp=fgetc(fenc);
        }
        //Считывание размера сообщения
        size=0;
        for(j = 6;j >= 0;j = j - 2)
        {
            pic_tmp = fgetc(fenc);
            tmp = (pic_tmp & 3) << j;
            size |= tmp;
        }
        /////////////////////////////
        for(i = 1;i <= size;i++)
        {
            msg_tmp = 0;
            for(j = 6;j >= 0;j = j - 2)
            {
                pic_tmp = fgetc(fenc);
                tmp = (pic_tmp & 3) << j;
                msg_tmp |= tmp;
            }
            fputc(msg_tmp,fmsg);
        }
        fclose(fmsg);
        fclose(fenc);
        QMessageBox::information(this,"Message","Decrypted");
        return 0;
}

void stegano::HelpMsg()
{
    QString str = "A field 'Text file' doesn't need for decrypting";
    QMessageBox::information(this,"Help",str);
}
