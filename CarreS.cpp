#include "CarreS.h"

#include "Carre.h"

void CarreS::dessiner(CImage &image)
{

    // Ligne supérieure
    for (int i = y; i < y + hauteur; i++)
    {
        for (int j = x; j < x + largeur; j++)
        {
            CPixel *pixel = image.getLigne(i)->getPixel(j);
            if (pixel != nullptr)
            {
                // couleur actuelle du pixel
                unsigned char fondR = pixel->Red();
                unsigned char fondG = pixel->Green();
                unsigned char fondB = pixel->Blue();

                // calcul couleur avec indice de transparence
                unsigned char newR = ((100 - transp) * fondR + transp * r) / 100;
                unsigned char newG = ((100 - transp) * fondG + transp * g) / 100;
                unsigned char newB = ((100 - transp) * fondB + transp * b) / 100;

                pixel->RGB(newR, newG, newB);
                
            }
             
        }
    }
}