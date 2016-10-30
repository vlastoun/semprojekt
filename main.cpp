#include <iostream>     // cout, cin
#include <algorithm>    // std::next_permutation, std::sort
#include "operace.h"
#include "bubblesort.h"

/** \brief Hlavni soubor programu
 *  \file main.cpp
 *  \author Vlastimil Sadilek
 *  \mainpage permutace
 */


using namespace std;



int main () {
	int SizeOfInputArray = 4;
	int *InputArray;
	InputArray = new int[SizeOfInputArray]; 
	InitializeArray(InputArray, SizeOfInputArray);


	int NumberOfPermutations = factorial(SizeOfInputArray);
	int *ArrayOfComparsions;
	ArrayOfComparsions = new int[NumberOfPermutations];
	int *ArrayOfChanges;
	ArrayOfChanges = new int[NumberOfPermutations];

	permutace(InputArray, ArrayOfComparsions, ArrayOfChanges, SizeOfInputArray);

	PrintArray(ArrayOfChanges, NumberOfPermutations);
	PrintArray(ArrayOfComparsions, NumberOfPermutations);


	int MaxOfChanges = ArrayMax(ArrayOfChanges, NumberOfPermutations);
	int *HistogramOfChanges;
	HistogramOfChanges = new int[MaxOfChanges];
	histogram(ArrayOfChanges, HistogramOfChanges, NumberOfPermutations, MaxOfChanges);
	PrintArray(HistogramOfChanges, MaxOfChanges);

	int MaxOfComparsions = ArrayMax(ArrayOfComparsions, NumberOfPermutations);
	int *HistogramOfComparsions;
	HistogramOfComparsions = new int(MaxOfComparsions);
	histogram(ArrayOfComparsions, HistogramOfComparsions, NumberOfPermutations, MaxOfComparsions);
	PrintArray(HistogramOfComparsions, MaxOfComparsions);



/*
const int numb = 4;
const int pocetPermutaci = 12;
int zpole[numb];
zadejPole(zpole,numb);
int ArrayOfComparsions[pocetPermutaci];
int ArrayOfChanges [pocetPermutaci];
permutace(zpole,ArrayOfComparsions,ArrayOfChanges,numb);
*/

/*
const int MaxOfChanges = 100;
int HistoOfChanges[MaxOfChanges];
histogram(ArrayOfChanges,HistoOfChanges,pocetPermutaci,MaxOfChanges);
vypisPole(HistoOfChanges,MaxOfChanges);

const int MaxOfComparsions = 100;
int HistoOfComp[MaxOfComparsions];
histogram(ArrayOfComparsions,HistoOfComp,pocetPermutaci,MaxOfComparsions);
vypisPole(HistoOfComp,MaxOfComparsions);
int a;
cin >> a;

*/

  return 0;
}

