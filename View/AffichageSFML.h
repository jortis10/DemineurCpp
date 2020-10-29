#ifndef AFFICHAGESFML_H_HEADER
#define AFFICHAGESFML_H_HEADER

#include "../Model/Plateau.h"
#include <SFML/Graphics.hpp>
#include <string>


#define WIDTH 400
#define HEIGHT 400

void affichageMenu(sf::RenderWindow& window);
void afficherPlateauSFML(Plateau* p, sf::RenderWindow& window);
sf::Texture loadTexture(std::string texture);
sf::Sprite loadSpriteWithTexture(sf::Texture texture, int pos_x, int pos_y);

#endif // !AFFICHAGESFML_H_HEADER

