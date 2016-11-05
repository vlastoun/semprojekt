#include <vector>
#include <algorithm>

using namespace std;
class BubbleClass {
public:
	void SetOrder(int SetOrderOfPermutations);
	void PrintInitOrder();
	void PrintArrOfComparsions() {
		PrintVector(ArrOfComparsions);
	}
	void PrintArrOfChanges() {
		PrintVector(ArrOfChanges);
	}

	BubbleClass(int order) {
		SetOrder(order);
		InitializeArray(order);
		InputArrayPermutations();
	}
private:
	int OrderOfPermutation;
	int NumberOFPermutations;

	vector<int> InitArray;
	vector<int> ArrOfComparsions;
	vector<int> ArrOfChanges;
	
	int factorial(int order);

	void InputArrayPermutations();

	void InitializeArray(int size);
	void BubbleSort(vector<int>& array);
	void PrintVector(vector<int>& array);
	void CopyVector(vector<int>& FirstVector, vector<int>& CopyOfVector);
};


int BubbleClass::factorial(int number) {
	if (number != 1) {
		return number*factorial(number - 1);
	}
}

void BubbleClass::SetOrder(int SetOrderOfPermutations) {
	OrderOfPermutation = SetOrderOfPermutations;
	NumberOFPermutations = factorial(SetOrderOfPermutations);
}

void BubbleClass::PrintInitOrder() {
	int size = InitArray.size();
	for (int i = 0; i < size; i++) {
		cout << InitArray[i] << " ";
	}
	cout << endl;
}

void BubbleClass::InitializeArray(int size) {
	for (int i = 0; i < size; i++) {
		InitArray.push_back(i+1);
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
	//cout << "vymen " << changes << endl;
	//cout << "porovnani " << comparsions << endl;
	ArrOfChanges.push_back(changes);
	ArrOfComparsions.push_back(comparsions);
}


void BubbleClass::InputArrayPermutations() {
	int size = InitArray.size();
	int counter = 0;
	vector<int> tmp;
	tmp.resize(size);
	do {
		/*cout << "Permutace " << counter<< endl;*/
		CopyVector(InitArray, tmp);
		/*PrintVector(tmp);*/
		BubbleSort(tmp);
		/*PrintVector(tmp);*/
		/*cout << endl;*/
		counter++;
	} while (std::next_permutation(InitArray.begin(),InitArray.end()));
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