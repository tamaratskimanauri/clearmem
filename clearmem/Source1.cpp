#include "clearmem.h"

int a = -1; /// <param name="a"> - ���������� ��� ��������� �������� </param>
int b = -1; /// <param name="b"> - ���������� ��� ��������� �������� </param>
int c = -1; /// <param name="c"> - ���������� ��� ��������� �������� </param>
int d = -1; /// <param name="d"> - ���������� ��� ��������� �������� </param>
bool o = 1; /**<���.�������� ��� ������������� ��������*/

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
	if (sml_t[a][b] == sml_t[c][d]) //������������ ���������� ����������
	{
		OPEN(tabl, a, b);
		OPEN(tabl, c, d);
	}
	else { //������� ����������� ����������
		if (o == 1) { //������� �������� ��������� ��������
			OPEN(tabl, a, b);
			OPEN(tabl, c, d);
			o = 0;
		}
		else { //������� �������� ��������� ��������
			tabl[a][b] = tabl_m[a][b];
			tabl[c][d] = tabl_m[c][d];
			o = 1;
		}
	}
}



