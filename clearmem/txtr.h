#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
extern int lenght, width;
extern int f_lenght;
extern int f_width;
extern int b_lenght;
extern int b_width;


class texture {
public:
	Texture person1, person2, person3, person4, person5, person6, frame, tt, background;
	void addtexture();
	Sprite Person1, Person2, Person3, Person4, Person5, Person6, Frame, TT, Background;
	void addsprites();
	void FRAME(RenderWindow& wn);
	void BCKG(RenderWindow& wn);
	void SPAWN(RenderWindow& wn, String tabl[4]);
	void FRGG(RenderWindow& wn, String tabl[4]);
};