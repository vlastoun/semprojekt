/** \brief Soubor obsahujici tridici algoritmus "bubble sort"
 *  \file bubblesort.h
 *
 */

 void BubbleSort(int a[], const int N){
    int Right = N - 1;
    int LastExchangeIndex;
    do {
        LastExchangeIndex = 0;
        for (int i = 0; i < Right;i++){
            if (a[i]>a[i+1]){
                int tmp = a [i];
                a [i] = a [i+1];
                a [i+1] = tmp;
                LastExchangeIndex = i + 1;
            }
        }
    Right = LastExchangeIndex;
    } while (LastExchangeIndex > 0);
    }
