#include <TGUI/TGUI.hpp>
#include <iostream>

#include "jeu.h"
#include "../Model/Terrain.h"
#include "../View/AffichageSFML.h"

void lancerJeu() {

	int width,height,mine;
	sf::String select;

	sf::RenderWindow menu(sf::VideoMode(370, 200), "Demineur", sf::Style::Close);
	setIcon(menu);
	menu.setFramerateLimit(30);
	tgui::Gui gui{ menu };

	gui.loadWidgetsFromFile("Assets/menu.txt");

	tgui::Button::Ptr button = gui.get<tgui::Button>("button");
	tgui::ComboBox::Ptr select_diff = gui.get<tgui::ComboBox>("select_diff");

	select_diff->setSelectedItem("Normale");


	button->connect("pressed", [&]() {
		if (!select.isEmpty()) {

			if (select == "Facile") {
				mine = 10;
				width = 8;
				height = 11;

			}
			else if (select == "Normale") {
				mine = 39;
				width = 14;
				height = 20;

			}
			else if (select == "Difficile") {
				mine = 102;
				width = 20;
				height = 29;

			}
			else if (select == "Expert") {
				mine = 230;
				width = 26;
				height = 38;

			}

			menu.close();
			lancerPartie(width, height, mine);
		}
	});

	while (menu.isOpen())
	{
		menu.clear(sf::Color::White);

		select = select_diff->getSelectedItem();

		sf::Event event_menu;
		while (menu.pollEvent(event_menu))
		{
			if (event_menu.type == sf::Event::Closed)
				menu.close();
			gui.handleEvent(event_menu);
		}

	
		gui.draw();
		menu.display();
	}

}
void lancerPartie(int width, int height, int mine) {

	Terrain* terrain = new Terrain(width, height);
	int state = 0;
	int i = 0;

	terrain->remplirTerrain(mine);

	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(width * 25, height * 25), "Demineur", sf::Style::Close);
	window.setFramerateLimit(120);

	setIcon(window);

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);

		/*JEU*/
			if (isWin(terrain) == 0 && state != -1) {
				i++;
				window.setTitle("Bombe restante : "+std::to_string(possibleBombLeft(terrain,mine)));

				//JEU

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right) {
							flag(terrain, event.mouseButton.x / 25, event.mouseButton.y / 25);
							sf::sleep(sf::milliseconds(100));
					}
					else if (event.mouseButton.button == sf::Mouse::Left)
						state = openCase(terrain, event.mouseButton.x / 25, event.mouseButton.y / 25);
				}
			}

			//Condition de fin de partie
			else if (isWin(terrain) == 1 && state != -1) { //si win
				window.setTitle("WIN");

				//Jouer un son

				state = 2;
			}
			else if (state == -1) { //si loose
				window.setTitle("BOOOOOOOOOM");

				//Jouer un son

				state = 2;
			}
			if (state == 2)
			{
				sf::sleep(sf::seconds(5));

				window.close();
				lancerJeu();
			}
		
		afficherTerrainSFML(terrain, window);
		window.display();
	}
}
int openCase(Terrain* p,int pos_x,int pos_y) {

	if (p->getCase(pos_y, pos_x)->m_type == Case::Type::mine && p->getCase(pos_y, pos_x)->m_state == Case::State::close) {
		p->getCase(pos_y, pos_x)->m_type = Case::Type::boom;
		openAllCase(p);
		return -1;
	}
	else if (p->getCase(pos_y, pos_x)->m_type == Case::Type::vide && p->getCase(pos_y, pos_x)->m_state == Case::State::close) {
		p->getCase(pos_y, pos_x)->m_state = Case::State::open;
		contamination(p, pos_x,pos_y);
		return 1;
	}
	else {
		p->getCase(pos_y, pos_x)->m_state = Case::State::open;
		p->getCase(pos_y, pos_x)->m_isFlag = 0;
		return 0;
	}
}

void openAllCase(Terrain* p) {

	for (int i = 0; i < p->get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			p->getCase(i, j)->m_state = Case::State::open;

		}
	}
}

void contamination(Terrain* p, int pos_x, int pos_y) {

	//Haut gauche
	if (pos_y > 0
		&& pos_x > 0
		&& contaminationPossible(p,pos_x-1,pos_y-1))
		openCase(p, pos_x - 1, pos_y - 1);

	//Haut
	if (pos_y > 0 
		&& contaminationPossible(p, pos_x, pos_y - 1))
		openCase(p, pos_x, pos_y - 1);

	//Haut droite
	if (pos_y > 0
		&& pos_x < p->get_size_x() - 1
		&& contaminationPossible(p, pos_x + 1, pos_y - 1))
		openCase(p, pos_x + 1, pos_y - 1);

	//Droite
	if (pos_x < p->get_size_x() - 1
		&& contaminationPossible(p, pos_x + 1, pos_y))
		openCase(p, pos_x + 1, pos_y);
	
	//Bas droite
	if (pos_y < p->get_size_y() - 1
		&& pos_x < p->get_size_x() - 1
		&& contaminationPossible(p, pos_x + 1, pos_y + 1))
		openCase(p, pos_x + 1, pos_y + 1);

	//Bas
	if (pos_y < p->get_size_y()-1 
		&& contaminationPossible(p, pos_x, pos_y + 1))
		openCase(p, pos_x, pos_y + 1);

	//Bas gauche
	if (pos_y < p->get_size_y() - 1
		&& pos_x > 0
		&& contaminationPossible(p, pos_x - 1, pos_y + 1))
		openCase(p, pos_x - 1, pos_y + 1);

	//Gauche
	if (pos_x > 0 
		&& contaminationPossible(p, pos_x - 1, pos_y))
		openCase(p, pos_x - 1, pos_y);

}
int isWin(Terrain* p) {

	int caseLeft = 0;

	for (int i = 0; i < p->get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			if (p->getCase(i, j)->m_state == Case::State::close && p->getCase(i, j)->m_type != Case::Type::mine)
				caseLeft++;
		}
	}

	if (caseLeft == 0) {
		return 1;
	}

	return 0;
}

int possibleBombLeft(Terrain* p, int mine) {

	int bombLeft = 0;

	for (int i = 0; i < p->get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			if (p->getCase(i, j)->m_isFlag == 1)
				bombLeft++;
		}
	}

	if (bombLeft > mine) {
		return 0;
	}

	return mine-bombLeft;
}

void flag(Terrain* p, int pos_x, int pos_y) {

	if(p->getCase(pos_y, pos_x)->m_isFlag == 0)
		p->getCase(pos_y, pos_x)->m_isFlag = 1;
	else
		p->getCase(pos_y, pos_x)->m_isFlag = 0;

}

bool contaminationPossible(Terrain* p,int pos_x,int pos_y) {

	if ((p->getCase(pos_y, pos_x)->m_type == Case::Type::vide
		|| p->getCase(pos_y, pos_x)->m_type == Case::Type::un
		|| p->getCase(pos_y, pos_x)->m_type == Case::Type::deux
		|| p->getCase(pos_y, pos_x)->m_type == Case::Type::trois
		|| p->getCase(pos_y, pos_x)->m_type == Case::Type::quatre)
		&& p->getCase(pos_y, pos_x)->m_state == Case::State::close)
		return true;
	else
		return false;



}
