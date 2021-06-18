﻿#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime> 
#include <windows.h>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

/*Класс загрузки текстур и спрайтов
@param person1, person2, person3, frame, tt, background
являются переменными, в которые загружаются текстуры для дальнейшего использования

@param Person1, Person2, Person3, Frame, TT, Background
являются переменными спрайтов

@function addtexture
загрузка текстур с помощью метода .loadFromFile()

@function addsprites
устанавливает текстуры спрайтам при помощи метода .setTexture()
*/
class texture {
public:
	Texture person1, person2, person3, frame, tt, background;

	void addtexture() {
		person1.loadFromFile("Fonts\\Cat 01-2.png");
		person2.loadFromFile("Fonts\\Cat 01-3.png");
		person3.loadFromFile("Fonts\\Dog 01-3.png");
		frame.loadFromFile("Fonts\\frame.png");
		background.loadFromFile("Fonts\\back.png");
		tt.loadFromFile("Fonts\\shirt.png");
	}

	Sprite Person1, Person2, Person3, Frame, TT, Background;
	void addsprites() {

		Person1.setTexture(person1);
		Person1.setTextureRect(IntRect(32, 0, 32, 32));

		Person2.setTexture(person2);
		Person2.setTextureRect(IntRect(32, 0, 32, 32));

		Person3.setTexture(person3);
		Person3.setTextureRect(IntRect(32, 0, 32, 32));

		Frame.setTexture(frame);

		TT.setTexture(tt);

		Background.setTexture(background);
	}


};
/*@param tabl[4], tabl_m[4]
строковые массивы, отвечающие за расположение персонажей и обложек карточек

@param sml_t
 строковый массив, использующийся для сравнения карточек друг с другом
*/
String tabl[4] =
{
"cca",
"aaa",
"ccb",
"bbb",
};
String tabl_m[4] =
{
"cca",
"aaa",
"ccb",
"bbb",
};
String sml_t[4] =
{
"   ",
"   ",
"   ",
"   ",
};


