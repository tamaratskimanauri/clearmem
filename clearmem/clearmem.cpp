#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime> 
#include <windows.h>
#include <SFML/Audio.hpp>
#include "clearmem.h"
#include "txtr.h"

using namespace sf;
using namespace std;




float frm = 0; /// <param name="frm"> - кадры </param>

/// \param tabl[4] - строковые массивы, отвечающие за расположение персонажей и обложек карточек.
String tabl[4] =
{
"cya",
"yak",
"lcb",
"bkl",
};
/// \param tabl_m[4] - строковые массивы, отвечающие за расположение персонажей и обложек карточек.
String tabl_m[4] =
{
"cya",
"yak",
"lcb",
"bkl",
};
/// \param sml_t - строковый массив, использующийся для сравнения карточек друг с другом.
String sml_t[4] =
{
"   ",
"   ",
"   ",
"   ",
};
	

int main()
{
	/// \param window - объект, в котором отображается 2d графика.
	RenderWindow window(VideoMode(lenght, width), "memorize");
	RenderWindow& wn = window;
	Clock clock; /// <param name="clock"> - время </param>

	texture aadd; 
	aadd.addtexture(); 
	aadd.addsprites(); 

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds(); /// <param name="time"> - прошедшее время </param>
		clock.restart(); 
		frm += 0.01 * time; 
		if (frm > 3) frm = frm - 3; 
		aadd.Person1.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); 
		aadd.Person2.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); 
		aadd.Person3.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		aadd.Person4.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); 
		aadd.Person5.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		aadd.Person6.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		window.clear(Color(50, 50, 123, 0)); 

		aadd.FRAME(wn);
		aadd.BCKG(wn);
		aadd.SPAWN(wn, tabl);
		aadd.FRGG(wn, tabl);
		
		float X_Pos; /// <param name="X_Pos"> - x координата курсора </param>
		float Y_Pos; /// <param name="Y_Pos"> - y координата курсора </param>
		float Win_X1; /// <param name="Win_X1"> - нижняя граница карточки </param>
		float Win_Y1; /// <param name="Win_Y1"> - левая граница карточки </param>
		float Win_X2; /// <param name="Win_X2"> - верхняя граница карточки </param>
		float Win_Y2; /// <param name="Win_Y2"> - правая граница карточки </param>

		Event event; /// <param name="event"> - событие в окне </param>
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) 
			{
				window.close(); 
			}
			else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				X_Pos = Mouse::getPosition(window).x;
				Y_Pos = Mouse::getPosition(window).y;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Win_X1 = (7 + 35 * i) * (window.getSize().x / lenght); 
						Win_Y1 = (7 + 35 * j) * (window.getSize().y / width); 
						Win_X2 = (42 + 35 * i) * (window.getSize().x / lenght);
						Win_Y2 = (42 + 35 * j) * (window.getSize().y / width);
						if ((X_Pos > Win_X1) && (X_Pos < Win_X2) && (Y_Pos > Win_Y1) && (Y_Pos < Win_Y2))
						{
							OPEN(tabl, i, j);

							if (((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C')
								|| (tabl[i][j] == 'K') || (tabl[i][j] == 'L') || (tabl[i][j] == 'Y')) && a == -1) 
							{
								a = i;
								b = j;
								sml_t[a][b] = tabl[i][j]; 
							}
							else if ((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C') ||
								 (tabl[i][j] == 'K') || (tabl[i][j] == 'L') || (tabl[i][j] == 'Y'))
							{
								
								c = i;
								d = j;
								sml_t[c][d] = tabl[i][j]; 
								CHEECK(sml_t, tabl, tabl_m);
								a = -1;
								b = -1;
							}
						}
					}
				}
			}
		}
		window.display(); 
	};
	return 0;
}