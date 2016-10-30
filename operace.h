/** \brief Soubor obsahujici funkce programu
 *  \file operace.h
 *
 */

using namespace std;

/** \brief Funkce pro vypsani pole na obrazovku.
 *
 * \param arr       Vstupni pole, ktere chceme vypsat.
 * \param size      Velikost vstupniho pole.
 *
 */
void PrintArray(int arr[],	const int size){
    for (int i = 0; i < size; i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
}

/** \brief Funkce pro zadani vstupniho pole do programu.
 *  Funkce zada hodnoty pole od 1 do N.
 *  tzn. pole[10] = {1,2,3,4,5,6,7,8,9,10}
 *
 * \param arr       Vstupni pole, ktere chceme vypsat.
 * \param size      Velikost vstupniho pole.
 *
 */
void InitializeArray(int arr[], int size){
    for (int i = 0, j=1 ; i<size; i++, j++){
        arr[i] = j;
    }
}


/** \brief Funkce pro vypocet faktorialu cisla n!.
 *
 * \param n vstupni parametru
 * \return Funkce vraci hodnotu faktorialu vstupniho cisla n.
 *
 */
const int factorial( int n){
    if(n!=1)
    return n*factorial(n-1);
}

void CopyArray (int arr[], int tmp[], const int size){
    for (int i = 0; i < size; i++){
        tmp[i] = arr [i];
    }
}

int ArrayMax (int arr[], const int size){
    int max = 0;
    for (int i = 0; i < size; i++){
        if ( arr[i] > max){
            max = arr[i];
        }
    }
return max;
}