int main()
{
	//Music music; /*@param music : переменная, в которую загружается музыкальный файл */
	//music.openFromFile("C:\\Users\\79529\\project\\Project1\\Фон1.ogg"); /*загрузка музыкального файла*/
	//music.play(); /*проигрывание музыкального файла*/
	//music.setLoop(true); /*вулючение повтора музыки*/

	//SoundBuffer shootBuffer;/*@param shootBuffer : буфер для звука*/
	//shootBuffer.loadFromFile("C:\\Users\\79529\\project\\Project1\\Нажатие.ogg");/*загружаем в буфер звук*/
	//Sound shoot(shootBuffer);/*создание звука и загрузка в него параметра*/

	int lenght = 154, width = 119; /* @param lenght, width : размеры окна*/
	RenderWindow window(VideoMode(lenght, width), "memorize");/* создание объекта класса RenderWindow
																@param Window : объект, в котором отображается 2d графика*/

	Clock clock; /*@param clock : переменная времени */

	texture aadd; /*@param aadd : объект класса Текстуры*/
	aadd.addtexture(); /*@method .addtexture : метод загрузки тектсур */
	aadd.addsprites(); /*@method .addsprites : метод загрузки спрайтов */

	float frm = 0; /*@param frm : кадры в игре*/


	/*@param f_lenght, f_width : вспомогательные параметры, делящие окно на ячейки, согласно размерам текстуры рамки */
	int f_lenght = lenght / 7;
	int f_width = width / 7;
	/*@param b_lenght, b_width : вспомогательные параметры, делящие окно на ячейки, согласно размерам карточек */
	int b_lenght = (lenght - 14) / 35;
	int b_width = (width - 14) / 35;

	/* @param a,b,c,d : переменные для сравнения карточек*/
	int a = -1, b = -1, c = -1, d = -1;
	bool o = 1;/*@param o : доп.параметр для различающихся карточек*/


	while (window.isOpen())/*цикл, работающий пока окно открыто*/
	{
		float time = clock.getElapsedTime().asMilliseconds(); /*@param time : переменная, в которую загружается время; @method .getElapsedTime().asMilliseconds() : дают прошедшее время в миллисекундах*/
		clock.restart(); /*@method .restsrt : обновление времени*/
		frm += 0.01 * time; /*количество прошедших кадров*/

		if (frm > 3) frm = frm - 3; /*создание анимации*/
		aadd.Person1.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); /*@method .setTextureRect() : установка необходимой текстуры спрайта*/
		aadd.Person2.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32)); /*@param IntRect : выбори необходимой области текстуры*/
		aadd.Person3.setTextureRect(IntRect(0 + 32 * int(frm), 0, 32, 32));

		window.clear(Color(50, 50, 123, 0)); /*@method .clear() : очистка окна и задание цвета*/

		/*создание рамки
		@method .setPosition устанавливается расположение рамки
		@method .draw(aadd.Frame) отрисовка спрайта рамки*/
		for (int i = 0; i < f_lenght; i++) {
			for (int j = 0; j < f_width; j++) {
				aadd.Frame.setPosition(i * 7, j * 7);
				if (i == 0 || j == 0 || i == f_lenght - 1 || j == f_width - 1)/*условие, фильтрующее расположение рамки*/
					window.draw(aadd.Frame);

			}
		}
		/*установка фоновых рубашек
		@method .setPosition устанавливает расположение фоновых рубашек
		@method .draw(aadd.Background) отрисовка спрайта фоновых рубашек*/
		for (int i = 0; i < b_lenght; i++) {
			for (int j = 0; j < b_width; j++) {
				aadd.Background.setPosition(i * 35 + 7, j * 35 + 7);
				window.draw(aadd.Background);

			}
		}

		/*отрисовка персонажей
		условиями if определяется тип необходимого персонажа*/
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				aadd.Person1.setPosition(i * 35 + 8, j * 35 + 9);/*установка расположения персонажей*/
				aadd.Person2.setPosition(i * 35 + 8, j * 35 + 9);
				aadd.Person3.setPosition(i * 35 + 8, j * 35 + 9);
				if (tabl[i][j] == 'a' || tabl[i][j] == 'A') {
					window.draw(aadd.Person1); /*отрисовка персонажа1*/
				}
				if (tabl[i][j] == 'b' || tabl[i][j] == 'B')
				{
					window.draw(aadd.Person2);/*отрисовка персонажа 2*/
				}
				if (tabl[i][j] == 'c' || tabl[i][j] == 'C') {
					window.draw(aadd.Person3);/*отрисовка персонажа 2*/
				}
			}
		};


		/*отрисовка верхних рубашек
		условиями if определяется необходимость появления верхних рубашек*/
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				aadd.TT.setPosition(i * 35 + 7, j * 35 + 7); /*установка расположения верхних рубашек*/

				if (tabl[i][j] == 'a' || tabl[i][j] == 'b' || tabl[i][j] == 'c') {
					window.draw(aadd.TT);/*отрисовка верхних руюашек*/
				}


			}
		};


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

						Win_X1 = (7 + 35 * i) * (window.getSize().x / lenght);
						Win_Y1 = (7 + 35 * j) * (window.getSize().y / width);

						Win_X2 = (42 + 35 * i) * (window.getSize().x / lenght);
						Win_Y2 = (42 + 35 * j) * (window.getSize().y / width);
						if ((X_Pos > Win_X1) && (X_Pos < Win_X2) && (Y_Pos > Win_Y1) && (Y_Pos < Win_Y2))
						{
							//shoot.play();

							if (tabl[i][j] == 'a') tabl[i][j] = 'A';
							if (tabl[i][j] == 'b') tabl[i][j] = 'B';
							if (tabl[i][j] == 'c') tabl[i][j] = 'C';

							if (((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C')) && a == -1)
							{
								a = i;
								b = j;

								sml_t[a][b] = tabl[i][j];
								cout << "pppp";
							}
							else if ((tabl[i][j] == 'A') || (tabl[i][j] == 'B') || (tabl[i][j] == 'C'))
							{
								c = i;
								d = j;
								sml_t[c][d] = tabl[i][j];
								cout << "aaaa";


								if (sml_t[a][b] == sml_t[c][d])
								{
									if (tabl[a][b] == 'a') tabl[a][b] = 'A';
									if (tabl[a][b] == 'b') tabl[a][b] = 'B';
									if (tabl[a][b] == 'c') tabl[a][b] = 'C';
									if (tabl[c][d] == 'a') tabl[c][d] = 'A';
									if (tabl[c][d] == 'b') tabl[c][d] = 'B';
									if (tabl[c][d] == 'c') tabl[c][d] = 'C';

								}
								else {
									if (o == 1) {
										if (tabl[a][b] == 'a') tabl[a][b] = 'A';
										if (tabl[a][b] == 'b') tabl[a][b] = 'B';
										if (tabl[a][b] == 'c') tabl[a][b] = 'C';
										if (tabl[c][d] == 'a') tabl[c][d] = 'A';
										if (tabl[c][d] == 'b') tabl[c][d] = 'B';
										if (tabl[c][d] == 'c') tabl[c][d] = 'C';
										o = 0;
									}
									else {
										tabl[a][b] = tabl_m[a][b];
										tabl[c][d] = tabl_m[c][d];
										o = 1;
									}

								}
								a = -1;
								b = -1;

							}


						}
						aadd.TT.setPosition(i * 35 + 7, j * 35 + 7);

						if (tabl[i][j] == 'a' || tabl[i][j] == 'b' || tabl[i][j] == 'c') {
							window.draw(aadd.TT);
						}
					}
				}
			}
		}

		window.display(); // отрисовка окна
	};
	return 0;
}