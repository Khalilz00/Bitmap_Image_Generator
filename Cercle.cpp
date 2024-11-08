#include "Cercle.h"
#include <cmath>

void Cercle::dessiner(CImage &image) {
    // Parcours complet des quarts gauche et droit
    for (int i = 0; i <= rayon; i++) {
        // Calcul de la position en x pour ce i (y)
        int deltaX = int(sqrt(std::pow(rayon, 2) - std::pow(i, 2)));

        // Quart supérieur gauche
        CPixel *pixelHautGauche = image.getLigne(y + i)->getPixel(x - deltaX);
        if (pixelHautGauche != nullptr) {
            unsigned char newR = ((100 - transp) * pixelHautGauche->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelHautGauche->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelHautGauche->Blue() + transp * b) / 100;
            pixelHautGauche->RGB(newR, newG, newB);
        }

        // Quart inférieur gauche (symétrique par rapport à l'axe horizontal)
        CPixel *pixelBasGauche = image.getLigne(y - i)->getPixel(x - deltaX);
        if (pixelBasGauche != nullptr) {
            unsigned char newR = ((100 - transp) * pixelBasGauche->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelBasGauche->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelBasGauche->Blue() + transp * b) / 100;
            pixelBasGauche->RGB(newR, newG, newB);
        }

        // Quart supérieur droit (symétrique par rapport à l'axe vertical)
        CPixel *pixelHautDroit = image.getLigne(y + i)->getPixel(x + deltaX);
        if (pixelHautDroit != nullptr) {
            unsigned char newR = ((100 - transp) * pixelHautDroit->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelHautDroit->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelHautDroit->Blue() + transp * b) / 100;
            pixelHautDroit->RGB(newR, newG, newB);
        }

        // Quart inférieur droit (symétrique par rapport à l'axe horizontal et vertical)
        CPixel *pixelBasDroit = image.getLigne(y - i)->getPixel(x + deltaX);
        if (pixelBasDroit != nullptr) {
            unsigned char newR = ((100 - transp) * pixelBasDroit->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelBasDroit->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelBasDroit->Blue() + transp * b) / 100;
            pixelBasDroit->RGB(newR, newG, newB);
        }
    }

    // Parcours des quarts haut et bas (utilisation de x au lieu de y pour le calcul de la symétrie)
    for (int i = 0; i <= rayon; i++) {
        // Calcul de la position en y pour ce i (x)
        int deltaY = int(sqrt(std::pow(rayon, 2) - std::pow(i, 2)));

        // Quart droit supérieur
        CPixel *pixelDroitHaut = image.getLigne(y + deltaY)->getPixel(x + i);
        if (pixelDroitHaut != nullptr) {
            unsigned char newR = ((100 - transp) * pixelDroitHaut->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelDroitHaut->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelDroitHaut->Blue() + transp * b) / 100;
            pixelDroitHaut->RGB(newR, newG, newB);
        }

        // Quart droit inférieur
        CPixel *pixelDroitBas = image.getLigne(y - deltaY)->getPixel(x + i);
        if (pixelDroitBas != nullptr) {
            unsigned char newR = ((100 - transp) * pixelDroitBas->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelDroitBas->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelDroitBas->Blue() + transp * b) / 100;
            pixelDroitBas->RGB(newR, newG, newB);
        }

        // Quart gauche supérieur
        CPixel *pixelGaucheHaut = image.getLigne(y + deltaY)->getPixel(x - i);
        if (pixelGaucheHaut != nullptr) {
            unsigned char newR = ((100 - transp) * pixelGaucheHaut->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelGaucheHaut->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelGaucheHaut->Blue() + transp * b) / 100;
            pixelGaucheHaut->RGB(newR, newG, newB);
        }

        // Quart gauche inférieur
        CPixel *pixelGaucheBas = image.getLigne(y - deltaY)->getPixel(x - i);
        if (pixelGaucheBas != nullptr) {
            unsigned char newR = ((100 - transp) * pixelGaucheBas->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixelGaucheBas->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixelGaucheBas->Blue() + transp * b) / 100;
            pixelGaucheBas->RGB(newR, newG, newB);
        }
    }
}
