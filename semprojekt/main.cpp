/** \brief Hlavni soubor programu semprojekt 0.1.0
*  \file main.cpp
*  \author Vlastimil Sadilek SAD045
*  \mainpage Algoritmy: Zadani 4 - Bubblesort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "bubbleclass.h"
#include "histogram.h"
#include "printtofile.h"


using namespace std;

void PrintVector(vector<int> array);
bool inputValidation(int toValidate);

int main() {
	int order;
	bool outputToConsole;
	char vstup[1];

	cout << "Zadejte maximalni velikost pole (cislo kladne od 0):" << endl;
	cin >> order;
	if (!inputValidation(order)) {
		cout << "Nespravny vstup" << endl;
		cout << "Konec programu" << endl;
		return 0;
	}
	if (order < 1) {
		cout << "Nespravny vstup" << endl;
		cout << "Konec programu" << endl;
		return 0;
	}
	
	cout << "Chcete výstup na obrazovku? A/N" << endl;
	cin >> vstup[0];
	while ((vstup[0] != 'A') && (vstup[0] != 'N')) {
		cout << "Zadejte A pro vystup na obrazovku nebo N pro primy tisk do souboru" << endl;
		cin >> vstup[0];
	}
	if (vstup[0] == 'A') {
		outputToConsole = 1;
	}
	else if (vstup[0] == 'N') {
		outputToConsole = 0;
	}
	else {
		cout << "Konec programu" << endl;
		return 0;
	}
			
	BubbleClass order1(order);

	vector<int>	arrayOfChanges		= order1.GetArrayOfChanges();
	vector<int>	arrayOfComparsions	= order1.GetArrayOfComparsions();

	HistogramClass histogramOfChanges(arrayOfChanges);
	HistogramClass histogramOfComparsions(arrayOfComparsions);
	
	if (outputToConsole) {
		cout << "Vstupni pole:" << endl;
		order1.PrintInitArray();
		cout << endl;

		cout << "Pole vymen:" << endl;
		order1.PrintArrOfChanges();
		cout << endl;

		cout << "Pole porovnani:" << endl;
		order1.PrintArrOfComparsions();
		cout << endl;

		cout << "Pole cetnosti vymen:" << endl;
		PrintVector(histogramOfChanges.GetHistogram());
		cout << endl;

		cout << "Pole cetnosti porovnani:" << endl;
		PrintVector(histogramOfComparsions.GetHistogram());
		cout << endl;
	}

	vector<int> hChangesToPrint	= histogramOfChanges.GetHistogram();
	vector<int> hComparsionsToPrint	= histogramOfComparsions.GetHistogram();
	string		nameOfFile1 = to_string(order) + "rad_cetosti vymen";
	string		nameOfFile2 = to_string(order) + "rad_cetosti porovnani" ;

	PrintToFileClass file1(hChangesToPrint);
	file1.SetNameOfFile(nameOfFile1);
	file1.SetNameOfValues("pocet vymen");
	file1.MakeFile();

	PrintToFileClass file2(hComparsionsToPrint);
	file2.SetNameOfFile(nameOfFile2);
	file2.SetNameOfValues("pocet porovnani");
	file2.MakeFile();


	cout << "Konec programu" << endl;
	return 0;
}

void PrintVector(vector<int> array) {
	int size = array.size();
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool inputValidation(int toValidate) {
	if (cin.fail()) {
		return false;
	}
	else {
		return true;
	}
}

