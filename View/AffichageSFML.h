#ifndef AFFICHAGESFML_H_HEADER
#define AFFICHAGESFML_H_HEADER

#include "../Model/Terrain.h"
#include <SFML/Graphics.hpp>

#define SCALE 0.1953125

class View {


public: 

	sf::Texture texture_close;
	sf::Texture texture_vide;
	sf::Texture texture_mine;
	sf::Texture texture_un;
	sf::Texture texture_deux;
	sf::Texture texture_trois;
	sf::Texture texture_quatre;
	sf::Texture texture_cinq;
	sf::Texture texture_six;
	sf::Texture texture_sept;
	sf::Texture texture_huit;
	sf::Texture texture_drapeau;
	sf::Texture texture_boom;

	sf::Sprite sprite_close;
	sf::Sprite sprite_vide;
	sf::Sprite sprite_mine;
	sf::Sprite sprite_un;
	sf::Sprite sprite_deux;
	sf::Sprite sprite_trois;
	sf::Sprite sprite_quatre;
	sf::Sprite sprite_cinq;
	sf::Sprite sprite_six;
	sf::Sprite sprite_sept;
	sf::Sprite sprite_huit;
	sf::Sprite sprite_drapeau;
	sf::Sprite sprite_boom;

	View();





};

void afficherTerrainSFML(View* view, Terrain* p, sf::RenderWindow& window, bool pressed);
sf::Texture loadTexture(std::string texture);
void setIcon(sf::RenderWindow& window);

#endif // !AFFICHAGESFML_H_HEADER

