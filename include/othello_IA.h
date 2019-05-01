#ifndef OTHELLO_IA_H
#define OTHELLO_IA_H

#include "include.h"

float max(float a,float b);
float min(float a,float b);

int CompteCasesVides(char* Grille);

int ValuerQuantitative(char* Grille);

int DonnetousLesCoupsValides(char* Grille,char camp,Lchaine** lcTete);

float trouvecoupsimpleQuiMaximise(char*Grille,Bestcoup* coup);

float trouvecoupsimpleQuiMinimise(char*Grille,Bestcoup* coup);

float TrouveMeilleurCoupSimple(char* Grille,char Camp,Bestcoup* coup);

float trouvecoupalphabeta(char*Grille,char camp,int prof,float alpha,float beta,Bestcoup* coup);

#endif // OTHELLO_IA_H
