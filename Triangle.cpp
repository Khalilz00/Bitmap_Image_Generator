#include "Triangle.h"
#include "Ligne.h"

void Triangle::dessiner(CImage &image)
{
    // Dessiner la première ligne du triangle (du point (x, y) à (x2, y2))
    Ligne ligne1(x, y, x2, y2, "bleu", transp);
    ligne1.dessiner(image);

    // Dessiner la deuxième ligne du triangle (du point (x2, y2) à (x3, y3))
    Ligne ligne2(x2, y2, x3, y3, "bleu", transp);
    ligne2.dessiner(image);

    // Dessiner la troisième ligne du triangle (du point (x3, y3) à (x, y))
    Ligne ligne3(x3, y3, x, y, "bleu", transp);
    ligne3.dessiner(image);
}


