#include "../include/othello_IA.h"
#include "../include/include.h"

int NBCOUPS_JOUES;

float max(float a,float b)
{
	if (a > b)
		return a;
	else
		return b;
}

float min(float a,float b)
{
	if (a < b)
		return a;
	else
		return b;
}

/* retourne le nombre de cases vides dans Grille*/
int CompteCasesVides(char *Grille)
{
	return ((Dimmax * Dimmax) -  NBCOUPS_JOUES);
}

int ValuerQuantitative(char *Grille)
{
	int NbpionsX,NbpionsO;

	ComptePions(Grille , &NbpionsX , &NbpionsO);
	return (NbpionsX - NbpionsO);
}

/*  C'est notre fonction isValidMove  */

/*cette fonction rescence tous les coups valides pour le camp (camp)dans une liste chainee dont chaque maillon contient un coup*/
int DonnetousLesCoupsValides(char *Grille,char camp,Lchaine** lcTete)
{
	int ievalue = 1;
	char jevalue;
	int compteur = 0;
	Lchaine* lc;
	(*lcTete) = NULL;

	while (ievalue <= Dimmax)
	{
		for (jevalue = 'a'; (jevalue  < (Dimmax + 'a'));jevalue++)
		{
			if (coupValide(Grille,camp,ievalue,jevalue)== 1)
			{
				compteur++;
				lc = (Lchaine*)malloc(sizeof(Lchaine));
				(lc-> coup).pion = camp;
				(lc-> coup).Numligne = ievalue;
				(lc->coup).Nomcolonne = jevalue;
				/* printf(" coup valide trouv� pour %c : (%c,%d) evalu� � : %d \n",camp,jevalue,ievalue,(lc->evaluation));*/
				lc->suivant= *lcTete;
				(*lcTete)= lc;
			}
		}
		ievalue++;
	}
	return compteur;
}

float trouvecoupsimpleQuiMaximise(char *Grille,Bestcoup* coup)
{
	Lchaine*  maliste;
	char *Grilledeteste;
	int i;
	float eval = -FLT_MAX,eval_temp;
	Lchaine* lc;

	int Nbcoupsvalides = DonnetousLesCoupsValides(Grille,'X',&maliste);
	for (i = 1;i<= Nbcoupsvalides;i++)
	{
		Grilledeteste= (char*) malloc((Dimmax * Dimmax * sizeof(char)));
		recopieGrille(Grilledeteste,Grille);
		JoueLeCoup(&Grilledeteste,((maliste->coup).Numligne),((maliste->coup).Nomcolonne),'X');
		eval_temp = evalue(Grilledeteste);
		if(eval_temp > eval)
		{
			coup->Numligne = (maliste ->coup).Numligne;
			coup->Nomcolonne = (maliste -> coup).Nomcolonne;
			eval = eval_temp;
		}
		lc= maliste;
		maliste = maliste -> suivant;
		free(lc);
		free(Grilledeteste);
	}
	free(maliste);
	return eval;
}

float trouvecoupsimpleQuiMinimise(char *Grille,Bestcoup* coup)
{
	char *Grilledeteste;
	Lchaine*  maliste;
	Lchaine* lc;
	int i;
	float eval = FLT_MAX,eval_temp;

	int Nbcoupsvalides = DonnetousLesCoupsValides(Grille,'O',&maliste);
	for (i = 1;i<= Nbcoupsvalides;i++)
	{
		Grilledeteste= (char*) malloc((Dimmax * Dimmax * sizeof(char)));
		recopieGrille(Grilledeteste,Grille);
		JoueLeCoup(&Grilledeteste,(maliste->coup.Numligne),(maliste->coup.Nomcolonne),'O');
		eval_temp = evalue(Grilledeteste);
		if(eval_temp < eval)
		{
			coup -> Numligne = maliste ->coup.Numligne;
			coup -> Nomcolonne = maliste ->coup.Nomcolonne;
			eval = eval_temp;
		}
		lc= maliste;
		maliste = maliste -> suivant;
		free(lc);
		free(Grilledeteste);
	}
	free(maliste);
	return eval;
}

float TrouveMeilleurCoupSimple(char *Grille,char Camp,Bestcoup* coup)
{
	if(Camp == 'X')
	return  (trouvecoupsimpleQuiMaximise(Grille,coup));
	else
	return  (trouvecoupsimpleQuiMinimise(Grille,coup));
}


float trouvecoupalphabeta(char *Grille,char camp,int prof,float alpha,float beta,Bestcoup* coup)
{
	Lchaine* maliste;
	Lchaine* lc;
	char *Grilledeteste;
	int i, Nbcoupsvalides;
	Bestcoup coup_fils;
	float new_alpha,new_beta,eval,eval_temp;

	if(existeCoupPourCamp(Grille ,camp)== 1)
	{
		if(prof == 1)
		{
			eval =  (TrouveMeilleurCoupSimple(Grille, camp,coup));
			return eval;
		}
		else
		{
			new_alpha = -FLT_MAX;
			new_beta = FLT_MAX;
			if(camp == 'X')
			{
				Nbcoupsvalides = DonnetousLesCoupsValides(Grille,'X',&maliste);
				for (i = 1;i<= Nbcoupsvalides;i++)
				{
					Grilledeteste= (char*) malloc((Dimmax * Dimmax * sizeof(char)));
					recopieGrille(Grilledeteste,Grille);

					JoueLeCoup(&Grilledeteste,(maliste->coup.Numligne),(maliste->coup.Nomcolonne),camp);
					eval_temp = (trouvecoupalphabeta(Grilledeteste,(adverse(camp)),(prof - 1),(max(alpha,new_alpha)),beta,&coup_fils));
					if(eval_temp > new_alpha)

					{
						new_alpha = eval_temp;
						coup -> Numligne = maliste->coup.Numligne;
						coup -> Nomcolonne = maliste->coup.Nomcolonne;
					}
					if(new_alpha > beta)/*coupe alpha*/
					{
						free(maliste);
						free(Grilledeteste);
						break;
					}
					else
					{

						lc= maliste;
						maliste = (maliste->suivant);
						free(lc);
						free(Grilledeteste);
					}
				}
				return new_alpha;
			}
			else
			{
				Nbcoupsvalides = DonnetousLesCoupsValides(Grille,'O',&maliste);
				for (i = 1;i<= Nbcoupsvalides;i++)
				{
					Grilledeteste= (char*) malloc((Dimmax * Dimmax * sizeof(char)));
					recopieGrille(Grilledeteste,Grille);

					JoueLeCoup(&Grilledeteste,(maliste->coup.Numligne),(maliste->coup.Nomcolonne),camp);
					eval_temp = (trouvecoupalphabeta(Grilledeteste,(adverse(camp)),(prof - 1),alpha,(min(new_beta,beta)),&coup_fils));
					if(eval_temp < new_beta)
					{
						new_beta = eval_temp;
						coup -> Numligne = maliste->coup.Numligne;
						coup -> Nomcolonne = maliste->coup.Nomcolonne;
					}
					if(alpha > new_beta)/*coupe beta*/
					{
						free(maliste);
						free(Grilledeteste);
						break;
					}
					else
					{

						lc= maliste;
						maliste = (maliste->suivant);
						free(lc);
						free(Grilledeteste);
					}
				}
				return new_beta;
			}
		}
	}
	else
	{
		eval = evalue(Grille);
		return eval;
	}
}
