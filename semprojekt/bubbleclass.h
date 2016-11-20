/** \brief soubor obsahujici tridu pro experimentalni zjisteni vysledku
Obsahuje definici tridy.
*  \file bubbleclass.h
*/

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
* \class BubbleClass
* \brief Hlavni trida pro splneni ukolu.
* \par Popis tridy
* Tato trida je pro vytvoreni pole porovnani a pole vymen
* pro experimentalni vypocet slozitosti algoritmu Bubblesort.
* Pole se inicializuje velikosti vstupniho pole, tzn velikost 4
* bude obsahovat pole o prvcich {1, 2, 3, 4}. U tohoto pole se dale provedou
* veskere jeho permutace napr.: {1, 3, 2, 4}; {1, 3, 4, 2}........{4, 3, 2, 1}.
* Veskere tyto jednotlive pole jsou setrizeny a do vektoru ArrayOfComparsions
* a ArrayOfChanges jsou zaznamenany pocty vymena porovnani pro jednotlive
* permutace. ArrayOfComparsions a ArrayOfChanges dale slouzi pro vytvoreni
* cetnosti.
* \param 	int				OrderOfPermutation;
* \param	int				NumberOFPermutations;
* \param	vector<int>		InitArray;
* \param	vector<int>		ArrOfComparsions;
* \param	vector<int>		ArrOfChanges;
*
* Created on: 5. 11. 2016
*
*/

class BubbleClass {
public:

	/** \brief Setter pro velikost vstupniho pole
	*	\param[in] SetOrderOfPermutations - funkce pro nastaveni velikosti pole
	*	\param[out] void
	*/
	void SetOrder(int SetOrderOfPermutations);


	/**	\brief Metoda pro vypsani puvodniho pole
	*	\param[out] void
	*	Funkce vypise puvodni vstupni pole do obrazovky konzole
	*/
	void PrintInitArray();


	/**	\brief Metoda pro vypsani pole porovnani
	*	\param[out] void
	*	Funkce vypise pole(vektor) do obrazovky konzole
	*/
	void PrintArrOfComparsions();


	/**	\brief Metoda pro vypsani pole vymen
	*	\param[out] void
	*	Funkce vypise pole(vektor) do obrazovky konzole
	*/
	void PrintArrOfChanges();

	/**	\brief Get ArrayOfChanges
	*	\param[out] void
	*/
	const vector<int> & GetArrayOfChanges();


	/**	\brief Get ArrayOfComparsions
	*	\param[out] void
	*/
	const vector<int> & GetArrayOfComparsions();

	/**	\brief Konstruktor pro BubbleClass
	*	\param[out] void
	*	\detail Inicializace vstupniho radu a provedeni potrebnych operaci.
	*/
	BubbleClass(int order) {
		SetOrder(order);
		InitializeArray(order);
		InputArrayPermutations();
	}



private:

	int				OrderOfPermutation;
	int				NumberOFPermutations;
	vector<int>		InitArray;
	vector<int>		ArrOfComparsions;
	vector<int>		ArrOfChanges;


	/**	\brief Funkce pro vypocet faktorialu
	*	\param[in] number - int pro vypocet faktorialu
	*	\param[out] number! - int faktorial hondoty number
	*/
	int factorial(int order);


	/**	\brief Metoda pro experimentalni urceni slozitosti
	*	\par Popis funkce
	*	Funkce provede veskere permutace vstupniho pole InitArray. Tyto jednotlive permutace
	*	jsou pote setrizeny algoritmem "BUBBLE SORT".
	*	\param[in] -
	*	\param[out] -
	*/
	void InputArrayPermutations();


	/**	\brief Metoda pro pro inicializaci pole
	*	Funkce, ktera inicializuje uvodni pole. Pri zadani radu N bude pole
	*	obsahovat pole o velikosti N prvku a bude obsahovat prvky {1, 2, ..., N}
	*	\param[in] size - int velikost pole
	*	\param[out] void
	*
	*/
	void InitializeArray(int size);


	/**	\brief Tridici algoritmus "BUBBLE SORT"
	*	\par Popis funkce
	*	Funkce setridi vstupni pole a pocita pocet vymen a porovnani.
	*	Tyto hodnoty jsou pote zapsany do vektoru ArrayOfChanges a ArrayOfComparsions.
	*	\param[in] vector<int>& array - vektor k setrizeni
	*	\param[out] void
	*/
	void BubbleSort(vector<int>& array);


	/**	\brief Funkce pro tisk vektoru
	*	\param[in] vector<int>& array
	*	\param[out] - void
	*/
	void PrintVector(vector<int>& array);


	/**	\brief Funkce pro kopirovani vektoru do jineho vektoru
	*	\param[in] vector<int>& FirstVector - vektor, ktery bude kopirovan
	*	\param[in] vector<int>& CopyOfVector - vektor, do ktereho se bude kopirovat
	*/
	void CopyVector(vector<int>& FirstVector, vector<int>& CopyOfVector);
};