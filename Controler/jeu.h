#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "../Model/Terrain.h"
#include <SFML/Graphics.hpp>



int openCase(Terrain* p,int pos_x, int pos_y);
void openAllCase(Terrain* p);
void contamination(Terrain* p, int pos_x, int pos_y);
bool contaminationPossible(Terrain* p, int pos_x, int pos_y);
void flag(Terrain* p, int pos_x, int pos_y);

void lancerPartie(int width, int height, int mine);
void lancerJeu();
int isWin(Terrain* p);
int possibleBombLeft(Terrain* p, int mine);


#endif // !JEU_H_INCLUDED

