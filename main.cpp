#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "CBitmap.h"
#include "CImage.h"
#include "FileReader.h"

int main(int argc, char *argv[])
{

    // Vérifier le nombre d'arguments
    if (argc < 3 || argc > 4)
    {
        std::cerr << "Utilisation : " << argv[0] << " fichier_initial.vec fichier_final.bmp [echelle]" << std::endl;
        return 1;
    }

    float echelle = 1;

    // Si l'echelle est fournie, la lire
    if (argc == 4)
    {
        echelle = std::stof(argv[3]); // convertir le string en float
    }
    // lire les paramètres
    std::string fichier_initial = argv[1];
    std::string fichier_final = argv[2];

    // Vérifier si le fichier initial existe
    std::ifstream fichier(fichier_initial);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur ouverture fichier " << fichier_initial << std::endl;
        return 1;
    }

    // Afficher les informations pour vérifier la lecture
    std::cout << "Fichier initial : " << fichier_initial << std::endl;
    std::cout << "Fichier final : " << fichier_final << std::endl;
    std::cout << "Echelle : " << echelle << std::endl;

    fichier.close();

    // Calculer la résolution minimale en fonction de l'échelle
    determinerResolutionMin(fichier_initial, echelle);

    // Afficher la résolution après application de l'échelle
    std::cout << "Résolution finale (après échelle) : " << resolution << std::endl;

    // Créer l'image avec la taille ajustée à la résolution calculée
    CImage image(resolution + 5, resolution + 5);

    // Lire le fichier vec et dessiner les formes avec l'échelle appliquée
    lireEtStocker(fichier_initial, image, echelle);

    // Trier les formes par leur niveau `z` croissant
    std::sort(formes.begin(), formes.end(), [](Forme *a, Forme *b)
              { return a->getZ() < b->getZ(); });

  

    // Dessiner les formes dans l'image
    for (Forme *forme : formes)
    {
        forme->dessiner(image);
    }

    // Libération de la mémoire
    for (Forme* forme : formes) {
        delete forme;
    }
    formes.clear();


    // Sauvegarder l'image dans un fichier .bmp
    CBitmap bitmap;
    bitmap.setImage(&image);

    if (bitmap.SaveBMP(fichier_final))
    {
        std::cout << "Bitmap généré avec succès dans " << fichier_final << std::endl;
    }
    else
    {
        std::cerr << "Erreur lors de la sauvegarde dans " << fichier_final << std::endl;
        return 1;
    }

    return 0;
}
