#ifndef STEGANO_H
#define STEGANO_H

#include <QDialog>

namespace Ui {
class stegano;
}

class stegano : public QDialog
{
    Q_OBJECT
    
public:
    explicit stegano(QWidget *parent = 0);
    ~stegano();
    
private:
    Ui::stegano *ui;
    int fsize(FILE *f);

private slots:
    int Encrypt();
    int Decrypt();
    void HelpMsg();
};

#endif // STEGANO_H
