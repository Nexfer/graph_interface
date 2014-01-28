#include "des.h"
#include "ui_des.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>

des::des(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::des)
{
    ui->setupUi(this);
    QObject::connect(ui->desButton1, SIGNAL(clicked()), this, SLOT(Encrypt()));
    QObject::connect(ui->desButton2, SIGNAL(clicked()), this, SLOT(Decrypt()));
}

des::~des()
{
    delete ui;
}

void des::generate_sub_keys(unsigned char* main_key, key_set* key_sets)
{
    int first_key_perestan[] = {57, 49,  41, 33,  25,  17,  9,
                                 1, 58,  50, 42,  34,  26, 18,
                                10,  2,  59, 51,  43,  35, 27,
                                19, 11,   3, 60,  52,  44, 36,
                                63, 55,  47, 39,  31,  23, 15,
                                 7, 62,  54, 46,  38,  30, 22,
                                14,  6,  61, 53,  45,  37, 29,
                                21, 13,   5, 28,  20,  12,  4};

    int key_shift_sizes[] = {-1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    int sub_key_perestan[] = {14, 17, 11, 24,  1,  5,
                               3, 28, 15,  6, 21, 10,
                              23, 19, 12,  4, 26,  8,
                              16,  7, 27, 20, 13,  2,
                              41, 52, 31, 37, 47, 55,
                              30, 40, 51, 45, 33, 48,
                              44, 49, 39, 56, 34, 53,
                              46, 42, 50, 36, 29, 32};

    int i, j;
    int shift_size;
    unsigned char shift_byte, first_shift_bits, second_shift_bits, third_shift_bits, fourth_shift_bits;

    for (i=0; i<8; i++)
        key_sets[0].k[i] = 0;

    for (i=0; i<56; i++)
    {
        shift_size = first_key_perestan[i];
        shift_byte = 0x80 >> ((shift_size - 1)%8);
        shift_byte &= main_key[(shift_size - 1)/8];
        shift_byte <<= ((shift_size - 1)%8);

        key_sets[0].k[i/8] |= (shift_byte >> i%8);
    }

    for (i=0; i<3; i++)
        key_sets[0].c[i] = key_sets[0].k[i];

    key_sets[0].c[3] = key_sets[0].k[3] & 0xF0;

    for (i=0; i<3; i++)
    {
        key_sets[0].d[i] = (key_sets[0].k[i+3] & 0x0F) << 4;
        key_sets[0].d[i] |= (key_sets[0].k[i+4] & 0xF0) >> 4;
    }

    key_sets[0].d[3] = (key_sets[0].k[6] & 0x0F) << 4;

    for (i=1; i<17; i++)
    {
        for (j=0; j<4; j++)
        {
            key_sets[i].c[j] = key_sets[i-1].c[j];
            key_sets[i].d[j] = key_sets[i-1].d[j];
        }

        shift_size = key_shift_sizes[i];
        if (shift_size == 1)
            shift_byte = 0x80;
        else shift_byte = 0xC0;

        // Process C
        first_shift_bits = shift_byte & key_sets[i].c[0];
        second_shift_bits = shift_byte & key_sets[i].c[1];
        third_shift_bits = shift_byte & key_sets[i].c[2];
        fourth_shift_bits = shift_byte & key_sets[i].c[3];

        key_sets[i].c[0] <<= shift_size;
        key_sets[i].c[0] |= (second_shift_bits >> (8 - shift_size));

        key_sets[i].c[1] <<= shift_size;
        key_sets[i].c[1] |= (third_shift_bits >> (8 - shift_size));

        key_sets[i].c[2] <<= shift_size;
        key_sets[i].c[2] |= (fourth_shift_bits >> (8 - shift_size));

        key_sets[i].c[3] <<= shift_size;
        key_sets[i].c[3] |= (first_shift_bits >> (4 - shift_size));

        // Process D
        first_shift_bits = shift_byte & key_sets[i].d[0];
        second_shift_bits = shift_byte & key_sets[i].d[1];
        third_shift_bits = shift_byte & key_sets[i].d[2];
        fourth_shift_bits = shift_byte & key_sets[i].d[3];

        key_sets[i].d[0] <<= shift_size;
        key_sets[i].d[0] |= (second_shift_bits >> (8 - shift_size));

        key_sets[i].d[1] <<= shift_size;
        key_sets[i].d[1] |= (third_shift_bits >> (8 - shift_size));

        key_sets[i].d[2] <<= shift_size;
        key_sets[i].d[2] |= (fourth_shift_bits >> (8 - shift_size));

        key_sets[i].d[3] <<= shift_size;
        key_sets[i].d[3] |= (first_shift_bits >> (4 - shift_size));

        for (j=0; j<48; j++)
        {
            shift_size = sub_key_perestan[j];
            if (shift_size <= 28)
            {
                shift_byte = 0x80 >> ((shift_size - 1)%8);
                shift_byte &= key_sets[i].c[(shift_size - 1)/8];
                shift_byte <<= ((shift_size - 1)%8);
            }
            else
            {
                shift_byte = 0x80 >> ((shift_size - 29)%8);
                shift_byte &= key_sets[i].d[(shift_size - 29)/8];
                shift_byte <<= ((shift_size - 29)%8);
            }

            key_sets[i].k[j/8] |= (shift_byte >> j%8);
        }
    }
}

void des::process_msg(unsigned char* msg_piece, unsigned char* processed_piece, key_set* key_sets, int mode)
{
    int first_msg_perestan[] = {58, 50, 42, 34, 26, 18, 10, 2,
                                60, 52, 44, 36, 28, 20, 12, 4,
                                62, 54, 46, 38, 30, 22, 14, 6,
                                64, 56, 48, 40, 32, 24, 16, 8,
                                57, 49, 41, 33, 25, 17,  9, 1,
                                59, 51, 43, 35, 27, 19, 11, 3,
                                61, 53, 45, 37, 29, 21, 13, 5,
                                63, 55, 47, 39, 31, 23, 15, 7};

    int msg_exp[] =  {32,  1,  2,  3,  4,  5,
                       4,  5,  6,  7,  8,  9,
                       8,  9, 10, 11, 12, 13,
                      12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21,
                      20, 21, 22, 23, 24, 25,
                      24, 25, 26, 27, 28, 29,
                      28, 29, 30, 31, 32,  1};

    int S1[] = {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
                 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
                 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
                15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13};

    int S2[] = {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
                 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
                 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
                13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9};

    int S3[] = {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
                13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
                13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
                 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12};

    int S4[] = { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
                13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
                10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
                 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14};

    int S5[] = { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
                14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
                 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
                11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3};

    int S6[] = {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
                10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
                 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
                 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13};

    int S7[] = { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
                13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
                 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
                 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12};

    int S8[] = {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
                 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
                 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
                 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11};

    int right_sub_msg_perestan[] = {16,  7, 20, 21,
                                    29, 12, 28, 17,
                                     1, 15, 23, 26,
                                     5, 18, 31, 10,
                                     2,  8, 24, 14,
                                    32, 27,  3,  9,
                                    19, 13, 30,  6,
                                    22, 11,  4, 25};

    int last_msg_perestan[] =  {40,  8, 48, 16, 56, 24, 64, 32,
                                39,  7, 47, 15, 55, 23, 63, 31,
                                38,  6, 46, 14, 54, 22, 62, 30,
                                37,  5, 45, 13, 53, 21, 61, 29,
                                36,  4, 44, 12, 52, 20, 60, 28,
                                35,  3, 43, 11, 51, 19, 59, 27,
                                34,  2, 42, 10, 50, 18, 58, 26,
                                33,  1, 41,  9, 49, 17, 57, 25};

    int i, k;
    int shift_size;
    unsigned char shift_byte;

    unsigned char first_perestan[8];
    memset(first_perestan, 0, 8);
    memset(processed_piece, 0, 8);

    for (i=0; i<64; i++)
    {
        shift_size = first_msg_perestan[i];
        shift_byte = 0x80 >> ((shift_size - 1)%8);
        shift_byte &= msg_piece[(shift_size - 1)/8];
        shift_byte <<= ((shift_size - 1)%8);

        first_perestan[i/8] |= (shift_byte >> i%8);
    }

    unsigned char l[4], r[4];
    for (i=0; i<4; i++)
    {
        l[i] = first_perestan[i];
        r[i] = first_perestan[i+4];
    }

    unsigned char ln[4], rn[4], er[6], ser[4];

    int key_index;
    for (k=1; k<=16; k++)
    {
        memcpy(ln, r, 4);
        printf("ln=%s\n",ln);
        memset(er, 0, 6);
        printf("er=%s\n",er);

        for (i=0; i<48; i++)
        {
            shift_size = msg_exp[i];
            shift_byte = 0x80 >> ((shift_size - 1)%8);
            shift_byte &= r[(shift_size - 1)/8];
            shift_byte <<= ((shift_size - 1)%8);

            r[i/8] |= (shift_byte >> i%8);
        }

        if (mode == 0)
            key_index = 17 - k;
        else key_index = k;

        for (i=0; i<6; i++)
            er[i] ^= key_sets[key_index].k[i];

        unsigned char row, column;

        for (i=0; i<4; i++)
            ser[i] = 0;

        // Byte 1
        row = 0;
        row |= ((er[0] & 0x80) >> 6);
        row |= ((er[0] & 0x04) >> 2);

        column = 0;
        column |= ((er[0] & 0x78) >> 3);

        ser[0] |= ((unsigned char)S1[row*16+column] << 4);

        row = 0;
        row |= (er[0] & 0x02);
        row |= ((er[1] & 0x10) >> 4);

        column = 0;
        column |= ((er[0] & 0x01) << 3);
        column |= ((er[1] & 0xE0) >> 5);

        ser[0] |= (unsigned char)S2[row*16+column];

        // Byte 2
        row = 0;
        row |= ((er[1] & 0x08) >> 2);
        row |= ((er[2] & 0x40) >> 6);

        column = 0;
        column |= ((er[1] & 0x07) << 1);
        column |= ((er[2] & 0x80) >> 7);

        ser[1] |= ((unsigned char)S3[row*16+column] << 4);

        row = 0;
        row |= ((er[2] & 0x20) >> 4);
        row |= (er[2] & 0x01);

        column = 0;
        column |= ((er[2] & 0x1E) >> 1);

        ser[1] |= (unsigned char)S4[row*16+column];

        // Byte 3
        row = 0;
        row |= ((er[3] & 0x80) >> 6);
        row |= ((er[3] & 0x04) >> 2);

        column = 0;
        column |= ((er[3] & 0x78) >> 3);

        ser[2] |= ((unsigned char)S5[row*16+column] << 4);

        row = 0;
        row |= (er[3] & 0x02);
        row |= ((er[4] & 0x10) >> 4);

        column = 0;
        column |= ((er[3] & 0x01) << 3);
        column |= ((er[4] & 0xE0) >> 5);

        ser[2] |= (unsigned char)S6[row*16+column];

        // Byte 4
        row = 0;
        row |= ((er[4] & 0x08) >> 2);
        row |= ((er[5] & 0x40) >> 6);

        column = 0;
        column |= ((er[4] & 0x07) << 1);
        column |= ((er[5] & 0x80) >> 7);

        ser[3] |= ((unsigned char)S7[row*16+column] << 4);

        row = 0;
        row |= ((er[5] & 0x20) >> 4);
        row |= (er[5] & 0x01);

        column = 0;
        column |= ((er[5] & 0x1E) >> 1);

        ser[3] |= (unsigned char)S8[row*16+column];

        for (i=0; i<4; i++)
            rn[i] = 0;

        for (i=0; i<32; i++)
        {
            shift_size = right_sub_msg_perestan[i];
            shift_byte = 0x80 >> ((shift_size - 1)%8);
            shift_byte &= ser[(shift_size - 1)/8];
            shift_byte <<= ((shift_size - 1)%8);

            rn[i/8] |= (shift_byte >> i%8);
        }

        for (i=0; i<4; i++)
            rn[i] ^= l[i];

        for (i=0; i<4; i++)
        {
            l[i] = ln[i];
            r[i] = rn[i];
        }
    }

    unsigned char pre_end_perestan[8];
    for (i=0; i<4; i++)
    {
        pre_end_perestan[i] = r[i];
        pre_end_perestan[4+i] = l[i];
    }

    for (i=0; i<64; i++)
    {
        shift_size = last_msg_perestan[i];
        shift_byte = 0x80 >> ((shift_size - 1)%8);
        shift_byte &= pre_end_perestan[(shift_size - 1)/8];
        shift_byte <<= ((shift_size - 1)%8);

        processed_piece[i/8] |= (shift_byte >> i%8);
    }
}

int des::main(int mode)
{
    const char *ARG1,*ARG2,*ARG3;
    FILE *fkey, *fin, *fout;
    unsigned long file_size;
    unsigned short int padding;

    ARG3 = (ui->desLineKey->text()).toLatin1().data();
    fkey = fopen(ARG3, "r");
    if (!fkey)
    {
        QMessageBox::information(this,"Error","Couldn't open file");
        return 1;
    }

    short int bytes_read;
    unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
    bytes_read = fread(des_key, sizeof(unsigned char), 8, fkey);
    if (bytes_read != 8)
    {
        QMessageBox::information(this,"Error","Key read from key file doesn't have valid key size\n");
        fclose(fkey);
        return 1;
    }
    fclose(fkey);

    ARG1 = (ui->desLineT1->text()).toLatin1().data();
    fin = fopen(ARG1, "r");
    if(!fin)
    {
        QMessageBox::information(this,"Error","Couldn't open file");
        return 1;
    }

    ARG2 = (ui->desLineT2->text()).toLatin1().data();
    fout = fopen(ARG2, "w");

    short int bytes_written;
    unsigned long block_count = 0, number_of_blocks;
    unsigned char* data_block = (unsigned char*) malloc(8*sizeof(char));
    unsigned char* processed_block = (unsigned char*) malloc(8*sizeof(char));
    key_set* key_sets = (key_set*)malloc(17*sizeof(key_set));

    generate_sub_keys(des_key, key_sets);

    fseek(fin, 0L, SEEK_END);
    file_size = ftell(fin);

    fseek(fin, 0L, SEEK_SET);
    number_of_blocks = file_size/8 + ((file_size%8)?1:0);

    while(fread(data_block, 1, 8, fin))
    {
        block_count++;
        if (block_count == number_of_blocks)
        {
            if (mode == 1)
            {
                padding = 8 - file_size%8;
                if (padding < 8)
                {
                    memset((data_block + 8 - padding), (unsigned char)padding, padding);
                }

                process_msg(data_block, processed_block, key_sets, mode);
                bytes_written = fwrite(processed_block, 1, 8, fout);

                if (padding == 8)
                {
                    memset(data_block, (unsigned char)padding, 8);
                    process_msg(data_block, processed_block, key_sets, mode);
                    bytes_written = fwrite(processed_block, 1, 8, fout);
                }
            }
            else
            {
                process_msg(data_block, processed_block, key_sets, mode);
                padding = processed_block[7];

                if (padding < 8)
                    bytes_written = fwrite(processed_block, 1, 8 - padding, fout);
            }
        }
        else
        {
            process_msg(data_block, processed_block, key_sets, mode);
            bytes_written = fwrite(processed_block, 1, 8, fout);
        }
        memset(data_block, 0, 8);
    }

    free(des_key);
    free(data_block);
    free(processed_block);
    fclose(fin);
    fclose(fout);

    if(mode == 1)
        QMessageBox::information(this,"Message","Encrypted");
    if(mode == 0)
        QMessageBox::information(this,"Message","Decrypted");
    return 0;
}

void des::Encrypt()
{
    int mode = 1;
    main(mode);
}

void des::Decrypt()
{
    int mode = 0;
    main(mode);
}
