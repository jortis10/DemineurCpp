#include <iostream>
#include <fstream>
#include <string>
#include "jeu.h"
#include <TGUI/TGUI.hpp>
#include "../Model/Plateau.h"
#include "../Model/Case.h"
#include "../View/Affichage.h"
#include "../View/AffichageSFML.h"





void lancerJeu() {

	int width = 30, height = 30;
	int mine = 4;

	sf::RenderWindow menu(sf::VideoMode(370, 200), "Demineur");
	menu.setFramerateLimit(60);
	tgui::Gui gui{ menu };

	sf::String select;

	sf::Image icon;



	icon.loadFromFile("Assets/mine.png");
	menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	gui.loadWidgetsFromFile("Assets/menu.txt");

	
	tgui::Button::Ptr button = gui.get<tgui::Button>("button");
	tgui::ComboBox::Ptr select_diff = gui.get<tgui::ComboBox>("select_diff");

	select_diff->setSelectedItem("Normale");

	

	button->connect("pressed", [&]() {
		if (!select.isEmpty()) {

			if (select == "Facile") {
				mine = 20;
				width = 10;
				height = 10;

			}
			else if (select == "Normale") {
				mine = 70;
				width = 20;
				height = 20;

			}
			else if (select == "Difficile") {
				mine = 150;
				width = 30;
				height = 30;

			}
			else if (select == "Expert") {
				mine = 250;
				width = 40;
				height = 40;

			}
			else if (select == "Armageddon") {
				mine = 600;
				width = 50;
				height = 50;

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
		gui.get("height_box");
	
		menu.display();
	}

}
void lancerPartie(int size_x, int size_y, int mine) {

	// création de la fenêtre


	sf::RenderWindow window(sf::VideoMode(size_x * 20, size_y * 20), "Demineur");
	window.setFramerateLimit(30);
	sf::Image icon;

	icon.loadFromFile("Assets/mine.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	Plateau* plateau = new Plateau(size_x, size_y);

	int state = 0, x = 0, y = 0;
	char flags = 'x';

	plateau->remplirPlateau(mine);

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
			if (isWin(plateau) == 0 && state != -1) {

				//JEU

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
						flag(plateau, event.mouseButton.x / 20, event.mouseButton.y / 20);
					else if (event.mouseButton.button == sf::Mouse::Left)
						state = openCase(plateau, event.mouseButton.x / 20, event.mouseButton.y / 20);
				}
			}

			//Condition de fin de partie
			else if (isWin(plateau) == 1 && state != -1) { //si win
				window.setTitle("WIN");

				//Jouer un son

				state = 2;
			}
			else if (state == -1) { //si loose
				window.setTitle("BOOOOOOOOOM");

				//Jouer un son

				state = 2;
			}
			afficherPlateauSFML(plateau, window);
		

		//afficherPlateauSFML(plateau, window);
		window.display();


		if (state == 2)
		{
			sf::sleep(sf::seconds(5));
			window.close();
			lancerJeu();
		}
	}
}
int openCase(Plateau* p,int pos_x,int pos_y) {

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
		return 0;

	}
}

void openAllCase(Plateau* p) {

	for (int i = 0; i < p->get_size_y(); i++) {
		for (int j = 0; j < p->get_size_x(); j++) {

			p->getCase(i, j)->m_state = Case::State::open;

		}
	}
}

void contamination(Plateau* p, int pos_x, int pos_y) {
	//Haut
	if (pos_y > 0 
		&& (p->getCase(pos_y - 1 , pos_x)->m_type == Case::Type::vide 
			|| p->getCase(pos_y - 1, pos_x)->m_type == Case::Type::un
			|| p->getCase(pos_y - 1, pos_x)->m_type == Case::Type::deux
			|| p->getCase(pos_y - 1, pos_x)->m_type == Case::Type::trois
			|| p->getCase(pos_y - 1, pos_x)->m_type == Case::Type::quatre)
		&& p->getCase(pos_y - 1, pos_x)->m_state == Case::State::close)
		openCase(p, pos_x, pos_y - 1);
	

	//Bas
	if (pos_y < p->get_size_y()-1 
		&& (p->getCase(pos_y+1, pos_x)->m_type == Case::Type::vide 
			|| p->getCase(pos_y + 1, pos_x)->m_type == Case::Type::un
			|| p->getCase(pos_y + 1, pos_x)->m_type == Case::Type::deux
			|| p->getCase(pos_y + 1, pos_x)->m_type == Case::Type::trois
			|| p->getCase(pos_y + 1, pos_x)->m_type == Case::Type::quatre)
		&& p->getCase(pos_y+1, pos_x)->m_state == Case::State::close)
		openCase(p, pos_x, pos_y + 1);

	//Gauche
	if (pos_x > 0 
		&& (p->getCase(pos_y, pos_x-1)->m_type == Case::Type::vide 
			|| p->getCase(pos_y, pos_x - 1)->m_type == Case::Type::un
			|| p->getCase(pos_y, pos_x - 1)->m_type == Case::Type::deux
			|| p->getCase(pos_y, pos_x - 1)->m_type == Case::Type::trois
			|| p->getCase(pos_y, pos_x - 1)->m_type == Case::Type::quatre)
		&& p->getCase(pos_y, pos_x-1)->m_state == Case::State::close)
		openCase(p, pos_x - 1, pos_y);

	//Droite
	if (pos_x < p->get_size_x() -1
		&& (p->getCase(pos_y, pos_x+1)->m_type == Case::Type::vide 
			|| p->getCase(pos_y, pos_x + 1)->m_type == Case::Type::un
			|| p->getCase(pos_y, pos_x + 1)->m_type == Case::Type::deux
			|| p->getCase(pos_y, pos_x + 1)->m_type == Case::Type::trois
			|| p->getCase(pos_y, pos_x + 1)->m_type == Case::Type::quatre)
		&& p->getCase(pos_y, pos_x+1)->m_state == Case::State::close)
		openCase(p, pos_x + 1, pos_y);


}
int isWin(Plateau* p) {

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

void flag(Plateau* p, int pos_x, int pos_y) {

	p->getCase(pos_y, pos_x)->m_isFlag = 1;

}
int getMine() {
	std::ifstream config("../config.txt");

	int mine = 0, i=0;
	std::string ligne;

	if (config)
	{
		while (std::getline(config, ligne)) {
			if (i == 0) {
				mine = std::stoi(ligne);
			}

			i++;
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}

	config.close();
	return mine;
}
int getWidth() {

	int width=0,i=0;

	std::ifstream config("C:/Users/Thiba/Desktop/Demineurcpp/config.txt");
	std::string ligne;

	if (config)
	{
		while (std::getline(config, ligne)) {
			if (i == 1) {
				width = std::stoi(ligne);
			}

			i++;
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}

	config.close();
	return width;
}

int getHeight() {

	int height=0,i = 0;

	std::ifstream config("config.txt");
	std::string ligne;

	if (config)
	{
		while (std::getline(config, ligne)) {
			if (i == 2) {
				height = std::stoi(ligne);
			}

			i++;
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}

	config.close();
	return height;
}

