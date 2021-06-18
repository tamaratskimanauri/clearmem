#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest/doctest.h"
#include "clearmem.h"

TEST_CASE("OPEN - проверка открытия всего") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	int i = 0, j = 0;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'C');
	i = 0, j = 1;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'Y');
	i = 0, j = 2;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'A');
	i = 1, j = 0;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'Y');
	i = 1, j = 1;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'A');
	i = 1, j = 2;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'K');
	i = 2, j = 0;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'L');
	i = 2, j = 1;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'C');
	i = 2, j = 2;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'B');
	i = 3, j = 0;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'B');
	i = 3, j = 1;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'K');
	i = 3, j = 2;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'L');
}

TEST_CASE("OPEN - проверка, что открытое, остается открытым") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	int i = 0, j = 0;
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'C');
	OPEN(tabl, i, j);
	CHECK(tabl[i][j] == 'C');
}

TEST_CASE("CHEECK - условие закрытия различных карточек") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	String tabl_m[4] = { "cya","yak","lcb","bkl", };
	String sml_t[4] = { "   ","   ","   ","   ", };
	a = 0; b = 0; c = 2; d = 2; o = 0;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'c');
	CHECK(tabl[c][d] == 'b');
}

TEST_CASE("CHEECK - условие идентичности карточек") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	String tabl_m[4] = { "cya","yak","lcb","bkl", };
	String sml_t[4] = { "   ","   ","   ","   ", };
	a = 0; b = 0; c = 2; d = 1;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'C');
}

TEST_CASE("CHEECK - 'o' не влияет на проверку идентичности") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	String tabl_m[4] = { "cya","yak","lcb","bkl", };
	String sml_t[4] = { "   ","   ","   ","   ", };
	a = 0; b = 0; c = 2; d = 1; o = 1;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'C');
	tabl[a][b] = tabl_m[a][b];
	tabl[c][d] = tabl_m[c][d];
	a = 0; b = 0; c = 2; d = 1; o = 0;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'C');
}

TEST_CASE("CHEECK - условие открытия различных карточек") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	String tabl_m[4] = { "cya","yak","lcb","bkl", };
	String sml_t[4] = { "   ","   ","   ","   ", };
	a = 0; b = 0; c = 2; d = 2; o = 1;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'B');
}

TEST_CASE("CHEECK - незакрытие одинаковые карточек") {
	String tabl[4] = { "cya","yak","lcb","bkl", };
	String tabl_m[4] = { "cya","yak","lcb","bkl", };
	String sml_t[4] = { "   ","   ","   ","   ", };
	a = 0; b = 0; c = 2; d = 1; o = 1;
	sml_t[a][b] = tabl[a][b];
	sml_t[c][d] = tabl[c][d];
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'C');
	a = 0; b = 0; c = 2; d = 1; o = 1;
	CHEECK(sml_t, tabl, tabl_m);
	CHECK(tabl[a][b] == 'C');
	CHECK(tabl[c][d] == 'C');
}
