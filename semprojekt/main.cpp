/** \brief Hlavni soubor programu semprojekt
*  \file main.cpp
*  \author Vlastimil Sadilek SAD045
*  \mainpage Algoritmy: Zadani 4 - Bubblesort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "bubbleclass.h"
#include "histogram.h"
#include "printtofile.h"


using namespace std;

void PrintVector(vector<int> array);
bool toConsoleValidation(string str, bool& outputToConsole);

int main() {
	int order;
	bool outputToConsole =  false;
	int counter = 0; /**< citac pro spatne vstupy */
	string choiceOfConsoleIO;

	/** Menu programu
	*  
	*/
	cout << "Zadejte rad permutace - kladne cislo od 1:" << endl;
	cin >> order;
	while (cin.fail()||order <1) {
		cout << "Spatne zadany vstup" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> order;
		counter++;
		if (counter == 10) {
			order = 5;
			cout << "Mnoho spatnych vstupu zvolen rad permutace 5" << endl;
			break;
		}
	}

	cout << "Chcete vystup do konzole? zadejte volbu A/N :" << endl;
	counter = 0;
	cin >> choiceOfConsoleIO;
	while (toConsoleValidation(choiceOfConsoleIO, outputToConsole)) {
		cout << "Spatne zadany vstup" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> choiceOfConsoleIO;
		counter++;
		if (counter == 10) {
			cout << "Mnoho spatnych vstupu vystup do konzole vypnut" << endl;
			outputToConsole = false;
			break;
		}
	}
	

	/** Tvorba histogramu
	*
	*/
	BubbleClass permutations(order);

	vector<int>	arrayOfChanges		= permutations.GetArrayOfChanges();
	vector<int>	arrayOfComparsions	= permutations.GetArrayOfComparsions();

	HistogramClass histogramOfChanges(arrayOfChanges);
	HistogramClass histogramOfComparsions(arrayOfComparsions);
	
	/** Vystup do konzole
	*
	*/
	if (outputToConsole) {
		cout << "Vstupni pole:" << endl;
		permutations.PrintInitArray();
		cout << endl;

		cout << "Pole vymen:" << endl;
		permutations.PrintArrOfChanges();
		cout << endl;

		cout << "Pole porovnani:" << endl;
		permutations.PrintArrOfComparsions();
		cout << endl;

		cout << "Pole cetnosti vymen:" << endl;
		PrintVector(histogramOfChanges.GetHistogram());
		cout << endl;

		cout << "Pole cetnosti porovnani:" << endl;
		PrintVector(histogramOfComparsions.GetHistogram());
		cout << endl;
	}

	/** Vystup do souboru
	*
	*/
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

	/** Konec programu
	*
	*/
	cout << endl << "Konec programu" << endl << endl;
	return 0;
}

/** Definice pomocne funkce pro tisk vektoru do konzole
*	\param[in] vector<int> vec
*/
void PrintVector(vector<int> vec) {
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		cout << vec.at(i) << " ";
	}
	cout << endl;
}


/**	\brief	Kontrola vstupu pro vystup do konzole a nstaveni promenne na tisk konzole
*	\param[in] vector<int> &InputVector
*	\param[out] true pri spatnem vstupu, false pri spravnem vstupu
*/
bool toConsoleValidation(string str, bool& outputToConsole) {
	if (!str.compare("a") || !str.compare("A")) {
		outputToConsole = true;
		return false;
	}
	else if (!str.compare("n") || !str.compare("N")) {
		outputToConsole = false;
		return false;
	}
	else {
		return true;
	}

}

