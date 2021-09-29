#include "pix.h"

pix::pix(){


}

void pix::asignar_pix(){

    for(int y = 0; y < height(); y++){

        for(int x = 0; x < width(); x++){

            asignar_color=new intensidades;

            asignar_color->Rojo=pixelColor(x,y).red();

            if (asignar_color->Rojo==255) asignar_color->Rojo=254;

            if (asignar_color->Rojo==0) asignar_color->Rojo=4;

            asignar_color->Verde=pixelColor(x,y).green();

            if (asignar_color->Verde==255) asignar_color->Verde=254;

            if (asignar_color->Verde==0) asignar_color->Verde=4;

            asignar_color->Azul=pixelColor(x,y).blue();

            if (asignar_color->Azul==255) asignar_color->Azul=254;

            if (asignar_color->Azul==0) asignar_color->Azul=4;

            pixel.push_back(*asignar_color);

            delete asignar_color;
        }

        num_pixels.push_back(pixel);

        pixel.clear();
    }


}

int pix::sub_sob(int px, int py){

    int cantidad_pixeles = px*py ;

    int ancho_iamgen, alto_imagen, dimension_matriz ;

    ancho_iamgen = width() ;

    alto_imagen = height() ;

    dimension_matriz = ancho_iamgen * alto_imagen ;




    if( cantidad_pixeles < dimension_matriz ){

        dX =  ( ancho_iamgen )/( px ) ;

        dY = ( alto_imagen )/( py ) ;

        siz = ( dX )*( dY ) ;

        return 0 ;

    }else if( cantidad_pixeles > dimension_matriz ){

        dX = ( px )/( ancho_iamgen ) ;

        dY = ( py )/( alto_imagen ) ;

        siz = ( dX )*( dY ) ;

        return  1 ;
    }
    else{

        return 2 ;
    }


}
/*
void pix::Submuestreo(){

    int cont = 0, promedioX = 0 , promedioY = 0, pixcont = 0, limiteX = 0 ;

    long int promedio_Rojo = 0 , promedio_Verde = 0, promedio_Azul = 0 ;

    while( cont < (width() * height() ) ){

        for( int y = 0 ; y < dY ; y++ ){


            for( int x = 0 ; x < dX ; x++ ){


                promedio_Rojo = num_pixels[promedioY+y][promedioX+x].Rojo + promedio_Rojo ;

                promedio_Verde = num_pixels[promedioY+y][promedioX+x].Verde + promedio_Verde ;

                promedio_Azul = num_pixels[promedioY+y][promedioX+x].Azul + promedio_Azul
        }


        asignar_color = new intensidades ;

        asignar_color->Rojo = promedio_Rojo/siz ;

        asignar_color->Verde = promedio_Verde/siz ;

        asignar_color->Azul = promedio_Azul/siz ;

        if( pixcont == 16 ){

            nueva_redi.push_back( pixel ) ;

            pixel.clear() ;

            pixcont = 0 ;
        }



        promedio_Rojo = 0 ;

        promedio_Verde = 0 ;

        promedio_Azul = 0 ;

    }

}
*/

/*
void pix::Sobremuestreo(){

    int distX = 0, x1 = 0, y1 = 0 ;

    for(int y = 0 ; y < height() ; y++ ){


        for( int x = 0 ; x < width() ; x++ ){


            asignar_color = new intensidades;

            asignar_color->Rojo = num_pixels[y][x]

            asignar_color->Verde = num_pixels[y][x]
            asignar_color->Azul = num_pixels[y][x];

            for( int pY = 0 ; pY < dY ; pY++ ){

                for( int pX = 0 ; pX < dX ; pX++ ){

                }





            }



            delete asignar_color ;


        }


    }


}
*/
