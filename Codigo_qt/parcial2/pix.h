#ifndef PIX_H
#define PIX_H

#include <vector>
#include <QImage>

using namespace std;

class pix
{
public:
    pix(QImage image_dir);
    void assignToPix(QImage image_dir);
    void remuestreo(QImage image_dir, int *auxX, int *auxY);
private:
    vector<short int> pixel;
    short int **mat;
    int *auxX, *auxY;
};

#endif // PIX_H
