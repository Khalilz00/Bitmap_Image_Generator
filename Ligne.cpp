#include "Ligne.h"
#include <cmath>
#include <iostream> // Pour les affichages de débogage

void Ligne::dessiner(CImage &image)
{
    // Utiliser les nouvelles variables x2 et y2
    int dx = x2 - x;
    int dy = y2 - y;

    // Calcul du nombre de pas, s'assurant qu'on couvre tous les pixels entre les deux points
    int steps = std::max(abs(dx), abs(dy));

    // Incréments pour chaque axe
    float incrementX = dx / float(steps);
    float incrementY = dy / float(steps);

    // Initialisation des coordonnées courantes
    float currentX = x;
    float currentY = y;

    // Boucle jusqu'à <= steps pour inclure le dernier pixel
    for (int i = 0; i <= steps; i++) {
        // Dessiner le pixel à la position arrondie
        CPixel *pixel = image.getLigne(round(currentY))->getPixel(round(currentX));
            
        if (pixel != nullptr) {
            // Calculer les nouvelles valeurs RGB avec transparence
            unsigned char newR = ((100 - transp) * pixel->Red() + transp * r) / 100;
            unsigned char newG = ((100 - transp) * pixel->Green() + transp * g) / 100;
            unsigned char newB = ((100 - transp) * pixel->Blue() + transp * b) / 100;

            // Appliquer la couleur au pixel
            pixel->RGB(newR, newG, newB);
        }

        // Incrémenter les coordonnées pour passer au point suivant
        currentX += incrementX;
        currentY += incrementY;
    }
}
