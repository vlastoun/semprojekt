#pragma once
#include <vector>
using namespace std;
class HistogramClass {
public:
	int GetMax() {
		return MaximumOfHistogram;
	}

	const vector<int> & GetHistogram() {
		return histogram;
	}


	HistogramClass(vector<int> &InputVector)
		: InputArray(InputVector)
	{
		MaxOfInputArray();
		SizeOfInputArray = InputArray.size();
		MaximumOfHistogram = MaxOfInputArray();
		MakeHistogram();
	}

private:
	std::vector<int> &InputArray;
	std::vector<int> histogram;
	int SizeOfInputArray;
	int MaximumOfHistogram;


	int MaxOfInputArray() {
		int max = 0;
		for (int i = 0; i < SizeOfInputArray; i++) {
			if (InputArray[i] > max) {
				max = InputArray[i];
			}
		}
		return max;
	}

	void MakeHistogram() {
		int counter = 0;
		do {
			histogram.push_back(0);
			counter++;
		} while (counter <= MaximumOfHistogram);
		for (int i = 0; i < MaximumOfHistogram; i++) {
			for (int j = 0; j < SizeOfInputArray; j++) {
				if (i = InputArray[j]) {
					histogram[i] = histogram[i] + 1;
				}
			}
		}
	}
};