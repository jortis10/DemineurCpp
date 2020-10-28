#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "case.h"

#define MINE 0.1
#define MAX 99


class Plateau
{

private:

	int m_size_x = 0;
	int m_size_y = 0;
	Case* cases[MAX][MAX];


public:
	Plateau(int size_x, int size_y);
	~Plateau();

	void resizePlateau(int size_x, int size_y);
	int get_size_x();
	int get_size_y();
	Case* getCase(int i, int j);
	void initPlateau();
	void remplirPlateau(int mine);

};




#endif // !PLATEAU_H_INCLUDED





