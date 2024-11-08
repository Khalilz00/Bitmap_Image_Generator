#pragma once
#pragma once
#include "Forme.h"

class Triangle : public Forme
{
protected: 
int x2,y2,x3,y3;

public:
    Triangle(int x = 0, int y = 0, int x2 = 10 , int y2 = 10, int x3 = 20, int y3 = 20 ,std::string couleur = "bleu", int transp = 100, int z = 0)
        : Forme(x,y,couleur,transp,z), x2(x2), y2(y2), x3(x3), y3(y3){}
  void dessiner(CImage &image) override;
};
