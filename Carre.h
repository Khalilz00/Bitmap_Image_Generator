#pragma once
#include "Rectangle.h"

class Carre : public Rectangle
{
public:
    Carre(int x = 0, int y = 0, int cote = 10, std::string couleur = "noir", int transp = 100, int z    = 0)
        : Rectangle(x, y, cote, cote, couleur, transp, z) {}

    // Getters & Setters
    int getCote() const { return largeur; }

    void setCote(int _cote)
    {
        largeur = _cote;
        hauteur = _cote;
    }
};