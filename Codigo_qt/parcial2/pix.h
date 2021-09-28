#ifndef PIX_H
#define PIX_H

#include <vector>
#include <QImage>
#include <iostream>
#include <fstream>

using namespace std;

class pix
{
public:
    pix(QImage image_dir);
    void assignToPix(QImage image_dir);
    QImage subm_gen(QImage image_dir, int *auxX, int *auxY);
    void submuestreo(QImage image_dir, int *auxX, int *auxY);
    void sobremuestreo(QImage image_dir, int *auxX, int *auxY);
    void create_file(string name);
    string create_string();
    void write_file(string name, string texto);
private:
    vector<short int> pixel;
    int *auxX, *auxY;
};

#endif // PIX_H
