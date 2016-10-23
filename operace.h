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
void vypisPole(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i]<< " ";
    }
}

/** \brief Funkce pro zadani vstupniho pole do programu.
 *  Funkce zada hodnoty pole od 1 do N.
 *  tzn. pole[10] = {1,2,3,4,5,6,7,8,9,10}
 *
 * \param arr       Vstupni pole, ktere chceme vypsat.
 * \param size      Velikost vstupniho pole.
 *
 */
void zadejPole(int arr[], int size){
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
long int factorial(int n)
{
    if(n!=1)
    return n*factorial(n-1);
}

void kopPole (int arr[], int tmp[], int size){
    for (int i = 0; i < size; i++){
        tmp[i] = arr [i];
    }
}

int maxPole (int arr[], int size){
    int max = 0;
    for (int i = 0; i < size; i++){
        if ( arr[i] > max){
            max = arr[i];
        }
    }
return max;
}
