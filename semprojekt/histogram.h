/** \brief soubor obsahujici tridu pro tvorbu tabulky cetnosti
Obsahuje definici tridy.
*  \file histogram.h
*/

#pragma once
#include <vector>


/**
* \class HistogramClass
* \brief Trida pro tvorbu tabulky cetnosti
* \par Popis tridy
* Tato trida slouzi pro tvorbu histogramu ze zadanych vektoru (poli).
*\param vector<int>		&InputArray;
*\param vector<int>		histogram;
*\param int				SizeOfInputArray;
*\param int				MaximumOfHistogram;
*
* Created on: 5. 11. 2016
*
*/
using namespace std;
class HistogramClass {
public:
	int GetMax();

	/** \brief Ziskani tabulky cetnosti jako vektoru
	*	\param[out] vector<int> & GetHistogram()
	*/
	const vector<int> & GetHistogram();
	
	/**	\brief Konstruktor pro HistogramClass
	*	\param[in] vector<int> &InputVector
	*	\detail Inicializace tridy a provedeni potrebnych procedur.
	*/
	HistogramClass(vector<int> &InputVector)
		: InputArray(InputVector)
	{
		MaxOfInputArray();
		SizeOfInputArray = InputArray.size();
		MaximumOfHistogram = MaxOfInputArray();
		MakeHistogram();
	}

private:
	vector<int>		&InputArray;
	vector<int>		histogram;
	int				SizeOfInputArray;
	int				MaximumOfHistogram;

	/** \brief Funkce nalezne maximalni hodnotu vstupniho pole InputArray 
	*	\param[out] max - maximalni hodnota vstupniho pole
	*/
	int MaxOfInputArray();
	
	/** \brief Funkce pro tvorbu tabulky cetnosti
	* Funkce nejdrive inicializuje pole hodnotami 0, pote pri nalezeni vyskytu prida hodnotu;
	*/
	void MakeHistogram();
};