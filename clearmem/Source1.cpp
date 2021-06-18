#include "clearmem.h"

/* @param a,b,c,d : переменные для сравнения карточек*/
int a = -1, b = -1, c = -1, d = -1;
bool o = 1;/**<доп.параметр для различающихся карточек*/


void CHEECK(sf::String sml_t[4], sf::String tabl[4], sf::String tabl_m[4]) {
	if (sml_t[a][b] == sml_t[c][d]) /*условие идентичности карточек*/
	{
		/*незакрывание идентичных персонажей */
		if (tabl[a][b] == 'a') tabl[a][b] = 'A';
		if (tabl[a][b] == 'b') tabl[a][b] = 'B';
		if (tabl[a][b] == 'c') tabl[a][b] = 'C';
		if (tabl[a][b] == 'y') tabl[a][b] = 'Y';
		if (tabl[a][b] == 'l') tabl[a][b] = 'L';
		if (tabl[a][b] == 'k') tabl[a][b] = 'K';
		if (tabl[c][d] == 'a') tabl[c][d] = 'A';
		if (tabl[c][d] == 'b') tabl[c][d] = 'B';
		if (tabl[c][d] == 'c') tabl[c][d] = 'C';
		if (tabl[c][d] == 'y') tabl[c][d] = 'Y';
		if (tabl[c][d] == 'l') tabl[c][d] = 'L';
		if (tabl[c][d] == 'k') tabl[c][d] = 'K';
	}
	else { /*условие различности персонажей*/
		if (o == 1) { /*условие открытия различных карточек*/
			if (tabl[a][b] == 'a') tabl[a][b] = 'A';
			if (tabl[a][b] == 'b') tabl[a][b] = 'B';
			if (tabl[a][b] == 'c') tabl[a][b] = 'C';
			if (tabl[a][b] == 'y') tabl[a][b] = 'Y';
			if (tabl[a][b] == 'l') tabl[a][b] = 'L';
			if (tabl[a][b] == 'k') tabl[a][b] = 'K';
			if (tabl[c][d] == 'a') tabl[c][d] = 'A';
			if (tabl[c][d] == 'b') tabl[c][d] = 'B';
			if (tabl[c][d] == 'c') tabl[c][d] = 'C';
			if (tabl[c][d] == 'y') tabl[c][d] = 'Y';
			if (tabl[c][d] == 'l') tabl[c][d] = 'L';
			if (tabl[c][d] == 'k') tabl[c][d] = 'K';
			o = 0;
		}
		else { /*условие закрытия различных карточек*/
			tabl[a][b] = tabl_m[a][b];
			tabl[c][d] = tabl_m[c][d];
			o = 1;
		}
	}
}

void OPEN(sf::String tabl[4], int i, int j) 
{
	if (tabl[i][j] == 'a') tabl[i][j] = 'A';
	if (tabl[i][j] == 'b') tabl[i][j] = 'B';
	if (tabl[i][j] == 'c') tabl[i][j] = 'C';
	if (tabl[i][j] == 'y') tabl[i][j] = 'Y';
	if (tabl[i][j] == 'l') tabl[i][j] = 'L';
	if (tabl[i][j] == 'k') tabl[i][j] = 'K';
}


