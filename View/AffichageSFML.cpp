#include <SFML/Graphics.hpp>
#include "AffichageSFML.h"
#include "../Model/Plateau.h"
#include <iostream>


void afficherPlateauSFML(Plateau* p, sf::RenderWindow& window) {

	/*Texture*/
	sf::Texture texture_close = loadTexture("Assets/close.png");
	sf::Texture texture_vide = loadTexture("Assets/vide.png");
	sf::Texture texture_mine = loadTexture("Assets/mine.png");
	sf::Texture texture_un = loadTexture("Assets/un.png");
	sf::Texture texture_deux = loadTexture("Assets/deux.png");
	sf::Texture texture_trois = loadTexture("Assets/trois.png");
	sf::Texture texture_quatre = loadTexture("Assets/quatre.png");
	sf::Texture texture_cinq = loadTexture("Assets/cinq.png");
	sf::Texture texture_six = loadTexture("Assets/six.png");
	sf::Texture texture_sept = loadTexture("Assets/sept.png");
	sf::Texture texture_huit = loadTexture("Assets/huit.png");
	sf::Texture texture_drapeau = loadTexture("Assets/drapeau.png");
	sf::Texture texture_boom = loadTexture("Assets/boom.png");


	/*Sprite*/
	sf::Sprite sprite_close;
	sprite_close.setTexture(texture_close);
	sf::Sprite sprite_vide;
	sprite_vide.setTexture(texture_vide);
	sf::Sprite sprite_mine;
	sprite_mine.setTexture(texture_mine);
	sf::Sprite sprite_un;
	sprite_un.setTexture(texture_un);
	sf::Sprite sprite_deux;
	sprite_deux.setTexture(texture_deux);
	sf::Sprite sprite_trois;
	sprite_trois.setTexture(texture_trois);
	sf::Sprite sprite_quatre;
	sprite_quatre.setTexture(texture_quatre);
	sf::Sprite sprite_cinq;
	sprite_cinq.setTexture(texture_cinq);
	sf::Sprite sprite_six;
	sprite_six.setTexture(texture_six);
	sf::Sprite sprite_sept;
	sprite_sept.setTexture(texture_sept);
	sf::Sprite sprite_huit;
	sprite_huit.setTexture(texture_huit);
	sf::Sprite sprite_drapeau;
	sprite_drapeau.setTexture(texture_drapeau);
	sf::Sprite sprite_boom;
	sprite_boom.setTexture(texture_boom);

	sf::Vector2f positionSprite(0, 0);


	for (int i = 0; i < (*p).get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			sf::Vector2f positionSprite(j * 20, i * 20);

			//Affichage case non découverte
			if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::close
				&& p->getCase(i, j)->m_isFlag == 0) {
				
				sprite_close.setPosition(positionSprite);
				window.draw(sprite_close);
			}

			//Affichage drapeau
			else if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::close
				&& p->getCase(i, j)->m_isFlag == 1) {

				sprite_drapeau.setPosition(positionSprite);
				window.draw(sprite_drapeau);
			}

			//affichage case découverte
			else if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::open) {


				switch (p->getCase(i, j)->m_type) {

				case Case::Type::vide:
					
					sprite_vide.setPosition(positionSprite);
					window.draw(sprite_vide);
					break;
				case Case::Type::mine:
					
					sprite_mine.setPosition(positionSprite);
					window.draw(sprite_mine);
					break;
				case Case::Type::un:
					
					sprite_un.setPosition(positionSprite);
					window.draw(sprite_un);
					break;
				case Case::Type::deux:
					
					sprite_deux.setPosition(positionSprite);
					window.draw(sprite_deux);
					break;
				case Case::Type::trois:
					
					sprite_trois.setPosition(positionSprite);
					window.draw(sprite_trois);
					break;
				case Case::Type::quatre:
					
					sprite_quatre.setPosition(positionSprite);
					window.draw(sprite_quatre);
					break;
				case Case::Type::cinq:
					
					sprite_cinq.setPosition(positionSprite);
					window.draw(sprite_cinq);
					break;
				case Case::Type::six:
					
					sprite_six.setPosition(positionSprite);
					window.draw(sprite_six);
					break;
				case Case::Type::sept:
					
					sprite_sept.setPosition(positionSprite);
					window.draw(sprite_sept);
					break;
				case Case::Type::huit:
					
					sprite_huit.setPosition(positionSprite);
					window.draw(sprite_huit);
					break;
				case Case::Type::boom:

					sprite_boom.setPosition(positionSprite);
					window.draw(sprite_boom);
					break;
				}
			}
			
		}
	}
}
void affichageMenu(sf::RenderWindow& window) {

	sf::Texture texture_textfield = loadTexture("Assets/textfield.png");
	sf::Sprite sprite_textfield;
	sprite_textfield.setTexture(texture_textfield);

	sf::Font font;
	if (!font.loadFromFile("Assets/arial.ttf"))
	{
		// erreur...
	}

	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(18);



	for (int i = 0; i < 3; i++) {
		sf::Vector2f positionSprite(150, i*40+50);
		sf::Vector2f positionText(50, i * 40 + 52);

		switch (i) {
			case 0: text.setString("Mine");
				break;
			case 1: text.setString("Largeur");
				break;
			case 2: text.setString("Hauteur");
				break;
		}

		text.setPosition(positionText);
		sprite_textfield.setPosition(positionSprite);
		window.draw(sprite_textfield);
		window.draw(text);
	}



}


sf::Texture loadTexture(std::string texture) {
	sf::Texture t;

	if (!t.loadFromFile(texture))
	{
		std::cout << "Erreur de chargement de la texture close.png\n";
	}

	return t;
}


sf::Sprite loadSpriteWithTexture(sf::Texture texture, int pos_x, int pos_y) {

	sf::Sprite sprite;

	sprite.setTexture(texture);

	return sprite;
}