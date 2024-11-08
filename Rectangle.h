#pragma once
#include "Forme.h"


class Rectangle : public Forme {
protected: 
    int largeur;
    int hauteur; 

public: 
Rectangle(int x=0, int y=0, int largeur = 20 , int hauteur = 10 , std::string couleur ="noir", int transp = 100, int z = 0)
    : Forme(x,y,couleur,transp, z), largeur(largeur), hauteur(hauteur)  {}

void dessiner(CImage &image) override;


// Getters & Setters
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }

    void setLargeur(int _largeur) { largeur = _largeur; }
    void setHauteur(int _hauteur) { hauteur = _hauteur; }

};