#include "txtr.h"

int lenght = 154; /// <param name="lenght"> - длина окна </param>
int width = 119; 
int f_lenght = lenght / 7; 
int f_width = width / 7; 
int b_lenght = (lenght - 14) / 35; 
int b_width = (width - 14) / 35;

/// <summary>
/// загрузка текстур
/// </summary>
void texture::addtexture() {
	person1.loadFromFile("Fonts\\Cat 01-2.png");
	person2.loadFromFile("Fonts\\Cat 01-3.png");
	person3.loadFromFile("Fonts\\Dog 01-3.png");
	person4.loadFromFile("Fonts\\Dog 01-2.png");
	person5.loadFromFile("Fonts\\Dog 01-1.png");
	person6.loadFromFile("Fonts\\Cat 01-1.png");
	frame.loadFromFile("Fonts\\frame.png");
	background.loadFromFile("Fonts\\back.png");
	tt.loadFromFile("Fonts\\shirt.png");
}
/// <summary>
/// загрузка спрайтов
/// </summary>
void texture::addsprites() {
	Person1.setTexture(person1);
	Person1.setTextureRect(IntRect(32, 0, 32, 32));
	Person2.setTexture(person2);
	Person2.setTextureRect(IntRect(32, 0, 32, 32));
	Person3.setTexture(person3);
	Person3.setTextureRect(IntRect(32, 0, 32, 32));
	Person4.setTexture(person4);
	Person4.setTextureRect(IntRect(32, 0, 32, 32));
	Person5.setTexture(person5);
	Person5.setTextureRect(IntRect(32, 0, 32, 32));
	Person6.setTexture(person6);
	Person6.setTextureRect(IntRect(32, 0, 32, 32));
	Frame.setTexture(frame);
	TT.setTexture(tt);
	Background.setTexture(background);
}
/// <summary>
/// отрисовка рамки
/// </summary>
/// <param name="wn">- окно </param>
void texture::FRAME(RenderWindow& wn) {
	for (int i = 0; i < f_lenght; i++) {
		for (int j = 0; j < f_width; j++) {
			Frame.setPosition(i * 7, j * 7);
			if (i == 0 || j == 0 || i == f_lenght - 1 || j == f_width - 1)/*условие, фильтрующее расположение рамки*/
				wn.draw(Frame);
		}
	}
}
/// <summary>
/// отрисовка фоновых рубашек
/// </summary>
/// <param name="wn">- окно </param>
void texture::BCKG(RenderWindow& wn) {
	for (int i = 0; i < b_lenght; i++) {
		for (int j = 0; j < b_width; j++) {
			Background.setPosition(i * 35 + 7, j * 35 + 7);
			wn.draw(Background);
		}
	}
}
/// <summary>
/// отрисовка персонажей
/// </summary>
/// <param name="wn">- окно </param>
/// <param name="tabl">- таблица карты </param>
void texture::SPAWN(RenderWindow& wn, sf::String tabl[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			Person1.setPosition(i * 35 + 8, j * 35 + 9);/*установка расположения персонажей*/
			Person2.setPosition(i * 35 + 8, j * 35 + 9);
			Person3.setPosition(i * 35 + 8, j * 35 + 9);
			Person4.setPosition(i * 35 + 8, j * 35 + 9);
			Person5.setPosition(i * 35 + 8, j * 35 + 9);
			Person6.setPosition(i * 35 + 8, j * 35 + 9);

			if (tabl[i][j] == 'a' || tabl[i][j] == 'A') {
				wn.draw(Person1); /*отрисовка персонажа1*/
			}
			if (tabl[i][j] == 'b' || tabl[i][j] == 'B')
			{
				wn.draw(Person2);/*отрисовка персонажа 2*/
			}
			if (tabl[i][j] == 'c' || tabl[i][j] == 'C') {
				wn.draw(Person3);/*отрисовка персонажа 2*/
			}
			if (tabl[i][j] == 'y' || tabl[i][j] == 'Y') {
				wn.draw(Person4); /*отрисовка персонажа1*/
			}
			if (tabl[i][j] == 'k' || tabl[i][j] == 'K')
			{
				wn.draw(Person5);/*отрисовка персонажа 2*/
			}
			if (tabl[i][j] == 'l' || tabl[i][j] == 'L') {
				wn.draw(Person6);/*отрисовка персонажа 2*/
			}
		}
	};
}
/// <summary>
/// отрисовка верхних рубашек
/// </summary>
/// <param name="wn"> - окно </param>
/// <param name="tabl"> - таблица карты </param>
void texture::FRGG(RenderWindow& wn, sf::String tabl[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			TT.setPosition(i * 35 + 7, j * 35 + 7); /*установка расположения верхних рубашек*/
			if (tabl[i][j] == 'a' || tabl[i][j] == 'b' || tabl[i][j] == 'c' ||
				tabl[i][j] == 'y' || tabl[i][j] == 'k' || tabl[i][j] == 'l') {
				wn.draw(TT);/*отрисовка верхних руюашек*/
			}
		}
	};
}