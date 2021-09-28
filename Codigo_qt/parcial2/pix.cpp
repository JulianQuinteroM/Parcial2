#include "pix.h"

pix::pix(QImage image_dir)
{
    auxX = new int;
    auxY = new int;
    *auxX = image_dir.width();
    *auxY = image_dir.height();
    if(*auxX == 8 && *auxY == 8) assignToPix(image_dir);
    else if(*auxX < 8 || *auxY < 8){
        *auxX = image_dir.width();
        *auxY = image_dir.height();
        sobremuestreo(image_dir, auxX, auxY);
    }
    else if(*auxX > 8 && *auxY > 8){
        image_dir = subm_gen(image_dir, auxX, auxY);
        submuestreo(image_dir, auxX, auxY);
    }
    string text = create_string();
}

void pix::assignToPix(QImage image_dir)
{
    for(int y = 0; y < *auxY; y++){
        for(int x = 0; x < *auxX; x++){
            pixel.push_back(short(image_dir.pixelColor(x,y).red()));
            pixel.push_back(short(image_dir.pixelColor(x,y).green()));
            pixel.push_back(short(image_dir.pixelColor(x,y).blue()));
        }
    }
}

QImage pix::subm_gen(QImage image_dir, int *auxX, int *auxY)
{
    for(int color = 0; color <= 2; color++){
        *auxX = image_dir.width();
        *auxY = image_dir.height();
        while(*auxX >= 32 && *auxY >= 32){
            for(int indy = 0; indy+1 < *auxY; indy=indy+2){
                for(int indx = 0; indx+1 < *auxX; indx=indx+2){
                    QColor tipo_color(image_dir.pixelColor(indx/2,indy/2).red(),image_dir.pixelColor(indx/2,indy/2).green(),image_dir.pixelColor(indx/2,indy/2).blue());
                    if(color == 0){
                        tipo_color.setRed((image_dir.pixelColor(indx,indy).red() + image_dir.pixelColor(indx+1,indy).red() + image_dir.pixelColor(indx,indy+1).red() + image_dir.pixelColor(indx+1,indy+1).red())/4);
                    }
                    else if(color == 1){
                        tipo_color.setGreen((image_dir.pixelColor(indx,indy).green() + image_dir.pixelColor(indx+1,indy).blue() + image_dir.pixelColor(indx,indy+1).green() + image_dir.pixelColor(indx+1,indy+1).green())/4);
                    }
                    else if(color == 2){
                        tipo_color.setBlue((image_dir.pixelColor(indx,indy).blue() + image_dir.pixelColor(indx+1,indy).blue() + image_dir.pixelColor(indx,indy+1).blue() + image_dir.pixelColor(indx+1,indy+1).blue())/4);
                    }
                    image_dir.setPixelColor(indx/2,indy/2,tipo_color);
                }
            }
            *auxX = *auxX/2;
            *auxY = *auxY/2;
        }
    }
    return image_dir;
}

