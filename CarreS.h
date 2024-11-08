#pragma once
#include "Carre.h"

class CarreS : public Carre
{
public:
    CarreS(int x = 0, int y = 0,int cote = 20 , std::string couleur = "noir", int transp = 100, int z   = 0)
        : Carre(x, y, cote, couleur, transp, z) {}
   
    void dessiner(CImage &image) override;
};