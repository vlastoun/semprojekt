/** \brief soubor obsahujici tridu pro experimentalni zjisteni vysledku
	Obsahuje tridu a jeji metody.
*  \file bubbleclass.h
*/

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
	void SetOrder(int SetOrderOfPermutations) {
		OrderOfPermutation = SetOrderOfPermutations;
		NumberOFPermutations = factorial(SetOrderOfPermutations);
	}
	
	
	/**	\brief Metoda pro vypsani puvodniho pole
	 *	\param[out] void
	 *	Funkce vypise puvodni vstupni pole do obrazovky konzole
	 */
	void PrintInitArray() {
		int size = InitArray.size();
		for (int i = 0; i < size; i++) {
			cout << InitArray[i] << " ";
		}
		cout << endl;
	}
	
	
	/**	\brief Metoda pro vypsani pole porovnani
	*	\param[out] void
	*	Funkce vypise pole(vektor) do obrazovky konzole
	*/
	void PrintArrOfComparsions() {
		PrintVector(ArrOfComparsions);
	}

	/**	\brief Metoda pro vypsani pole vymen
	*	\param[out] void
	*	Funkce vypise pole(vektor) do obrazovky konzole
	*/
	void PrintArrOfChanges() {
		PrintVector(ArrOfChanges);
	}

	/**	\brief Get ArrayOfChanges
	*	\param[out] void
	*/
	const vector<int> & GetArrayOfChanges() {
		return ArrOfChanges;
	}


	/**	\brief Get ArrayOfComparsions
	*	\param[out] void
	*/
	const vector<int> & GetArrayOfComparsions() {
		return ArrOfComparsions;
	}
	
	
	
	/**	\brief Konstruktor pro BubbleClass
	*	\param[out] void
	*	\detailInicializace vstupniho radu a provedeni potrebnych operaci.
	*/
	BubbleClass(int order) {
		SetOrder(order);
		InitializeArray(order);
		InputArrayPermutations();
	}



private:

	/*!> Deklarace radu permutaci*/
	int OrderOfPermutation;

	/*!> Deklarace poctu vsech permutaci*/
	int NumberOFPermutations;

	/*!> Deklarace vektoru permutovaneho pole*/
	vector<int> InitArray;

	/*!> Deklarace vektoru pole porovnani*/
	vector<int> ArrOfComparsions;
	
	/*!> Deklarace vektoru pole zmen*/
	vector<int> ArrOfChanges;
	
	
	/**	\brief Funkce pro vypocet faktorialu
	*	\param[in] number - int pro vypocet faktorialu
	*	\param[out] number! - int faktorial hondoty number
	*/
	int factorial(int order) {
		if (order != 1) {
			return order*factorial(order - 1);
		}
	}

	
	/**	\brief Metoda pro experimentalni urceni slozitosti
	*	\par Popis funkce
	*	Funkce provede veskere permutace vstupniho pole InitArray. Tyto jednotlive permutace
	*	jsou pote setrizeny algoritmem "BUBBLE SORT".
	*	\param[in] -
	*	\param[out] -
	*/
	void InputArrayPermutations() {
		int size = InitArray.size();
		int counter = 0;
		vector<int> tmp;
		tmp.resize(size);
		do {
			/*!< Kopirovani permutovaneho pole do docasneho pole*/
			CopyVector(InitArray, tmp);

			/*!< Setrizeni docasneho pole a vlozeni vysledku do ArrayOfComparsions
			a ArrayOfChanges
			*/
			BubbleSort(tmp);

			counter++;
		} while (std::next_permutation(InitArray.begin(), InitArray.end()));
	}

	
	/**	\brief Metoda pro pro inicializaci pole
	*	Funkce, ktera inicializuje uvodni pole. Pri zadani radu N bude pole
	*	obsahovat pole o velikosti N prvku a bude obsahovat prvky {1, 2, ..., N}
	*	\param[in] size - int velikost pole
	*	\param[out] void
	*	
	*/
	void InitializeArray(int size) {
		for (int i = 0; i < size; i++) {
			InitArray.push_back(i + 1);
		}
	}
	
	
	/**	\brief Tridici algoritmus "BUBBLE SORT"
	*	\par Popis funkce
	*	Funkce setridi vstupni pole a pocita pocet vymen a porovnani.
	*	Tyto hodnoty jsou pote zapsany do vektoru ArrayOfChanges a ArrayOfComparsions.
	*	\param[in] vector<int>& array - vektor k setrizeni
	*	\param[out] void
	*/
	void BubbleSort(vector<int>& array) {
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
		ArrOfChanges.push_back(changes);
		ArrOfComparsions.push_back(comparsions);
	}

	
	/**	\brief Funkce pro tisk vektoru
	*	\param[in] vector<int>& array
	*	\param[out] - void
	*/
	void PrintVector(vector<int>& array) {
		int size = array.size();
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	
	
	/**	\brief Funkce pro kopirovani vektoru do jineho vektoru
	*	\param[in] vector<int>& FirstVector - vektor, ktery bude kopirovan
	*	\param[in] vector<int>& CopyOfVector - vektor, do ktereho se bude kopirovat
	*/
	void CopyVector(vector<int>& FirstVector, vector<int>& CopyOfVector) {
		int size = FirstVector.size();
		for (int i = 0; i < size; i++) {
			CopyOfVector[i] = FirstVector[i];
		}
	}
};