#pragma once
#include "Rectangle.h"

class RectangleS : public Rectangle
{
public:
    RectangleS(int x = 0, int y = 0,int largeur = 20 , int hauteur = 10 , std::string couleur = "noir", int transp = 100, int z = 0)
        : Rectangle(x, y, largeur, hauteur, couleur, transp, z) {}
   
    void dessiner(CImage &image) override;
};