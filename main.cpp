/** \brief Hlavni soubor programu semprojekt 0.1.0
*  \file main.cpp
*  \author Vlastimil Sadilek
*  \mainpage Algoritmy: Zadani 4 - Bubblesort
*/

#include <iostream>     // cout, cin
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include "bubbleclass.h"

using namespace std;

int main () {
	

	BubbleClass hovno(4);
	hovno.PrintInitArray();
	hovno.PrintArrOfChanges();
	hovno.PrintArrOfComparsions();
	BubbleClass prdy(5);
	prdy.PrintInitArray();
	prdy.PrintArrOfChanges();
	prdy.PrintArrOfComparsions();

	return 0;
}

