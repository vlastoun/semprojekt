/** \brief Hlavni soubor programu semprojekt 0.1.0
*  \file main.cpp
*  \author Vlastimil Sadilek
*  \mainpage Algoritmy: Zadani 4 - Bubblesort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "bubbleclass.h"
#include "histogram.h"
#include "printtofile.h"


using namespace std;

void PrintVector(vector<int> array) {
	int size = array.size();
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	int MaxSize;

	cout << "Zadejte maximalni velikost pole:" << endl;
	cin >> MaxSize;

	BubbleClass order1(MaxSize);


	cout << "Vstupni pole:" << endl;
	order1.PrintInitArray();
	cout << endl;

	cout << "Pole vymen:" << endl;
	order1.PrintArrOfChanges();
	cout << endl;

	cout << "Pole porovnani:" << endl;
	order1.PrintArrOfComparsions();
	cout << endl;

	vector<int> arrayOfChanges;
	arrayOfChanges = order1.GetArrayOfChanges();
	vector<int> arrayOfComparsions;
	arrayOfComparsions = order1.GetArrayOfComparsions();
	HistogramClass histogram1(arrayOfChanges);

	cout << "Pole cetnosti vymen:" << endl;
	PrintVector(histogram1.GetHistogram());
	cout << endl;

	HistogramClass histogram2(arrayOfComparsions);

	cout << "Pole cetnosti porovnani:" << endl;
	PrintVector(histogram2.GetHistogram());
	cout << endl;

	vector<int> vectorToPrint;
	vectorToPrint = histogram1.GetHistogram();
	vector<int> vectorToPrint2;
	vectorToPrint2 = histogram2.GetHistogram();

	PrintToFileClass file1(vectorToPrint);
	file1.SetNameOfFile("histogram cetnosti vymen");
	file1.SetNameOfValues("pocet vymen");
	file1.MakeFile();

	PrintToFileClass file2(vectorToPrint2);
	file1.SetNameOfFile("histogram cetnosti porovnani");
	file1.SetNameOfValues("pocet porovnani");
	file2.MakeFile();
}

