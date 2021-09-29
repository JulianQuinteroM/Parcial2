#ifndef PIX_H
#define PIX_H

#include <iostream>
#include <QImage>
#include <string>
#include <vector>

using namespace std;

struct intensidades ;

class pix: public QImage
{
public:

    pix();

    void asignar_pix() ;

    int sub_sob( int px, int py );

    void Submuestreo() ;

    void Sobremuestreo() ;

    void w_intensidades();

    void Fill();

private:

   vector < vector < intensidades > > num_pixels ;

   vector < vector < intensidades > > nueva_redi ;

   vector < intensidades > pixel ;

   intensidades *asignar_color ;

   int siz, dX, dY ;



};


struct intensidades{

    unsigned int Rojo ;

    unsigned int Verde ;

    unsigned int Azul ;

};

#endif // PIX_H
