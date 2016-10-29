#include <iostream>     // cout, cin
#include <algorithm>    // std::next_permutation, std::sort
#include "operace.h"
#include "bubblesort.h"

/** \brief Hlavni soubor programu
 *  \file main.cpp
 *  \author Vlastimil Sadilek
 *  \mainpage permutace
 */


using namespace std;

void permutace (int zaklPole[],int comp[],int chnges[], int size){
    int changes = 0;
    int comparsions = 0;
    int tmp [size];
    int *pointer1;
    int *pointer2;
    int counter=0;
    do{
        kopPole(zaklPole,tmp,size);
        pointer1 = &changes;
        pointer2 = &comparsions;
        BubbleSort(zaklPole, size, pointer1, pointer2);
        chnges[counter] = changes;
        comp[counter] = comparsions;
        counter++;
    }while (next_permutation(zaklPole,zaklPole+size));
}


int main () {
    int n;                          /**< Vstupni parametr pro volbu velikosti pole. */
    long int citacPermutaci = 0;
    long int pocetPermutaci = 0;
    int vymeny = 0;
    int porovnani = 0;
    int *ukazatel1;
    int *ukazatel2;

    n = 8;
    pocetPermutaci = factorial(n);

    int zpole[n];
    int tmpPole[n];
    int poleVymen[pocetPermutaci];
    int polePorovnani[pocetPermutaci];

    zadejPole(zpole,n);

    do {
        kopPole(zpole,tmpPole,n);
        ukazatel1 = &vymeny;
        ukazatel2 = &porovnani;
        BubbleSort(tmpPole,n,ukazatel1,ukazatel2);
        polePorovnani[citacPermutaci] = porovnani;
        poleVymen[citacPermutaci] = vymeny;
        citacPermutaci++;
    } while (next_permutation(zpole,zpole+n));

    int ArrayOfComparsions [pocetPermutaci];
    int ArrayOfChanges [pocetPermutaci];

    permutace(zpole,ArrayOfComparsions,ArrayOfChanges,n);



    int max = maxPole(polePorovnani,pocetPermutaci)+1;
    int histogram [max];

    for (int i = 0; i < max; i++){
        histogram[i] = 0;
    }

    for (int i = 0; i < max; i++){
        for (long int j = 0; j < pocetPermutaci; j++){
            if (i == polePorovnani[j]){
                histogram[i] = histogram[i]+1;
            }
        }
    }
    long int kontrola = 0;
    for (int i = 0; i < max; i++){
            kontrola = kontrola + histogram[i];

    }


    cout << "histogram"<< endl;

    for (int i = 0; i < max; i++){
        cout << "Pocet vyskytu "<< i << " porovnani:\t" << histogram [i]<< endl;
    }

    cout << endl;

    cout << "kontrola"<< endl;
    cout << kontrola << endl;

    cout << "Celkem probehlo permutaci: " << citacPermutaci <<endl;
    cout << "n!:  " << pocetPermutaci <<endl;
    if (pocetPermutaci != citacPermutaci){
        cout << "KONTROLA: problem v poctu permutaci a vygenerovanych permutacich.";
    } else {
        cout << "Vse probehlo v poradku, permutace jsou OK.";
    }

  return 0;
}

