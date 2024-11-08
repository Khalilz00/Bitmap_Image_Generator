#pragma once
#include "Cercle.h"

class CercleS : public Cercle
{
public:
    CercleS(int x = 0, int y = 0,int rayon = 50 , std::string couleur = "noir", int transp = 100, int z = 0)
        : Cercle(x, y, rayon, couleur, transp, z) {}
   
    void dessiner(CImage &image) override;
};