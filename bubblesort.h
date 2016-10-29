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

/** \brief Hlavní funkce pro tvorbu pole zmen a porovnani.
 *
 * \param zaklPole[] Vstupuje zakladni pole, kde se provadi veskere jeho permutace.
 * \param comp[] Pro vlozeni hodnot do pole porovnani.
 * \param changes[] Pro vlozeni hodnot do pole zmen.
 * \param size Vlozeni velikosti pole.
 * \return void
 *
 */

void permutace (int zaklPole[],int comp[],int chnges[], int size){
    vypisPole(zaklPole, size);
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
        BubbleSort(tmp, size, pointer1, pointer2);
        chnges[counter] = changes;
        comp[counter] = comparsions;
        counter++;
    }while (next_permutation(zaklPole,zaklPole+size));
}
