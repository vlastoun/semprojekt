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

	//PrintArray(ArrayOfChanges, NumberOfPermutations);
	//PrintArray(ArrayOfComparsions, NumberOfPermutations);


	int MaxOfChanges = ArrayMax(ArrayOfChanges, NumberOfPermutations)+1;
	int *HistogramOfChanges;
	HistogramOfChanges = new int[MaxOfChanges];
	histogram(ArrayOfChanges, HistogramOfChanges, NumberOfPermutations, MaxOfChanges);
	//PrintArray(HistogramOfChanges, MaxOfChanges);
	

	int MaxOfComparsions = ArrayMax(ArrayOfComparsions, NumberOfPermutations)+1;
	int *HistogramOfComparsions;
	HistogramOfComparsions = new int(MaxOfComparsions);
	histogram(ArrayOfComparsions, HistogramOfComparsions, NumberOfPermutations, MaxOfComparsions);
	//PrintArray(HistogramOfComparsions, MaxOfComparsions);

	delete[] ArrayOfChanges;
	delete[] ArrayOfComparsions;
	delete[] HistogramOfChanges;
	delete[] HistogramOfChanges;

  return 0;
}

