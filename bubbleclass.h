#include <vector>

using namespace std;

class BubbleClass{
public:
	void SetOrder(int SetOrderOfPermutations);
	void PrintInitOrder();
	void SortInitArray();
	BubbleClass(int order) {
		SetOrder(order);
		InitializeArray(order);
	}
private:
	int OrderOfPermutation;

	vector<int> InitArray;
	vector<int> ArrayOfComparsions;
	vector<int> ArrayOfChanges;
	
	void InitializeArray(int size);
	void BubbleSort(vector<int>& array);
};

void BubbleClass::SetOrder(int SetOrderOfPermutations) {
	OrderOfPermutation = SetOrderOfPermutations;
}

void BubbleClass::PrintInitOrder() {
	for (int i = 0; i < InitArray.size(); i++) {
		cout << InitArray[i] << " ";
	}
	cout << endl;
}

void BubbleClass::InitializeArray(int size) {
	for (int i = 0, j = size; i < size; i++, j--) {
		InitArray.push_back(j);
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
}

void BubbleClass::SortInitArray() {
	BubbleSort(InitArray);
}