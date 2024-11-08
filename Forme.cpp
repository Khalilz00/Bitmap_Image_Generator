#include "Forme.h"
#include <map>
#include <iostream>

Forme::Forme(int x, int y, std::string couleur, int transp, int z)
    : x(x), y(y), couleur(couleur) , transp(transp), z(z)
{
    std::tuple<unsigned char, unsigned char, unsigned char> rgb = convertToRGB(couleur);
    r = std::get<0>(rgb) ;
    g = std::get<1>(rgb);
    b = std::get<2>(rgb);

}

std::tuple<unsigned char, unsigned char, unsigned char> Forme::convertToRGB(const std::string &couleur)
{
    static std::map<std::string, std::tuple<unsigned char, unsigned char, unsigned char>> colorMap = {
    {"rouge", {255, 0, 0}},
    {"vert", {0, 255, 0}},
    {"bleu", {0, 0, 255}},
    {"noir", {0, 0, 0}},
    {"blanc", {255, 255, 255}},
    {"jaune", {255, 255, 0}},
    {"cyan", {0, 255, 255}},
    {"magenta", {255, 0, 255}},
    {"gris", {128, 128, 128}},
    {"rose", {255, 192, 203}},
    {"violet", {128, 0, 128}},
    {"orange", {255, 165, 0}},
    {"marron", {165, 42, 42}},
    {"lime", {0, 255, 0}},
    {"indigo", {75, 0, 130}},
    {"or", {255, 215, 0}},
    {"argent", {192, 192, 192}},
    {"bleu ciel", {135, 206, 235}},
    {"olive", {128, 128, 0}},
    {"corail", {255, 127, 80}},
    {"turquoise", {64, 224, 208}},
    {"lavande", {230, 230, 250}},
    {"beige", {245, 245, 220}},
    {"chocolat", {210, 105, 30}},
    {"sable", {244, 164, 96}},
    {"bronze", {205, 127, 50}},
    {"ivoire", {255, 255, 240}},
    {"pêche", {255, 218, 185}},
    {"saumon", {250, 128, 114}},
    {"violet foncé", {139, 0, 139}}
    };

    auto it = colorMap.find(couleur);
    if (it != colorMap.end())
    {
        return it->second;
    }
    else
    {
        return {0, 0, 0};
    }
}