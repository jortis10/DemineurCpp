#include <iostream>
#include "jeu.h"
#include "../Model/Plateau.h"
#include "../Model/Case.h"
#include "../View/Affichage.h"
#include "../View/AffichageSFML.h"



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

void lancerPartie(int size_x, int size_y, float mine) {

	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(size_x*20, size_y*20), "Demineur");

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

		afficherPlateauSFML(plateau, window);
		window.display();

		if (isWin(plateau) == 0 && state != -1) {

			//JEU

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{

					flag(plateau, event.mouseButton.x/20, event.mouseButton.y/20);


					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					state = openCase(plateau, event.mouseButton.x/20 , event.mouseButton.y/20);
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}


			afficherPlateauSFML(plateau, window);

		}

		if (isWin(plateau) == 1 && state == 0) {
			std::cout << "Vous avez gagné !!!\n";
			state = 1;
			// while pas clic souris

			/*if (event.type == sf::Event::MouseButtonPressed)
			{
				break;
			}*/

		}
		else if (state == -1) {
			state = 1;
			std::cout << "BOOOOOOOMMMM!!! Vous avez perdu\n";
			/*
			//break;
			if (event.type == sf::Event::MouseButtonPressed)
			{
				break;
			}*/
		}

	}
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