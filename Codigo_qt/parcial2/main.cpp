#include <iostream>
#include <QImage>
#include "pix.h"

using namespace std;

int main()
{
    cout << "Bienvenido." << endl;
    cout << "Se le informa que, con el fin de mostrar la imagen elegida de forma correcta en la matriz de neopixeles construida," << endl;
    cout << "debe hacer uso de este programa y otro localizado en el sitio web de Tinkercad." << endl;
    cout << "Primero, ingrese la direccion de la imagen de la bandera que desea representar:" << endl;
    cout << "  - Para conocer dicha direccion, ubiquese en el lugar del explorador de archivos de su ordenador donde se encuentra la imagen," << endl;
    cout << "  despues, haga clic derecho a la derecha de la ruta de la imagen en la barra de direcciones y escoja la opcion Copiar direccion como texto." << endl;
    cout << "  Finalmente, pegue la direccion aqui, cambie todos los backslash por slash y agregue el nombre de la imagen incluyendo su respectiva extension." << endl;
    cout << "  - Recuerde que el formato de la imagen debe ser en formato JPG." << endl;
    cout << "  Para ver el formato de su imagen, dirigase al explorador de archivos de su ordenador:" << endl;
    cout << "  Seccion Vista > Apartado Mostrar u Ocultar > Activar la casilla de Extensiones de nombre de archivo" << endl;
    cout << "  A continuacion, dirigase al lugar donde tiene guardada su imagen y fijese en el nombre de su imagen," << endl;
    cout << "  las letras que se encuentran despues del punto, ese es el formato de su imagen." << endl;
    string filename;
    getline(cin,filename);
    QImage im(filename.c_str());
    pix matriz_pixeles(im);
    cout << "La imagen dada ha sido procesada exitosamente. Ahora, por favor dirigase al archivo ubicado en la" << endl;
    cout << " direccion especificada en el archivo instrucciones_de_uso.txt, ubicado en la carpeta Manual_Uso." << endl;
    return 0;
}
