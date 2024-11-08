#pragma once
#include "Forme.h"

class Point : public Forme {

public : 
    Point(int x=0 , int y =0 , std::string couleur = "noir", int transp = 100 , int z = 0) : Forme(x,y,couleur,transp,z) {}
        
    void dessiner(CImage &image) override;
};
