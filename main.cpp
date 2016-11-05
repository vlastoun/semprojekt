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
	int MaxSize;
	vector<BubbleClass> Permutations;
	
	cout << "Zadejte maximalni velikost pole:" << endl;
	cin >> MaxSize;
	for (int i = 0; i < MaxSize; i++) {
		Permutations.push_back(BubbleClass(i+1));
	}
	cout << "Pole urcena k permutacim" << endl;
	for (int i = 0; i < MaxSize; i++) {
		Permutations[i].PrintInitArray();
	}
	vector < vector<int>> ArrayOfComparsions;
	
	for (int i = 0; i < MaxSize; i++) {
		ArrayOfComparsions[i].push_back() = Permutations[i].GetArrayOfComparsions;
	}



	return 0;
}

