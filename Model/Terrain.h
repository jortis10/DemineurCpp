#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "case.h"

#define MAX 99

class Terrain
{

private:

	int m_size_x = 0;
	int m_size_y = 0;
	Case* cases[MAX][MAX];

public:
	Terrain(int size_x, int size_y);

	void resizeTerrain(int size_x, int size_y);
	int get_size_x();
	int get_size_y();
	Case* getCase(int i, int j);
	void initTerrain();
	void remplirTerrain(int mine);

};




#endif // !PLATEAU_H_INCLUDED





