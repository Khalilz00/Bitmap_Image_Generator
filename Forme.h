#pragma once
#include <string>
#include "CImage.h"
#include <tuple>

class Forme
{

protected:
    int x;
    int y;
    std::string couleur;
    unsigned char r;
    unsigned char g;
    unsigned char b;

    int transp;
    int z; // Plan Z

public:
    Forme(int x = 0, int y = 0, std::string couleur = "noir", int transp = 100, int z = 0);

    virtual ~Forme() = default;

    virtual void dessiner(CImage &image) = 0;

    // Getters & Setters
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    std::string getCouleur() const { return couleur; }

    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    void setZ(int _z) { z = _z; }
    void setCouleur(const std::string &_couleur) { couleur = _couleur; }

    std::tuple<unsigned char, unsigned char, unsigned char> convertToRGB(const std::string &couleur);
};