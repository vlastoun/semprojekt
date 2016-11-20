/** \brief soubor obsahujici implementaci metod tridy
Obsahuje implementaci tridy BubbleClass
*  \file bubbleclass.cpp
*/
#include "bubbleclass.h"

void BubbleClass::SetOrder(int SetOrderOfPermutations) {
	OrderOfPermutation = SetOrderOfPermutations;
	NumberOFPermutations = factorial(SetOrderOfPermutations);
}

void BubbleClass::PrintInitArray() {
	int size = InitArray.size();
	for (int i = 0; i < size; i++) {
		cout << InitArray[i] << " ";
	}
	cout << endl;
}

void BubbleClass::PrintArrOfComparsions() {
	PrintVector(ArrOfComparsions);
}

void BubbleClass::PrintArrOfChanges() {
	PrintVector(ArrOfChanges);
}

const vector<int> & BubbleClass::GetArrayOfChanges() {
	return ArrOfChanges;
}

const vector<int> & BubbleClass::GetArrayOfComparsions() {
	return ArrOfComparsions;
}

int BubbleClass::factorial(int order) {
	if (order != 1) {
		return order*factorial(order - 1);
	}
}

void BubbleClass::InputArrayPermutations() {
	int size = InitArray.size();
	int counter = 0;
	vector<int> tmp;
	tmp.resize(size);
	do {
		/*!< Kopirovani permutovaneho pole do docasneho pole*/
		CopyVector(InitArray, tmp);

		/*!< Setrizeni docasneho pole a vlozeni vysledku do ArrayOfComparsions
		a ArrayOfChanges
		*/
		BubbleSort(tmp);

		counter++;
	} while (std::next_permutation(InitArray.begin(), InitArray.end()));
}

void BubbleClass::InitializeArray(int size) {
	for (int i = 0; i < size; i++) {
		InitArray.push_back(i + 1);
	}
}

void BubbleClass::BubbleSort(vector<int>& array) {
	int size = array.size();
	int Right = size - 1;
	int LastExchangeIndex;
	int changes = 0;
	int comparsions = 0;
	do {
		LastExchangeIndex = 0;
		for (int i = 0; i < Right; i++) {
			comparsions++;
			if (array[i]>array[i + 1]) {
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				changes = changes + 2;
				LastExchangeIndex = i + 1;
			}
		}
		Right = LastExchangeIndex;
	} while (LastExchangeIndex > 0);
	this->ArrOfChanges.push_back(changes);
	this->ArrOfComparsions.push_back(comparsions);
}

void BubbleClass::PrintVector(vector<int>& array) {
	int size = array.size();
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void BubbleClass::CopyVector(vector<int>& FirstVector, vector<int>& CopyOfVector) {
	int size = FirstVector.size();
	for (int i = 0; i < size; i++) {
		CopyOfVector[i] = FirstVector[i];
	}
}