#ifndef DES_H
#define DES_H

#include <QDialog>

namespace Ui {
class des;
}

class des : public QDialog
{
    Q_OBJECT
    
public:
    explicit des(QWidget *parent = 0);
    ~des();
    typedef struct {
            unsigned char k[8];
            unsigned char c[4];
            unsigned char d[4];
    } key_set;

private:
    Ui::des *ui;
    void generate_sub_keys(unsigned char* main_key, key_set* key_sets);
    void process_msg(unsigned char* message_piece, unsigned char* processed_piece, key_set* key_sets, int mode);
    int main(int mode);

private slots:
    void Encrypt();
    void Decrypt();
};

#endif // DES_H
