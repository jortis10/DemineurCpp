#include "AffichageSFML.h"
#include "../Model/Terrain.h"

View::View() {

	/*Assignement des texture*/
	texture_close = loadTexture("Assets/close.png");
	texture_vide = loadTexture("Assets/vide.png");
	texture_mine = loadTexture("Assets/mine.png");
	texture_un = loadTexture("Assets/un.png");
	texture_deux = loadTexture("Assets/deux.png");
	texture_trois = loadTexture("Assets/trois.png");
	texture_quatre = loadTexture("Assets/quatre.png");
	texture_cinq = loadTexture("Assets/cinq.png");
	texture_six = loadTexture("Assets/six.png");
	texture_sept = loadTexture("Assets/sept.png");
	texture_huit = loadTexture("Assets/huit.png");
	texture_drapeau = loadTexture("Assets/drapeau.png");
	texture_boom = loadTexture("Assets/boom.png");

	/*Sprite*/
	sprite_close.setTexture(texture_close);
	sprite_close.scale(SCALE, SCALE);
	sprite_vide.setTexture(texture_vide);
	sprite_vide.scale(SCALE, SCALE);
	sprite_mine.setTexture(texture_mine);
	sprite_mine.scale(SCALE, SCALE);
	sprite_un.setTexture(texture_un);
	sprite_un.scale(SCALE, SCALE);
	sprite_deux.setTexture(texture_deux);
	sprite_deux.scale(SCALE, SCALE);
	sprite_trois.setTexture(texture_trois);
	sprite_trois.scale(SCALE, SCALE);
	sprite_quatre.setTexture(texture_quatre);
	sprite_quatre.scale(SCALE, SCALE);
	sprite_cinq.setTexture(texture_cinq);
	sprite_cinq.scale(SCALE, SCALE);
	sprite_six.setTexture(texture_six);
	sprite_six.scale(SCALE, SCALE);
	sprite_sept.setTexture(texture_sept);
	sprite_sept.scale(SCALE, SCALE);
	sprite_huit.setTexture(texture_huit);
	sprite_huit.scale(SCALE, SCALE);
	sprite_drapeau.setTexture(texture_drapeau);
	sprite_drapeau.scale(SCALE, SCALE);
	sprite_boom.setTexture(texture_boom);
	sprite_boom.scale(SCALE, SCALE);

}


void afficherTerrainSFML(View* view, Terrain* p, sf::RenderWindow& window, bool pressed) {

	


	for (int i = 0; i < p->get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			sf::Vector2f positionSprite(j * 25, i * 25);

			if (pressed == true) {
				switch (p->getCase(i, j)->m_type) {

				case Case::Type::vide:

					view->sprite_vide.setPosition(positionSprite);
					window.draw(view->sprite_vide);
					break;
				case Case::Type::mine:

					view->sprite_mine.setPosition(positionSprite);
					window.draw(view->sprite_mine);
					break;
				case Case::Type::un:

					view->sprite_un.setPosition(positionSprite);
					window.draw(view->sprite_un);
					break;
				case Case::Type::deux:

					view->sprite_deux.setPosition(positionSprite);
					window.draw(view->sprite_deux);
					break;
				case Case::Type::trois:

					view->sprite_trois.setPosition(positionSprite);
					window.draw(view->sprite_trois);
					break;
				case Case::Type::quatre:

					view->sprite_quatre.setPosition(positionSprite);
					window.draw(view->sprite_quatre);
					break;
				case Case::Type::cinq:

					view->sprite_cinq.setPosition(positionSprite);
					window.draw(view->sprite_cinq);
					break;
				case Case::Type::six:

					view->sprite_six.setPosition(positionSprite);
					window.draw(view->sprite_six);
					break;
				case Case::Type::sept:

					view->sprite_sept.setPosition(positionSprite);
					window.draw(view->sprite_sept);
					break;
				case Case::Type::huit:

					view->sprite_huit.setPosition(positionSprite);
					window.draw(view->sprite_huit);
					break;
				case Case::Type::boom:

					view->sprite_boom.setPosition(positionSprite);
					window.draw(view->sprite_boom);
					break;
				}
			}


			if (p->getCase(i, j)->m_refresh = true) {

				//Affichage case non découverte
				if (p->getCase(i, j)->m_state == Case::State::close
					&& p->getCase(i, j)->m_isFlag == 0
					&& !pressed) {


					view->sprite_close.setPosition(positionSprite);
					window.draw(view->sprite_close);
				}

				//Affichage drapeau
				else if (p->getCase(i, j)->m_state == Case::State::close
					&& p->getCase(i, j)->m_isFlag == 1
					&& !pressed) {

					view->sprite_drapeau.setPosition(positionSprite);
					window.draw(view->sprite_drapeau);
				}

				//affichage case découverte
				else if ((p->getCase(i, j)->m_state == Case::State::open)
					&& !pressed) {

					switch (p->getCase(i, j)->m_type) {

					case Case::Type::vide:

						view->sprite_vide.setPosition(positionSprite);
						window.draw(view->sprite_vide);
						break;
					case Case::Type::mine:

						view->sprite_mine.setPosition(positionSprite);
						window.draw(view->sprite_mine);
						break;
					case Case::Type::un:

						view->sprite_un.setPosition(positionSprite);
						window.draw(view->sprite_un);
						break;
					case Case::Type::deux:

						view->sprite_deux.setPosition(positionSprite);
						window.draw(view->sprite_deux);
						break;
					case Case::Type::trois:

						view->sprite_trois.setPosition(positionSprite);
						window.draw(view->sprite_trois);
						break;
					case Case::Type::quatre:

						view->sprite_quatre.setPosition(positionSprite);
						window.draw(view->sprite_quatre);
						break;
					case Case::Type::cinq:

						view->sprite_cinq.setPosition(positionSprite);
						window.draw(view->sprite_cinq);
						break;
					case Case::Type::six:

						view->sprite_six.setPosition(positionSprite);
						window.draw(view->sprite_six);
						break;
					case Case::Type::sept:

						view->sprite_sept.setPosition(positionSprite);
						window.draw(view->sprite_sept);
						break;
					case Case::Type::huit:

						view->sprite_huit.setPosition(positionSprite);
						window.draw(view->sprite_huit);
						break;
					case Case::Type::boom:

						view->sprite_boom.setPosition(positionSprite);
						window.draw(view->sprite_boom);
						break;
					}
				}

				p->getCase(i, j)->m_refresh = false;
			}
			
		}
	}
}




sf::Texture loadTexture(std::string texture) {
	sf::Texture t;

	if (!t.loadFromFile(texture))
	{
		//Erreur
	}

	return t;
}

void setIcon(sf::RenderWindow& window) {
	sf::Image icon;
	icon.loadFromFile("Assets/mine.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}