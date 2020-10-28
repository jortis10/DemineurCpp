#include <iostream>
#include "Controler/jeu.h"

#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        lancerPartie(20, 20, 0.3);


        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
