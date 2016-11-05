#include <vector>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

class PrintToFileClass {
public:
	void SetNameOfValues(string insertName) {
		NameOfValues = insertName;
	}
	void SetNameOfFile(string insertName) {
		NameOfFile = insertName;
	}
	void MakeFile() {
		PrintToFile();
	}

	PrintToFileClass(vector<int> &InputVector)
		: ThingsToPrint(InputVector)
	{
		NameOfFile = "default";
		NameOfValues = "default";
		OutputFolder = "Vystup_programu";
	}

private:
	std::vector<int> &ThingsToPrint;
	string NameOfValues;
	string NameOfFile;
	string OutputFolder;
	
	
	void PrintToFile() {		
		int NumberOfRows = ThingsToPrint.size();
		string path = OutputFolder + "/" + NameOfFile + ".csv";
		ofstream OutputFile(path);
		for (int i = 0; i < NumberOfRows; i++) {
			OutputFile << "Pocet " << i << " "
				<< NameOfValues << ":" << ";" << ThingsToPrint[i] << endl;;
		}
	}
};