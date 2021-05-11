#include <random>
#include <functional>
#include <chrono>

#include "Terrain.h"
#include "Case.h"


Terrain::Terrain(int size_x, int size_y) {

	m_size_x = size_x;
	m_size_y = size_y;

	this->initTerrain();
}

void Terrain::resizeTerrain(int size_x, int size_y)
{
	m_size_x = size_x;
	m_size_y = size_y;

}

int Terrain::get_size_x() {
	return m_size_x;
}
int Terrain::get_size_y() {
	return m_size_y;
}
Case* Terrain::getCase(int i,int j) {
	return cases[i][j];

}
void Terrain::initTerrain() {

	for (int i = 0; i < m_size_y; i++)
	{
		for (int j = 0; j < m_size_x; j++)
		{
			cases[i][j] = new Case(Case::Type::vide, Case::State::close,0);
		}
	}
}
void Terrain::remplirTerrain(int mine) {

	/*Génération de l'aléatoire*/
	std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine rez(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distrib_x{ 0, m_size_x - 1 };
	std::uniform_int_distribution<int> distrib_y{ 0, m_size_y - 1 };

	auto rd_x = bind(distrib_x, re);
	auto rd_y = bind(distrib_y, rez);
	
	/*Génération du plateau avec case vide*/

	for (int i = 0; i < m_size_y; i++) {
		for (int j = 0; j < m_size_x; j++) {
			cases[i][j]->modifyCase(Case::Type::vide, Case::State::close,0);
		}
	}
		
	/*Génération des mines*/
	int i = 0;
	while(i < (mine)){
		int x = rd_x();
		int y = rd_y();

		if (cases[y][x]->m_type == Case::Type::vide) {
			cases[y][x]->modifyCase(Case::Type::mine, Case::State::close,0);
			i++;
		}
			
	}
	/*Génération des chiffres autours des mines*/
	int count = 0;
	for (int i = 0; i < m_size_y; i++) {
		for (int j = 0; j < m_size_x; j++) {

			count = 0;

			if (cases[i][j]->m_type != Case::Type::mine) {

				/*Haut gauche*/
				if (i > 0 && j > 0 && cases[i - 1][j - 1]->m_type == Case::Type::mine)
					count += 1;
				/*Haut*/
				if (i > 0 && cases[i - 1][j]->m_type == Case::Type::mine)
					count += 1;
				/*Haut droite*/
				if (i > 0 && j < m_size_x - 1 && cases[i - 1][j + 1]->m_type == Case::Type::mine)
					count += 1;
				/*Droite*/
				if (j < m_size_x - 1 && cases[i][j + 1]->m_type == Case::Type::mine)
					count += 1;
				/*Bas droite*/
				if (i < m_size_y - 1 && j < m_size_x - 1 &&  cases[i + 1][j + 1]->m_type == Case::Type::mine)
					count += 1;
				/*Bas*/
				if (i < m_size_y - 1 && cases[i + 1][j]->m_type == Case::Type::mine)
					count += 1;
				/*Bas gauche*/
				if (i < m_size_y - 1 && j > 0 && cases[i + 1][j - 1]->m_type == Case::Type::mine)
					count += 1;
				/*Gauche*/
				if (j > 0 && cases[i][j - 1]->m_type == Case::Type::mine)
					count += 1;


				switch (count)
				{
					case 1: cases[i][j]->m_type = Case::Type::un;
						break;
					case 2: cases[i][j]->m_type = Case::Type::deux;
						break;
					case 3: cases[i][j]->m_type = Case::Type::trois;
						break;
					case 4: cases[i][j]->m_type = Case::Type::quatre;
						break;
					case 5: cases[i][j]->m_type = Case::Type::cinq;
						break;
					case 6: cases[i][j]->m_type = Case::Type::six;	
						break;
					case 7: cases[i][j]->m_type = Case::Type::sept;
						break;
					case 8: cases[i][j]->m_type = Case::Type::huit;
						break;
					case 0: cases[i][j]->m_type = Case::Type::vide;
						break;
				}
			}
		}
	}

}





