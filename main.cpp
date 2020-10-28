#include <iostream>
#include "Controler/jeu.h"

#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
    while (window.isOpen())
    {
        lancerPartie(20, 20, 0.3);

        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �v�nement "fermeture demand�e" : on ferme la fen�tre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
