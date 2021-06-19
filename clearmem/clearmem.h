// clearmem.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

extern int a; /// <param name="a"> - переменная для сравнения карточек </param>
extern int b; /// <param name="b"> - переменная для сравнения карточек </param>
extern int c; /// <param name="c"> - переменная для сравнения карточек </param>
extern int d; /// <param name="d"> - переменная для сравнения карточек </param>
extern bool o; /**<доп.параметр для различающихся карточек*/

/// <summary>
/// функция проверка идентичности карточек
/// </summary>
/// <param name="sml_t">- таблица кэша</param>
/// <param name="tabl">- таблица спавна карты</param>
/// <param name="tabl_m">- таблица, хранящая первоначальные значения карты</param>
void CHEECK(sf::String sml_t[4], sf::String tabl[4], sf::String tabl_m[4]);

/// <summary>
/// функция открытия карточек
/// </summary>
/// <param name="tabl"> - таблица спавна карты </param>
/// <param name="i">- номер строки </param>
/// <param name="j">- номер столбца </param>
void OPEN(sf::String tabl[4], int i, int j);

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
