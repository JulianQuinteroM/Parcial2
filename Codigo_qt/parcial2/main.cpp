#include "pix.h"


int main()
{

    pix imagen ;

    string base_direccion, nombre_imagen ;

    bool flag ;

    base_direccion = "../parcial2/imagenes/" ;       //Definimos la ruta de donde se extraerá la imagen

    cout << "                                               Bienvenido                                " << endl;
    cout << "  Este programa lee imagenes ingresadas por el usuario, con la particularidad de usar metodos de submuestreo o sobremuestreo" << endl;
    cout << "  para cambiar el tamaño original de la imagen" << endl << endl;
    cout << "  Ingrese el nombre de su Imagen con su formato correspondiente." << endl;
    cout << "  - Recuerde que el formato de la imagen debe ser en formato JPG. Ejm--> (colombia.jpg)"<< endl;

    cout << " Nombre de la imagen: " ;

    cin >> nombre_imagen ;

    cout << endl ;

    base_direccion.append( nombre_imagen ) ;

    flag = imagen.load( base_direccion.c_str() ) ;

    if( flag ){

       cout << " Imagen Cargada" << endl ;

       imagen.asignar_pix() ;

       int n = imagen.sub_sob( 16, 16 ) ;

       switch( n ){

           case 0 :{

            //imagen.Submuestreo();

            //imagen.w_intensidades() ;

           }break;

           case 1:{

            //imagen.Fill() ;

            //imagen.Sobremuestreo() ;

            //imagen.w_intensidades() ;

           }break;

           case 2 :{
           }break;

       }


    }else{

      cout << "ERROR" << endl ;

    }

    cout << endl ;

    return 0;
}
