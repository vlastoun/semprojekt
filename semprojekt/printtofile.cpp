/** \brief soubor obsahujici implementaci metod tridy
Obsahuje implementaci tridy PrintToFileClass
*  \file printtofile.cpp
*/
#include "printtofile.h"

void PrintToFileClass::SetNameOfValues(string insertName) {
	NameOfValues = insertName;
}

void PrintToFileClass::SetNameOfFile(string insertName) {
	NameOfFile = insertName;
}

void PrintToFileClass::MakeFile() {
	PrintToFile();
	cout << "Byl vytvoren soubor: " << this->NameOfFile << ".csv" << endl;
}

void PrintToFileClass::PrintToFile() {
	int		NumberOfRows	= ThingsToPrint.size();
	string	path			= OutputFolder + "/" + NameOfFile + ".csv";

	ofstream OutputFile;
	OutputFile.open(path);
	
	if (OutputFile.fail()) {
		cout << "Problem s vytvorenim souboru" << endl;
	}
	OutputFile << "Pocet " << NameOfValues << ";" << "Cetnost" << endl;
	for (int i = 0; i < NumberOfRows; i++) {
		OutputFile << i << ";" << ThingsToPrint.at(i) << endl;;
	}
	OutputFile.close();
}