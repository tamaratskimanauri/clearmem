#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

extern int lenght; /// <param name="lenght"> - ����� ���� </param>
extern int width; /// <param name="width"> - ������ ���� </param>
extern int f_lenght; /// <param name="f_lenght"> - ���������� ������� � ����� </param>
extern int f_width; /// <param name="f_width"> - ���������� ������� � ������ </param>
extern int b_lenght; /// <param name="b_lenght"> - ���������� �������� �������� �� ���� </param>
extern int b_width; /// <param name="b_width"> - ���������� ����� �������� �� ���� </param>

///  \- ����� ��������� ������� ��������.
class texture {
public:
	Texture person1, person2, person3, person4, person5, person6, frame, tt, background;
	/// <summary>
	/// �������� �������
	/// </summary>
	void addtexture();
	Sprite Person1, Person2, Person3, Person4, Person5, Person6, Frame, TT, Background;
	/// <summary>
	/// �������� ��������
	/// </summary>
	void addsprites();
	/// <summary>
	/// ��������� �����
	/// </summary>
	/// <param name="wn">- ���� </param>
	void FRAME(RenderWindow& wn);
	/// <summary>
	/// ��������� ������� �������
	/// </summary>
	/// <param name="wn">- ���� </param>
	void BCKG(RenderWindow& wn);
	/// <summary>
	/// ��������� ����������
	/// </summary>
	/// <param name="wn">- ���� </param>
	/// <param name="tabl">- ������� ����� </param>
	void SPAWN(RenderWindow& wn, String tabl[4]);
	/// <summary>
	/// ��������� ������� �������
	/// </summary>
	/// <param name="wn"> - ���� </param>
	/// <param name="tabl"> - ������� ����� </param>
	void FRGG(RenderWindow& wn, String tabl[4]);
};