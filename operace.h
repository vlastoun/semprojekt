using namespace std;

void vypisPole(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i]<<"  ";
    }
}



void zadejPole(int arr[], int size){
    for (int i = 0, j=1 ; i<size; i++, j++){
        arr[i] = j;
    }
}

int factorial(int n)
{
    if(n!=1)
     return n*factorial(n-1);
}
