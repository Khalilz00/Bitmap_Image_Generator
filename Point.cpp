#include "Point.h"
#include "CPixel.h"

void Point::dessiner(CImage &image)
{
    CPixel *pixel = image.getLigne(y)->getPixel(x);

    if (pixel != nullptr)
    {
        // couleur pixel actuelle
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