void pix::submuestreo(QImage image_dir, int *auxX, int *auxY)
{
    float distOriginX = 1 /(float(*auxX) - float(2)), dist = 1 /(float(8)), distOriginY = 1/(float(*auxY) - float(2));
    for(int y = 0; y < 8; y++){
        int iy = 0;
        for(;;iy++){
            if(iy*distOriginY > y*dist+dist/2) break;
        }
        int iy_min = iy;
        for(;iy_min >= 0; iy_min--){
            if(iy_min*distOriginY <= y*dist+dist/2) break;
        }
        for(int x = 0; x < 8; x++){
            int ix = 0;
            for(;;ix++){
                if(ix*distOriginX > x*dist+dist/2) break;
            }
            int ix_min = ix;
            for(;ix_min >= 0;ix_min--){
                if(ix_min*distOriginX <= x * dist+dist/2) break;
            }
            pixel.push_back(short((1/((ix*distOriginX-ix_min*distOriginX)*(iy*distOriginY-iy_min*distOriginY)))*((image_dir.pixelColor(ix_min,iy_min).red()*(ix*distOriginX-(x*dist+dist/2))*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix,iy_min).red()*((x*dist+dist/2)-ix_min*distOriginX)*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix_min,iy).red()*(ix*distOriginX-(x*dist+dist/2))*((y*dist+dist/2)-iy_min*distOriginY))+(image_dir.pixelColor(ix,iy).red()*((x*dist+dist/2)-ix_min*distOriginX)*((y*dist+dist/2)-iy_min*distOriginY)))));
            pixel.push_back(short((1/((ix*distOriginX-ix_min*distOriginX)*(iy*distOriginY-iy_min*distOriginY)))*((image_dir.pixelColor(ix_min,iy_min).green()*(ix*distOriginX-(x*dist+dist/2))*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix,iy_min).green()*((x*dist+dist/2)-ix_min*distOriginX)*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix_min,iy).green()*(ix*distOriginX-(x*dist+dist/2))*((y*dist+dist/2)-iy_min*distOriginY))+(image_dir.pixelColor(ix,iy).green()*((x*dist+dist/2)-ix_min*distOriginX)*((y*dist+dist/2)-iy_min*distOriginY)))));
            pixel.push_back(short((1/((ix*distOriginX-ix_min*distOriginX)*(iy*distOriginY-iy_min*distOriginY)))*((image_dir.pixelColor(ix_min,iy_min).blue()*(ix*distOriginX-(x*dist+dist/2))*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix,iy_min).blue()*((x*dist+dist/2)-ix_min*distOriginX)*(iy*distOriginY-(y*dist+dist/2)))+(image_dir.pixelColor(ix_min,iy).blue()*(ix*distOriginX-(x*dist+dist/2))*((y*dist+dist/2)-iy_min*distOriginY))+(image_dir.pixelColor(ix,iy).blue()*((x*dist+dist/2)-ix_min*distOriginX)*((y*dist+dist/2)-iy_min*distOriginY)))));
        }
    }
}

void pix::sobremuestreo(QImage image_dir, int *auxX, int *auxY)
{
    int mult = 16;
    *auxX = *auxX * mult;
    *auxY = *auxY * mult;
    QImage image(*auxX,*auxY,image_dir.format());
    image.fill(QColor(1,1,1));
    for(int y = 0; y < *auxY; y++){
        for(int x = 0; x < *auxX; x++){
            image.setPixelColor(x,y,QColor(image_dir.pixelColor(x/mult,y/mult).red(),image_dir.pixelColor(x/mult,y/mult).green(),image_dir.pixelColor(x/mult,y/mult).blue()));
        }
    }
    image_dir.~QImage();
    image = subm_gen(image,auxX,auxY);
    submuestreo(image,auxX,auxY);
}

void pix::create_file(string name)
{
    fstream text(name, fstream::out);
    text.close();
}

string pix::create_string()
{
    string texto;
    int cont = 1;
    for(auto i = pixel.begin(); i != pixel.end(); i++){
        if(*i >= 100){
            for(int mult = 100; mult >= 1; mult/=10){
                texto.push_back(char(*i/mult+48));
                *i = *i - (*i/mult)*mult;
            }
        }
        else if(*i >= 10){
            for(int mult = 10; mult >= 1; mult/= 10){
                texto.push_back(char(*i/mult+48));
                *i = *i - (*i/mult)*mult;
            }
            texto.push_back('.');
        }
        else{
            texto.push_back(char(*i+48));
            texto.push_back('.');
            texto.push_back('.');
        }
        if(cont%3!=0){
            texto.push_back(',');
        }
        else{
            texto.push_back(';');
        }
        if(cont%12==0) texto.push_back('\n');
        cont++;
    }
    return texto;
}

void pix::write_file(string name, string texto)
{
    fstream text(name, fstream::out);
    text <<texto;
    text.close();
}
