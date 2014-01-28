#ifndef VIGENERE_H
#define VIGENERE_H

#include <QDialog>

namespace Ui {
class vigenere;
}

class vigenere : public QDialog
{
    Q_OBJECT
    
public:
    explicit vigenere(QWidget *parent = 0);
    ~vigenere();
    
private:
    Ui::vigenere *ui;
    int fsize(FILE *f);
    int innum(char a);
    int inchar(char a);

private slots:
    int Encrypt();
    int Decrypt();
};

#endif // VIGENERE_H
