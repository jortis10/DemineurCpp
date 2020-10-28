#include <iostream>
#include "Controler/jeu.h"
#include "View/AffichageSFML.h"
#include "Model/Plateau.h"


#include <SFML/Graphics.hpp>

int main()
{
    //system("mode con LINES=20 COLS=50");
    lancerPartie(20, 20, 0.20);

    return 0;
}
