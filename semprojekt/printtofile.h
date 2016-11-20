/** \brief soubor obsahujici tridu pro tvorbu souboru
Obsahuje definici tridy.
*  \file printtofile.h
*/

#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
* \class HistogramClass
* \brief Trida pro tvorbu tabulky cetnosti
* \par Popis tridy
* Tato trida slouzi pro tvorbu histogramu ze zadanych vektoru (poli).
*
*\param vector<int>		&ThingsToPrint;
*\param string			NameOfValues;
*\param string			NameOfFile;
*\param string			OutputFolder;
*
* Created on: 5. 11. 2016
*
*/
class PrintToFileClass {
public:
	/** \brief Setter pro vystupni hodnoty
	*	\param[in] string insertName
	*/
	void SetNameOfValues(string insertName);
	
	/** \brief Setter pro nazev souboru
	*	\param[in] string insertName
	*/
	void SetNameOfFile(string insertName);
	
	/** \brief Setter pro velikost vstupniho pole
	*	\param[in] SetOrderOfPermutations - funkce pro nastaveni velikosti pole
	*	\param[out] void
	*/
	void MakeFile();

	/**	\brief Konstruktor pro PrintToFileClass
	*	\param[in] vector<int> &InputVector
	*	\detail Inicializace tridy a provedeni potrebnych procedur.
	*/
	PrintToFileClass(vector<int> &InputVector)
		: ThingsToPrint(InputVector)
	{
		NameOfFile = "default";
		NameOfValues = "default";
		OutputFolder = "Vystup_programu";
	}

private:

	vector<int>		&ThingsToPrint;
	string			NameOfValues;
	string			NameOfFile;
	string			OutputFolder;
	
	/** \brief Tvorba tabulky cetnosti do souboru
	*/
	void PrintToFile();
};