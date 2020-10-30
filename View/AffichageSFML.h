#ifndef AFFICHAGESFML_H_HEADER
#define AFFICHAGESFML_H_HEADER

#include "../Model/Terrain.h"
#include <SFML/Graphics.hpp>

#define SCALE 0.1953125

void afficherTerrainSFML(Terrain* p, sf::RenderWindow& window);
sf::Texture loadTexture(std::string texture);
void setIcon(sf::RenderWindow& window);

#endif // !AFFICHAGESFML_H_HEADER

