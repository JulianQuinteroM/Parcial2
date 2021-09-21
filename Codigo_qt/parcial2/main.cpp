#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    string filename = "../images/image.jpg";
    QImage im(filename.c_str());

    unsigned int pixX = 200;
    unsigned int pixY = 200;

    cout << "Intensidad de rojo del pixel seleccionado: " << im.pixelColor(pixX, pixY).red() << endl;
    cout << "Intensidad de verde del pixel seleccionado: " << im.pixelColor(pixX, pixY).green() << endl;
    cout << "Intensidad de azul del pixel seleccionado: " << im.pixelColor(pixX, pixY).blue() << endl;
    for(int indx = 0; indx < im.width(); ++indx){
        for(int indy = 0; indy < im.height(); ++indy){
            cout << indx << ", " << indy << " = " << im.pixelColor(indx,indy).red() << endl;
        }
    }
    return 0;
}
