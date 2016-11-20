/** \brief soubor obsahujici implementaci metod tridy
Obsahuje implementaci tridy HistogramClass
*  \file histogram.cpp
*/
#include "histogram.h"

int HistogramClass::GetMax() {
	return MaximumOfHistogram;
}

const vector<int> & HistogramClass::GetHistogram() {
	return histogram;
}

int HistogramClass::MaxOfInputArray() {
	int max = 0;
	for (int i = 0; i < SizeOfInputArray; i++) {
		if (this->InputArray[i] > max) {
			max = this->InputArray[i];
		}
	}
	return max;
}

void HistogramClass::MakeHistogram() {
	int counter = 0;
	
	do {
		histogram.push_back(0);
		counter++;
	} while (counter <= this->MaximumOfHistogram);

	for (int i = 0; i < this->MaximumOfHistogram; i++) {
		for (int j = 0; j < SizeOfInputArray; j++) {
			if (i = InputArray[j]) {
				histogram[i] = histogram[i] + 1;
			}
		}
	}
}