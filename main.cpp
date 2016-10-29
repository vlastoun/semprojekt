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
    long int pocetPermutaci = 0;
    n = 5;
    pocetPermutaci = factorial(n);
    int zpole[n];
    zadejPole(zpole,n);
    int ArrayOfComparsions [pocetPermutaci];
    int ArrayOfChanges [pocetPermutaci];
    permutace(zpole,ArrayOfComparsions,ArrayOfChanges,n);

  return 0;
}

