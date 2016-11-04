#include <vector>;

using namespace std;

class BubbleClass{
public:
	void SetOrder(int SetOrderOfPermutations);
	void PrintOrder();
	BubbleClass(int order) {
		SetOrder(order);
	}
private:
	int OrderOfPermutation;
	vector<int> InitialArray;
	void ArrayInitialize();
};

void BubbleClass::ArrayInitialize() {
	cout << "funkce aray initialize";
}

void BubbleClass::SetOrder(int SetOrderOfPermutations) {
	OrderOfPermutation = SetOrderOfPermutations;
}

void BubbleClass::PrintOrder() {
	cout << "jajaja" << OrderOfPermutation << endl;
}