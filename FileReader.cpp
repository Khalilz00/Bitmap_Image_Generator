#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Point.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Ligne.h"
#include "RectangleS.h"
#include "CarreS.h"
#include "Cercle.h"
#include "CercleS.h"
#include "Triangle.h"
#include "TriangleS.h"

// variable globale pour stocker la résolution minimale de l'image generée
int resolution = 0;

// Vecteur pour stocker les formes avec leur niveau `z`
std::vector<Forme *> formes;

// Fonction pour mettre à jour la résolution minimale de l'image si necessaire
void updateResolution(int x, int y, int taille)
{
    int newResolution = taille + std::max(x, y);
    if (newResolution > resolution)
    {
        resolution = newResolution;
    }
}

// Fonction pour faire une premiere lecture du fichier vec pour determiner la resolution minimale de l'image
void determinerResolutionMin(const std::string &fichier_initial, float echelle)
{
    std::ifstream fichier(fichier_initial);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur ouverture fichier " << fichier_initial << std::endl;
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne))
    {
        std::istringstream ss(ligne);
        std::string typeForme;
        ss >> typeForme;

        if (typeForme == "Point")
        {
            int x, y, transparence;
            std::string couleur;
            ss >> x >> y >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            updateResolution(x, y, 0); // Point n'a pas de taille, donc taille = 0
            std::cout << "Point: (" << x << ", " << y << ") avec échelle" << std::endl;
        }
        else if (typeForme == "Ligne")
        {
            int x, y, a, b, transparence;
            std::string couleur;
            ss >> x >> y >> a >> b >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            a = static_cast<int>(a * echelle);
            b = static_cast<int>(b * echelle);
            updateResolution(x, y, 0); // Ligne n'a pas de taille propre
            updateResolution(a, b, 0);
            std::cout << "Ligne: (" << x << ", " << y << ") -> (" << a << ", " << b << ") avec échelle" << std::endl;
        }
        else if (typeForme == "Rectangle" || typeForme == "RectangleS")
        {
            int x, y, largeur, hauteur, transparence;
            std::string couleur;
            ss >> x >> y >> largeur >> hauteur >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            largeur = static_cast<int>(largeur * echelle);
            hauteur = static_cast<int>(hauteur * echelle);
            updateResolution(x, y, std::max(largeur, hauteur));
            std::cout << "Rectangle: (" << x << ", " << y << "), largeur: " << largeur << ", hauteur: " << hauteur << " avec échelle" << std::endl;
        }
        else if (typeForme == "Carre" || typeForme == "CarreS")
        {
            int x, y, cote, transparence;
            std::string couleur;
            ss >> x >> y >> cote >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            cote = static_cast<int>(cote * echelle);
            updateResolution(x, y, cote);
            std::cout << "Carre: (" << x << ", " << y << "), côté: " << cote << " avec échelle" << std::endl;
        }
        else if (typeForme == "Cercle" || typeForme == "CercleS")
        {
            int x, y, rayon, transparence;
            std::string couleur;
            ss >> x >> y >> rayon >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            rayon = static_cast<int>(rayon * echelle);
            updateResolution(x, y, rayon + 1);
            std::cout << "Cercle: centre (" << x << ", " << y << "), rayon: " << rayon << " avec échelle" << std::endl;
        }
        else if (typeForme == "Triangle" || typeForme == "TriangleS")
        {
            int x, y, x2, y2, x3, y3, transparence;
            std::string couleur;
            ss >> x >> y >> x2 >> y2 >> x3 >> y3 >> couleur >> transparence;
            x = static_cast<int>(x * echelle);
            y = static_cast<int>(y * echelle);
            x2 = static_cast<int>(x2 * echelle);
            y2 = static_cast<int>(y2 * echelle);
            x3 = static_cast<int>(x3 * echelle);
            y3 = static_cast<int>(y3 * echelle);

            // Calculer les coordonnées maximales
            int maxX = std::max(x, std::max(x2, x3));
            int maxY = std::max({y, y2, y3});

            // Mettre à jour la résolution avec les coordonnées maximales
            updateResolution(maxX, maxY, 0);

            // Afficher les coordonnées pour vérification
            std::cout << "Triangle: (" << x << ", " << y << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ") avec échelle" << std::endl;
        }
    }
    fichier.close();
}

