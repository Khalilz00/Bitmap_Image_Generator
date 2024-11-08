# Projet de Génération de Bitmap avec Formes Géométriques Superposées

Ce projet génère une image bitmap contenant diverses formes géométriques superposées en fonction d'un fichier d'entrée `.vec`. Chaque forme peut être configurée avec une couleur, un niveau de transparence, et un plan (axe `z`) pour permettre une superposition des formes. Les formes sont stockées, triées par niveau `z`, et rendues dans l'ordre approprié dans l'image finale.

## Table des Matières
- [Fonctionnalités](#fonctionnalités)
- [Exigences](#exigences)
- [Structure du Projet](#structure-du-projet)
- [Fichier d'entrée `.vec`](#fichier-dentrée-vec)
- [Exécution](#exécution)
- [Exemples d'utilisation](#exemples-dutilisation)

---

### Fonctionnalités

- Prend en charge plusieurs formes géométriques : Points, Lignes, Rectangles, Carrés, Cercles, Triangles.
- Support de la transparence et des couleurs personnalisées pour chaque forme.
- Gestion de la superposition de formes grâce à un paramètre de plan `z` permettant de dessiner des formes dans un ordre spécifique.
- Permet d'appliquer un facteur d'échelle pour redimensionner les coordonnées des formes.

### Exigences

- **Langage** : C++
- **Bibliothèques** : Aucune dépendance externe requise pour ce projet.
- **Compilateur** : Un compilateur C++ compatible (GCC, Clang, ou MSVC)

### Structure du Projet

Le projet est organisé en plusieurs fichiers pour une meilleure modularité :
- **main.cpp** : Gère le flux principal du programme.
- **FileReader.h** / **FileReader.cpp** : Contient les fonctions pour lire le fichier d'entrée `.vec`, calculer la résolution minimale, et stocker les formes.
- **Formes géométriques** : Chaque forme est définie dans une classe distincte, par exemple `Point`, `Rectangle`, `Cercle`, etc.
- **CImage** et **CBitmap** : Gestion de l'image bitmap et des pixels.

### Fichier d'entrée `.vec`

Le fichier d'entrée `.vec` contient les informations pour chaque forme géométrique sous forme de texte. Chaque ligne représente une forme et suit une syntaxe spécifique :
- **Point** : `Point x y couleur transparence [z]`
- **Ligne** : `Ligne x y x2 y2 couleur transparence [z]`
- **Rectangle** : `Rectangle x y largeur hauteur couleur transparence [z]`
- **Carre** : `Carre x y cote couleur transparence [z]`
- **Cercle** : `Cercle x y rayon couleur transparence [z]`
- **Triangle** : `Triangle x y x2 y2 x3 y3 couleur transparence [z]`

**Remarque** : Le paramètre `z` est optionnel. Si `z` est omis, il est défini par défaut à `0`.

### Exécution

Pour compiler et exécuter le projet, suivez les étapes suivantes :

1. **Compilation**

   Utilisez un compilateur C++ pour compiler le projet. Voici un exemple de commande avec `g++` :
```bash
   g++ main.cpp FileReader.cpp CImage.cpp CBitmap.cpp Point.cpp Rectangle.cpp Carre.cpp Ligne.cpp Cercle.cpp Triangle.cpp -o generateur_bitmap
```
    
3. **Exécution**

    Une fois compilé, lancez le programme avec les paramètres suivants :
```bash
   ./generateur_bitmap fichier_initial.vec fichier_final.bmp [echelle]
```
fichier_initial.vec : Fichier d'entrée contenant la description des formes.

fichier_final.bmp : Nom du fichier de sortie, au format .bmp.

echelle (optionnel) : Facteur d'échelle appliqué aux coordonnées de chaque forme. Par défaut à 1.

### Exemples d'utilisation

1. **Exemple de Fichier .vec**

    Voici un exemple de fichier .vec avec plusieurs formes superposées :

            Rectangle 10 10 50 30 rouge 100 1
            Cercle 40 40 20 bleu 100 2
            Triangle 20 20 50 20 35 60 vert 100 0
            Carre 15 15 20 jaune 50 3

   Dans cet exemple :

   Le rectangle rouge se situe sur le plan z=1.
   Le cercle bleu se situe sur le plan z=2.
   Le triangle vert se situe sur le plan z=0 et sera tracé en arrière-plan.
   Le carré jaune se situe sur le plan z=3, il sera donc tracé en dernier.

    Commandes d'exécution

    Sans échelle (taille d'origine des formes) :
        ./generateur_bitmap exemple.vec resultat.bmp

    Avec une échelle de 1.5 :
        ./generateur_bitmap exemple.vec resultat.bmp 1.5


## Notes Importantes
#### Libération de la Mémoire :
     Le programme nettoie automatiquement la mémoire allouée aux formes à la fin de l'exécution.
#### Tracé et Superposition :
     Les formes sont tracées dans l'ordre croissant de z pour gérer correctement la superposition. Les formes de niveau z inférieur sont tracées en premier.
