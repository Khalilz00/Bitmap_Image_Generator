#include "CercleS.h"
#include "Cercle.h"
#include <cmath>

void CercleS::dessiner(CImage &image)
{
    for (int i = -rayon ; i <= rayon ; i++) {
        int deltaX = int(sqrt(std::pow(rayon, 2) - std::pow(i , 2)));

        for (int j = - deltaX ; j <= deltaX ; j++ ) {
            CPixel *pixel = image.getLigne(y + i)->getPixel(x + j);
            
            if (pixel != nullptr) {
            unsigned char newR = ((100 - transp) * pixel->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixel->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixel->Blue() + transp * b) / 100;
            pixel->RGB(newR, newG, newB);
        }
        }
    }
    
}