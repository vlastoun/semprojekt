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

    n = 4;
    pocetPermutaci = factorial(n);

    int zpole[n];
    int permPole[pocetPermutaci][n];

    zadejPole(zpole,n);
    vypisPole(zpole,n);
    cout << endl << endl;

    do {
        for (int i = 0; i < n; i++){
            permPole[citacPermutaci][i] = zpole[i];
        }
        citacPermutaci++;
    } while (next_permutation(zpole,zpole+n) );


    for (int j = 0; j < citacPermutaci; j++){
            for (int i = 0; i < n; i++){
               cout << permPole[j][i]<<"  ";
            }
            cout << endl;
    }


    cout << "Celkem probehlo permutaci: " << citacPermutaci <<endl;
    cout << "n!:  " << pocetPermutaci <<endl;

  return 0;
}

