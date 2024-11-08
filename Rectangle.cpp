#include "Rectangle.h"

void Rectangle::dessiner(CImage &image) {


    //Ligne supérieure
    for (int i = x ; i < x+largeur ; i++ ){
        CPixel *pixel = image.getLigne(y+hauteur-1)->getPixel(i); 
        if (pixel != nullptr) {
            //couleur actuelle du pixel 
            unsigned char fondR = pixel->Red();
            unsigned char fondG = pixel->Green();
            unsigned char fondB = pixel->Blue();

            //calcul couleur avec indice de transparence
            unsigned char newR = ((100-transp) * fondR + transp *r)/100;
            unsigned char newG = ((100-transp) * fondG + transp *g)/100;
            unsigned char newB = ((100-transp) * fondB + transp *b)/100;            

            pixel->RGB(newR,newG,newB);
        }
    }

    //Ligne inférieur
    for (int i = x ; i < x+largeur ; i++ ){
        CPixel *pixel = image.getLigne(y)->getPixel(i); 
        if (pixel != nullptr) {
           //couleur actuelle du pixel 
            unsigned char fondR = pixel->Red();
            unsigned char fondG = pixel->Green();
            unsigned char fondB = pixel->Blue();

            //calcul couleur avec indice de transparence
            unsigned char newR = ((100-transp) * fondR + transp *r)/100;
            unsigned char newG = ((100-transp) * fondG + transp *g)/100;
            unsigned char newB = ((100-transp) * fondB + transp *b)/100;            

            pixel->RGB(newR,newG,newB);
        }
    }

    //Ligne gauche
    for (int i = y+1 ; i < y+hauteur-1 ; i++ ){
        CPixel *pixel = image.getLigne(i)->getPixel(x); 
        if (pixel != nullptr) {
            //couleur actuelle du pixel 
            unsigned char fondR = pixel->Red();
            unsigned char fondG = pixel->Green();
            unsigned char fondB = pixel->Blue();

            //calcul couleur avec indice de transparence
            unsigned char newR = ((100-transp) * fondR + transp *r)/100;
            unsigned char newG = ((100-transp) * fondG + transp *g)/100;
            unsigned char newB = ((100-transp) * fondB + transp *b)/100;            

            pixel->RGB(newR,newG,newB);
        }
    }

    //Ligne droite
    for (int i = y+1 ; i < y+hauteur-1 ; i++  ){
        CPixel *pixel = image.getLigne(i)->getPixel(x+largeur-1); 
        if (pixel != nullptr) {
            //couleur actuelle du pixel 
            unsigned char fondR = pixel->Red();
            unsigned char fondG = pixel->Green();
            unsigned char fondB = pixel->Blue();

            //calcul couleur avec indice de transparence
            unsigned char newR = ((100-transp) * fondR + transp *r)/100;
            unsigned char newG = ((100-transp) * fondG + transp *g)/100;
            unsigned char newB = ((100-transp) * fondB + transp *b)/100;            

            pixel->RGB(newR,newG,newB);
        }
    }

}