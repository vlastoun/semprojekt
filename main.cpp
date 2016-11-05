/** \brief Hlavni soubor programu semprojekt 0.1.0
*  \file main.cpp
*  \author Vlastimil Sadilek
*  \mainpage Algoritmy: Zadani 4 - Bubblesort
*/

#include <iostream>     // cout, cin
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include "bubbleclass.h"
#include "histogram.h"
#include "printtofile.h"


using namespace std;

void PrintVector(vector<int>& array) {
	int size = array.size();
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main () {
	vector<int> vysledek;
	vector<int> histogram1;

	BubbleClass order4(5);
	order4.PrintInitArray();
	vysledek = order4.GetArrayOfComparsions();
	HistogramClass obj(vysledek);
	histogram1 = obj.GetHistogram();
	PrintVector(histogram1);
	PrintToFileClass obj1(histogram1);
	obj1.MakeFile();
	order4.PrintArrOfComparsions();


	return 0;
}

