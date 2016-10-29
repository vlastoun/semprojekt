/** \brief Soubor obsahujici tridici algoritmus "bubble sort"
 *  \file bubblesort.h
 *
 */


 /** \brief Algoritmus bubblesortu
 *
 * \param a[] Pole urcene k setrizeni;
 * \param N Velikost trideneho pole;
 * \param *vymeny adresa pro ulozeni vymen
 * \param *porovnani adresa pro ulozeni porovnani
 * \return void
 *
 */
void BubbleSort(int a[], const int N, int *vymeny, int *porovnani){
    int Right = N - 1;
    int LastExchangeIndex;
    int v = 0;
    int p = 0;
    do {
        LastExchangeIndex = 0;
        for (int i = 0; i < Right;i++){
            p++;
            if (a[i]>a[i+1]){
                int tmp = a [i];
                a [i] = a [i+1];
                a [i+1] = tmp;
                v = v + 2;
                LastExchangeIndex = i + 1;
            }
        }
    Right = LastExchangeIndex;
    } while (LastExchangeIndex > 0);
    *vymeny = v; /**< priradim hodnoty vymen na tuhle adresu */
    *porovnani = p; /**< priradim hodnoty porovnani na tuhle adresu */
}

/** \brief Hlavní funkce pro tvorbu pole zmen a porovnani.
 *
 * \param EntryArray[] Vstupuje zakladni pole, kde se provadi veskere jeho permutace.
 * \param comp[] Pro vlozeni hodnot do pole porovnani.
 * \param changes[] Pro vlozeni hodnot do pole zmen.
 * \param size Vlozeni velikosti pole.
 * \return void
 *
 */

void permutace (int EntryArray[],int ComparsionArray[],int ChangesArray[], int size){
    vypisPole(EntryArray, size);
    int changes;
    int comparsions;
    int tmp [size];
    int *PointerAtChanges;
    int *PointerAtComparsions;
    int counter=0;

    do{
        kopPole(EntryArray,tmp,size);
        PointerAtChanges = &changes; /**< Prirazeni adresy ukazateli */
        PointerAtComparsions = &comparsions; /**< Prirazeni adresy ukazateli */
        BubbleSort(tmp, size, PointerAtChanges, PointerAtComparsions); /**< Serazeni docasneho pole a prirazeni  */
        ChangesArray[counter] = changes; /**< ulozeni hodnot do pole zmen */
        ComparsionArray[counter] = comparsions; /**< ulozeni hodnot do pole porovnani */
        counter++;
    }while (next_permutation(EntryArray,EntryArray+size));
}

void histogram(int InputArray[], int HistoArray[],int SizeOfArray, int MaxOfHistogram){
    for (int i = 0; i < MaxOfHistogram; i++){
        HistoArray[i]=0;
    }
    for (int i = 0; i <MaxOfHistogram;i++){
        for (int j = 0; j < SizeOfArray; j++){
            if ( i = InputArray[j]){
                HistoArray[i]=HistoArray[i]+1;
            }
        }
    }
}
