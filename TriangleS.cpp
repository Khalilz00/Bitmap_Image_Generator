#include "TriangleS.h"
#include "Ligne.h"
#include <algorithm>  // Pour std::swap et std::min / std::max

void TriangleS::dessiner(CImage &image) {
    // Fonction lambda pour dessiner une ligne horizontale remplie entre deux points x
    auto drawHorizontalLine = [&](int y, int xStart, int xEnd) {
        if (xStart > xEnd) std::swap(xStart, xEnd);
        for (int x = xStart; x <= xEnd; ++x) {
            CPixel* pixel = image.getLigne(y)->getPixel(x);
            if (pixel) {
                unsigned char newR = ((100 - transp) * pixel->Red() + transp * r) / 100;
                unsigned char newG = ((100 - transp) * pixel->Green() + transp * g) / 100;
                unsigned char newB = ((100 - transp) * pixel->Blue() + transp * b) / 100;
                pixel->RGB(newR, newG, newB);
            }
        }
    };

    // Décomposer le triangle en trois points
    int x0 = x, y0 = y;
    int x1 = x2, y1 = y2;
    int x2 = this->x3, y2 = this->y3;

    // Trier les points du triangle par leur coordonnée y
    if (y0 > y1) { std::swap(y0, y1); std::swap(x0, x1); }
    if (y0 > y2) { std::swap(y0, y2); std::swap(x0, x2); }
    if (y1 > y2) { std::swap(y1, y2); std::swap(x1, x2); }

    // Remplissage de la première moitié du triangle (entre y0 et y1)
    if (y1 != y0) {
        float invSlope1 = float(x1 - x0) / (y1 - y0);
        float invSlope2 = float(x2 - x0) / (y2 - y0);
        float curX1 = x0;
        float curX2 = x0;

        for (int scanY = y0; scanY < y1; ++scanY) {
            drawHorizontalLine(scanY, static_cast<int>(curX1), static_cast<int>(curX2));
            curX1 += invSlope1;
            curX2 += invSlope2;
        }
    }

    // Remplissage de la deuxième moitié du triangle (entre y1 et y2)
    if (y2 != y1) {
        float invSlope1 = float(x2 - x1) / (y2 - y1);
        float invSlope2 = float(x2 - x0) / (y2 - y0);
        float curX1 = x1;
        float curX2 = x0 + invSlope2 * (y1 - y0);

        for (int scanY = y1; scanY <= y2; ++scanY) {
            drawHorizontalLine(scanY, static_cast<int>(curX1), static_cast<int>(curX2));
            curX1 += invSlope1;
            curX2 += invSlope2;
        }
    }
}
