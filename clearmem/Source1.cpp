#include "clearmem.h"

int a = -1; /// <param name="a"> - переменная для сравнения карточек </param>
int b = -1; /// <param name="b"> - переменная для сравнения карточек </param>
int c = -1; /// <param name="c"> - переменная для сравнения карточек </param>
int d = -1; /// <param name="d"> - переменная для сравнения карточек </param>
bool o = 1; /**<доп.параметр для различающихся карточек*/

void OPEN(sf::String tabl[4], int i, int j)
{
	if (tabl[i][j] == 'a') tabl[i][j] = 'A';
	if (tabl[i][j] == 'b') tabl[i][j] = 'B';
	if (tabl[i][j] == 'c') tabl[i][j] = 'C';
	if (tabl[i][j] == 'y') tabl[i][j] = 'Y';
	if (tabl[i][j] == 'l') tabl[i][j] = 'L';
	if (tabl[i][j] == 'k') tabl[i][j] = 'K';
}

void CHEECK(sf::String sml_t[4], sf::String tabl[4], sf::String tabl_m[4]) {
	if (sml_t[a][b] == sml_t[c][d]) //незакрывание идентичных персонажей
	{
		OPEN(tabl, a, b);
		OPEN(tabl, c, d);
	}
	else { //условие различности персонажей
		if (o == 1) { //условие открытия различных карточек
			OPEN(tabl, a, b);
			OPEN(tabl, c, d);
			o = 0;
		}
		else { //условие закрытия различных карточек
			tabl[a][b] = tabl_m[a][b];
			tabl[c][d] = tabl_m[c][d];
			o = 1;
		}
	}
}



