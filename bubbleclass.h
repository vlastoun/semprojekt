#include <vector>

using namespace std;

class BubbleClass{
public:
	void SetOrder(int SetOrderOfPermutations);
	void PrintInitOrder();
	BubbleClass(int order) {
		SetOrder(order);
		InitializeArray(order);
	}
private:
	int OrderOfPermutation;
	vector<int> InitArray;
	void InitializeArray(int size);

};

void BubbleClass::SetOrder(int SetOrderOfPermutations) {
	OrderOfPermutation = SetOrderOfPermutations;
}

void BubbleClass::PrintInitOrder() {
	for (int i = 0; i < InitArray.size(); i++) {
		cout << InitArray[i];
	}
}

void BubbleClass::InitializeArray(int size) {
	for (int i = 0; i < size; i++) {
		InitArray.push_back(i + 1);
	}
}
