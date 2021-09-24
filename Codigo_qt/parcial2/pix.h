#ifndef PIX_H
#define PIX_H

#include <vector>
#include <QImage>

using namespace std;

class pix
{
public:
    pix(QImage image_dir);
private:
    vector<short int[3][8][8]> pixel;
    short int **mat;
    int *auxX, *auxY;
};

#endif // PIX_MAT_H
