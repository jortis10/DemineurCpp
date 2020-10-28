
#include <iostream>

#include "Affichage.h"
#include "../Model/Plateau.h"
#include "../Model/Case.h"
#include "ConsoleColor.h"
#include "setcolor_manip.h"


void afficherPlateau(Plateau* p) {
	system("cls");
	unsigned short oldAttr = getConsoleColor();

	std::cout << "   ";
	for (int k = 0; k < p->get_size_x(); k++) {
		if (k > 9)
			std::cout << k << "";
		else
			std::cout << k << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < (*p).get_size_y(); i++) {

		if (i > 9)
			std::cout << i << " ";
		else
			std::cout << i << "  ";


		for (int j = 0; j < p->get_size_x(); j++) {


			if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::open) {

				switch (p->getCase(i, j)->m_type) {

				case Case::Type::vide:
					std::cout << setcolor(0x77) << "0 ";
					break;
				case Case::Type::mine:
					std::cout << setcolor(0x44) << "X ";
					break;
				case Case::Type::un:
					std::cout << setcolor(0x71) << "1 ";
					break;
				case Case::Type::deux:
					std::cout << setcolor(0x72) << "2 ";
					break;
				case Case::Type::trois:
					std::cout << setcolor(0x74) << "3 ";
					break;
				case Case::Type::quatre:
					std::cout << setcolor(0x75) << "4 ";
					break;
				case Case::Type::cinq:
					std::cout << setcolor(0x76) << "5 ";
					break;
				case Case::Type::six:
					std::cout << setcolor(0x73) << "6 ";
					break;
				case Case::Type::sept:
					std::cout << setcolor(0x78) << "7 ";
					break;
				case Case::Type::huit:
					std::cout << setcolor(0x79) << "8 ";
					break;
				}
			}
			else if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::close
				&& p->getCase(i, j)->m_isFlag == 0)

				std::cout << setcolor(0x21) << "0 ";

			else if (p->getCase(i, j)->m_pos_x == j
				&& p->getCase(i, j)->m_pos_y == i
				&& p->getCase(i, j)->m_state == Case::State::close
				&& p->getCase(i, j)->m_isFlag == 1)

				std::cout << setcolor(0x44) << "F ";
		}
		std::cout << "\n";

		setConsoleColor(oldAttr);
	}
}
