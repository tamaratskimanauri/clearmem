#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

extern int lenght; /// <param name="lenght"> - длина окна </param>
extern int width; /// <param name="width"> - ширина окна </param>
extern int f_lenght; /// <param name="f_lenght"> - количество рамочек в длине </param>
extern int f_width; /// <param name="f_width"> - количество рамочек в ширине </param>
extern int b_lenght; /// <param name="b_lenght"> - количество столбцов карточек на поле </param>
extern int b_width; /// <param name="b_width"> - количество строк карточек на поле </param>

///  \- класс отрисовки игровых объектов.
class texture {
public:
	Texture person1, person2, person3, person4, person5, person6, frame, tt, background;
	/// <summary>
	/// загрузка текстур
	/// </summary>
	void addtexture();
	Sprite Person1, Person2, Person3, Person4, Person5, Person6, Frame, TT, Background;
	/// <summary>
	/// загрузка спрайтов
	/// </summary>
	void addsprites();
	/// <summary>
	/// отрисовка рамки
	/// </summary>
	/// <param name="wn">- окно </param>
	void FRAME(RenderWindow& wn);
	/// <summary>
	/// отрисовка фоновых рубашек
	/// </summary>
	/// <param name="wn">- окно </param>
	void BCKG(RenderWindow& wn);
	/// <summary>
	/// отрисовка персонажей
	/// </summary>
	/// <param name="wn">- окно </param>
	/// <param name="tabl">- таблица карты </param>
	void SPAWN(RenderWindow& wn, String tabl[4]);
	/// <summary>
	/// отрисовка верхних рубашек
	/// </summary>
	/// <param name="wn"> - окно </param>
	/// <param name="tabl"> - таблица карты </param>
	void FRGG(RenderWindow& wn, String tabl[4]);
};