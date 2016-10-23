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
    int citacPermutaci = 0;
    int pocetPermutaci = 0;
    int vymeny = 0;
    int porovnani = 0;
    int *ukazatel1;
    int *ukazatel2;

    n = 4;
    pocetPermutaci = factorial(n);

    int zpole[n];
    int tmpPole[n];
    int pocetVymen[pocetPermutaci];
    int pocetPorovnani[pocetPermutaci];

    cout << &porovnani<< endl;
    cout << &vymeny<< endl;

    zadejPole(zpole,n);
    vypisPole(zpole,n);
    cout << endl << endl;

    do {
        kopPole(zpole,tmpPole,n);
        vypisPole(tmpPole,n);
        cout << '\t' << "Setrizene pole: ";
        ukazatel1 = &vymeny;
        ukazatel2 = &porovnani;
        BubbleSort(tmpPole,n,ukazatel1,ukazatel2);
        vypisPole(tmpPole,n);
        pocetPorovnani[citacPermutaci] = porovnani;
        pocetVymen[citacPermutaci] = vymeny;
        cout << '\t'<< "PV:" << vymeny;
        cout << '\t'<< "PP:" << porovnani;
        cout << endl;
        citacPermutaci++;
    } while (next_permutation(zpole,zpole+n));

    cout << "Pole vymen"<< endl;
    vypisPole(pocetVymen,pocetPermutaci);
    cout << endl;
    cout << "Pole porovnani" << endl;
    vypisPole(pocetPorovnani,pocetPermutaci);
    cout << endl;

    cout << "Celkem probehlo permutaci: " << citacPermutaci <<endl;
    cout << "n!:  " << pocetPermutaci <<endl;
    if (pocetPermutaci != citacPermutaci){
        cout << "KONTROLA: problem v poctu permutaci a vygenerovanych permutacich.";
    } else {
        cout << "Vse probehlo v poradku, permutace jsou OK.";
    }

  return 0;
}

