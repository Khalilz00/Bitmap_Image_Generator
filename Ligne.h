#pragma once
#include "Forme.h"


class Ligne : public Forme {
protected: 
    int x2;
    int y2; 

public: 
Ligne(int x, int y, int x2, int y2, std::string couleur, int transp, int z = 0)
    : Forme(x, y, couleur, transp, z ), x2(x2), y2(y2){}


void dessiner(CImage &image) override;


// Getters & Setters

int getX2() const { return x2; }
int getY2() const { return y2; }
void setX2(int _x2) { x2 = _x2; }
void setY2(int _y2) { y2 = _y2; }


};