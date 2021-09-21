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
    vector<short int[3][16][16]> pixel;
    short int **mat;
    short int *auxX, *auxY;
};


#endif // PIX_H
