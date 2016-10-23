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

    //cout << &porovnani<< endl;
    //cout << &vymeny<< endl;

    zadejPole(zpole,n);
    vypisPole(zpole,n);
    cout << endl << endl;

    do {
        kopPole(zpole,tmpPole,n);
        //vypisPole(tmpPole,n);
        //cout << '\t' << "Setrizene pole: ";
        ukazatel1 = &vymeny;
        ukazatel2 = &porovnani;
        BubbleSort(tmpPole,n,ukazatel1,ukazatel2);
        //vypisPole(tmpPole,n);
        polePorovnani[citacPermutaci] = porovnani;
        poleVymen[citacPermutaci] = vymeny;
        //cout << '\t'<< "PV:" << vymeny;
        //cout << '\t'<< "PP:" << porovnani;
        //cout << endl;
        citacPermutaci++;
    } while (next_permutation(zpole,zpole+n));

    //sort(polePorovnani,polePorovnani+pocetPermutaci);
    //sort(poleVymen,poleVymen+pocetPermutaci);

    //cout << "Pole vymen"<< endl;
    //vypisPole(poleVymen,pocetPermutaci);
    //cout << endl;
    //cout << "Pole porovnani" << endl;
    //vypisPole(polePorovnani,pocetPermutaci);
    //cout << endl<<endl;


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

