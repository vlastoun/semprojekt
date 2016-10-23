/** \brief Soubor obsahujici tridici algoritmus "bubble sort"
 *  \file bubblesort.h
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
    *vymeny = v;
    *porovnani = p;
}
