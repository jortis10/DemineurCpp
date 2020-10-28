#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "../Model/Plateau.h"



int openCase(Plateau* p,int pos_x, int pos_y);
void openAllCase(Plateau* p);
void contamination(Plateau* p, int pos_x, int pos_y);
void flag(Plateau* p, int pos_x, int pos_y);

void lancerPartie(int size_x, int size_y, int mine);
int isWin(Plateau* p);




#endif // !JEU_H_INCLUDED

