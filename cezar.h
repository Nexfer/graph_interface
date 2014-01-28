#ifndef CEZAR_H
#define CEZAR_H

#include <QDialog>

namespace Ui {
class cezar;
}

class cezar : public QDialog
{
    Q_OBJECT
    
public:
    explicit cezar(QWidget *parent = 0);
    ~cezar();
    
private:
    Ui::cezar *ui;
    int fsize(FILE *f);

private slots:
    int Encrypt();
    int Decrypt();
    void HelpMsg();
};

#endif // CEZAR_H
