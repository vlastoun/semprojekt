#include <iostream>     // cout, cin
#include <algorithm>    // std::next_permutation, std::sort
#include "operace.h"
#include "bubblesort.h"
#include <fstream>
#include <string>

/** \brief Hlavni soubor programu
 *  \file main.cpp
 *  \author Vlastimil Sadilek
 *  \mainpage permutace
 */


using namespace std;



int main () {
    int n = 8;                          /**< Vstupni parametr pro volbu velikosti pole. */
    int pocetPermutaci = 0;
    pocetPermutaci = factorial(n);
    int zpole[n];
    int ArrayOfComparsions [pocetPermutaci];
    int ArrayOfChanges [pocetPermutaci];

    zadejPole(zpole,n);
    permutace(zpole,ArrayOfComparsions,ArrayOfChanges,n);

    int MaxOfChanges = maxPole(ArrayOfChanges,pocetPermutaci)+1;
    int HistoOfChanges[MaxOfChanges];
    histogram(ArrayOfChanges,HistoOfChanges,pocetPermutaci,MaxOfChanges);
    vypisPole(HistoOfChanges,MaxOfChanges);


    int MaxOfComparsions = maxPole(ArrayOfComparsions,pocetPermutaci)+1;
    int HistoOfComp[MaxOfComparsions];
    histogram(ArrayOfComparsions,HistoOfComp,pocetPermutaci,MaxOfComparsions);
    vypisPole(HistoOfComp,MaxOfComparsions);



  return 0;
}