// Fonction pour lire et dessiner les formes à partir du fichier .vec
void lireEtStocker(const std::string &fichier_initial, CImage &image, float echelle)
{
    std::ifstream fichier(fichier_initial);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur ouverture fichier " << fichier_initial << std::endl;
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne))
    {
        std::istringstream ss(ligne);
        std::string typeForme;
        ss >> typeForme;

        if (typeForme == "Point")
        {
            int x, y, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                formes.push_back(new Point(x, y, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Point" << std::endl;
            }
        }
        else if (typeForme == "Ligne")
        {
            int x, y, a, b, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> a >> b >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                a = static_cast<int>(a * echelle);
                b = static_cast<int>(b * echelle);
                formes.push_back(new Ligne(x, y, a, b, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Ligne" << std::endl;
            }
        }
        else if (typeForme == "Rectangle")
        {
            int x, y, largeur, hauteur, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> largeur >> hauteur >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                largeur = static_cast<int>(largeur * echelle);
                hauteur = static_cast<int>(hauteur * echelle);
                formes.push_back(new Rectangle(x, y, largeur, hauteur, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Rectangle" << std::endl;
            }
        }
        else if (typeForme == "RectangleS")
        {
            int x, y, largeur, hauteur, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> largeur >> hauteur >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                largeur = static_cast<int>(largeur * echelle);
                hauteur = static_cast<int>(hauteur * echelle);
                formes.push_back(new RectangleS(x, y, largeur, hauteur, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour RectangleS" << std::endl;
            }
        }
        else if (typeForme == "Carre")
        {
            int x, y, cote, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> cote >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                cote = static_cast<int>(cote * echelle);
                formes.push_back(new Carre(x, y, cote, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Carre" << std::endl;
            }
        }
        else if (typeForme == "CarreS")
        {
            int x, y, cote, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> cote >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                cote = static_cast<int>(cote * echelle);
                formes.push_back(new CarreS(x, y, cote, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour CarreS" << std::endl;
            }
        }
        else if (typeForme == "Cercle")
        {
            int x, y, rayon, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> rayon >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                rayon = static_cast<int>(rayon * echelle);
                formes.push_back(new Cercle(x, y, rayon, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Cercle" << std::endl;
            }
        }
        else if (typeForme == "CercleS")
        {
            int x, y, rayon, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> rayon >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                rayon = static_cast<int>(rayon * echelle);
                formes.push_back(new CercleS(x, y, rayon, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour CercleS" << std::endl;
            }
        }
        else if (typeForme == "Triangle")
        {
            int x, y, x2, y2, x3, y3, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> x2 >> y2 >> x3 >> y3 >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                x2 = static_cast<int>(x2 * echelle);
                y2 = static_cast<int>(y2 * echelle);
                x3 = static_cast<int>(x3 * echelle);
                y3 = static_cast<int>(y3 * echelle);
                formes.push_back(new Triangle(x, y, x2, y2, x3, y3, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour Triangle" << std::endl;
            }
        }
        else if (typeForme == "TriangleS")
        {
            int x, y, x2, y2, x3, y3, transparence, z = 0;
            std::string couleur;
            if (ss >> x >> y >> x2 >> y2 >> x3 >> y3 >> couleur >> transparence)
            {
                if (!(ss >> z))
                {
                    z = 0; // Si `z` n'est pas fourni, on le considère comme 0
                }
                x = static_cast<int>(x * echelle);
                y = static_cast<int>(y * echelle);
                x2 = static_cast<int>(x2 * echelle);
                y2 = static_cast<int>(y2 * echelle);
                x3 = static_cast<int>(x3 * echelle);
                y3 = static_cast<int>(y3 * echelle);
                formes.push_back(new TriangleS(x, y, x2, y2, x3, y3, couleur, transparence, z));
            }
            else
            {
                std::cerr << "Erreur: paramètre(s) manquant(s) pour TriangleS" << std::endl;
            }
        }
    }
    fichier.close();
}
