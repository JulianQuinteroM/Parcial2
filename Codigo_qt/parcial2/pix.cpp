#include "pix.h"

#include <iostream>
pix::pix(QImage image_dir)
{
    auxX = new short int;
    auxY = new short int;
    for(int color = 0; color <= 2; color++){
        *auxX = image_dir.width();
        *auxY = image_dir.height();
        for(int indx = 0; indx < image_dir.width(); indx=indx+2){
            for(int indy = 0; indy < image_dir.height(); indy=indy+2){
                if(*auxX >= 16 || *auxY >= 16){
                    if(color == 0){
                        image_dir.setPixelColor(indx,indy,(image_dir.pixelColor(indx,indy).red() + image_dir.pixelColor(indx+1,indy).red() + image_dir.pixelColor(indx,indy+1).red() + image_dir.pixelColor(indx+1,indy+1).red())/4);
                    }
                    if(color == 1){
                        image_dir.setPixelColor(indx,indy,(image_dir.pixelColor(indx,indy).blue() + image_dir.pixelColor(indx+1,indy).blue() + image_dir.pixelColor(indx,indy+1).blue() + image_dir.pixelColor(indx+1,indy+1).blue())/4);
                    }
                    if(color == 2){
                        image_dir.setPixelColor(indx,indy,(image_dir.pixelColor(indx,indy).green() + image_dir.pixelColor(indx+1,indy).green() + image_dir.pixelColor(indx,indy+1).green() + image_dir.pixelColor(indx+1,indy+1).green())/4);
                    }
                    *auxX = *auxX/2;
                    *auxY = *auxY/2;
                }
                else{
                    break;
                }
            }
        }
    }
    for(int x = 0; x < *auxX; x++){
        for(int y = 0; y < *auxY; y++){
            cout << image_dir.pixelColor(x,y).red() << "\t";
            cout << image_dir.pixelColor(x,y).blue() << "\t";
            cout << image_dir.pixelColor(x,y).green() << "\t";
        }
        cout << endl;
    }
}
