#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "../Model/Plateau.h"
#include <SFML/Graphics.hpp>



int openCase(Plateau* p,int pos_x, int pos_y);
void openAllCase(Plateau* p);
void contamination(Plateau* p, int pos_x, int pos_y);
void flag(Plateau* p, int pos_x, int pos_y);

void lancerPartie(int size_x, int size_y, int mine);
void lancerJeu();
int isWin(Plateau* p);

int getMine();
int getWidth();
int getHeight();




#endif // !JEU_H_INCLUDED

