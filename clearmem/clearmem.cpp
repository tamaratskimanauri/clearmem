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


/* \param tabl[4], tabl_m[4] - строковые массивы, отвечающие за расположение персонажей и обложек карточек

    \param sml_t - строковый массив, использующийся для сравнения карточек друг с другом
*/

float frm = 0; /*@param frm : кадры в игре*/
/*@param f_lenght, f_width : вспомогательные параметры, делящие окно на ячейки, согласно размерам текстуры рамки */

/*@param b_lenght, b_width : вспомогательные параметры, делящие окно на ячейки, согласно размерам карточек */


String tabl[4] =
{
"cya",
"yak",
"lcb",
"bkl",
};
String tabl_m[4] =
{
"cya",
"yak",
"lcb",
"bkl",
};
String sml_t[4] =
{
"   ",
"   ",
"   ",
"   ",
};


/*Класс загрузки текстур и спрайтов
* \param person1, person2, person3, frame, tt, background - являются переменными, в которые загружаются текстуры для дальнейшего использования

* \param Person1, Person2, Person3, Frame, TT, Background - являются переменными спрайтов

* \function addtexture
загрузка текстур с помощью метода .loadFromFile()

@function addsprites
устанавливает текстуры спрайтам при помощи метода .setTexture()
*/

	

int main()
{
	RenderWindow window(VideoMode(lenght, width), "memorize");/* создание объекта класса RenderWindow
																@param Window : объект, в котором отображается 2d графика*/
	RenderWindow& wn = window;
	Clock clock; /*@param clock : переменная времени */

	texture aadd; /*@param aadd : объект класса Текстуры*/
	aadd.addtexture(); /*@method .addtexture : метод загрузки тектсур */
	aadd.addsprites(); /*@method .addsprites : метод загрузки спрайтов */

	while (window.isOpen())/*цикл, работающий пока окно открыто*/
	{
		float time = clock.getElapsedTime().asMilliseconds(); /*@param time : переменная, в которую загружается время; @method .getElapsedTime().asMilliseconds() : дают прошедшее время в миллисекундах*/
		clock.restart(); /*@method .restsrt : обновление времени*/
		frm += 0.01 * time; /*количество прошедших кадров*/
		if (frm > 3) frm = frm - 3; /*создание анимации*/
		aadd.Person1.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); /*@method .setTextureRect() : установка необходимой текстуры спрайта*/
		aadd.Person2.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); /*@param IntRect : выбори необходимой области текстуры*/
		aadd.Person3.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		aadd.Person4.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); 
		aadd.Person5.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		aadd.Person6.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));
		window.clear(Color(50, 50, 123, 0)); /*@method .clear() : очистка окна и задание цвета*/

		aadd.FRAME(wn);
		aadd.BCKG(wn);
		aadd.SPAWN(wn, tabl);
		aadd.FRGG(wn, tabl);
		/*@param X_Pos, Y_Pos, Win_X1, Win_Y1, Win_X2, Win_Y2
		X_Pos, Y_Pos : координаты курсора
		Win_X1, Win_Y1, Win_X2, Win_Y2 : координаты вершин карточек*/
		float X_Pos, Y_Pos, Win_X1, Win_Y1, Win_X2, Win_Y2;

		Event event; /*@param event : переменная событий в окне*/
		/*цикл, перебирающий все события в окне
		@method .pollEvent() : собирает все события, происходящие в окне*/
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) /*обработка события нажатия крестика*/
			{
				window.close(); /*@method .close() : закрывает окно*/
			}
			else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) /*обработка события нажатия левой кнопки мыши*/
			{
				X_Pos = Mouse::getPosition(window).x;/*@method Mouse::getPosition(window) : считывание координат курсора в окне*/
				Y_Pos = Mouse::getPosition(window).y;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						/* масштабирование координат плиток*/
						Win_X1 = (7 + 35 * i) * (window.getSize().x / lenght); /*@method .getSize : получение размеров окна*/
						Win_Y1 = (7 + 35 * j) * (window.getSize().y / width); /* "/ lenght(width)" : отношение текущего и первоначального размера окна*/
						Win_X2 = (42 + 35 * i) * (window.getSize().x / lenght);
						Win_Y2 = (42 + 35 * j) * (window.getSize().y / width);
						/*цикл взаимодействия с карточками*/
						if ((X_Pos > Win_X1) && (X_Pos < Win_X2) && (Y_Pos > Win_Y1) && (Y_Pos < Win_Y2))/*условие опрделения положения курсора относительно карточек(внутри/снаружи)*/
						{
							//shoot.play(); 
							/*циклы открытия карточек*/
							OPEN(tabl, i, j);

							if (((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C')
								|| (tabl[i][j] == 'K') || (tabl[i][j] == 'L') || (tabl[i][j] == 'Y')) && a == -1) /*условие открытия первой карточки*/
							{
								/*присваивание текущего номера карточки*/
								a = i;
								b = j;
								sml_t[a][b] = tabl[i][j]; /*запоминание номера первой открытой карточки*/
							}
							else if ((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C') ||
								 (tabl[i][j] == 'K') || (tabl[i][j] == 'L') || (tabl[i][j] == 'Y'))/*условие открытия второй карточки*/
							{
								/*присваивание текущего номера карточки*/
								c = i;
								d = j;
								sml_t[c][d] = tabl[i][j]; /*запоминание номера второй открытой карточки*/
								/*сравнение карточек*/
								CHEECK(sml_t, tabl, tabl_m);
								a = -1;
								b = -1;
							}
						}
					}
				}
			}
		}
		window.display(); /*Отрисовка окна*/
	};
	return 0;
}