#pragma once
#include "Forme.h"


class Cercle : public Forme { 
protected: 
    int rayon; 

public: 
Cercle(int x=50, int y=50, int rayon=5 , std::string couleur ="rouge", int transp = 100, int z = 0)
    : Forme(x,y,couleur,transp, z), rayon(rayon){}

void dessiner(CImage &image) override;
};