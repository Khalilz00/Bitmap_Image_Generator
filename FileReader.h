// FileReader.h
#pragma once
#include <string>
#include <vector>
#include "CImage.h"
#include "Forme.h"

// Variable globale pour stocker la résolution minimale de l'image
extern int resolution;

// Vecteur global pour stocker les formes avec leur niveau `z`
extern std::vector<Forme*> formes;

// Fonction pour mettre à jour la résolution minimale de l'image
void updateResolution(int x, int y, int taille);

// Fonction pour déterminer la résolution minimale en fonction du fichier .vec
void determinerResolutionMin(const std::string &fichier_initial, float echelle);

// Fonction pour lire le fichier .vec et stocker les formes
void lireEtStocker(const std::string &fichier_initial, CImage &image, float echelle);
