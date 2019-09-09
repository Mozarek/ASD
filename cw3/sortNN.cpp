#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void swap(int& a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortNNsequence(int tab[], int N)
{
    int poczatki[N];
    int nT[N*N];

    for(int i=0;i<N;i++)
        poczatki[i] = i;

    //sort poczatki so that [ i =< j ] <=> [ tab[poczatki[i]*N + N-1] >= tab[poczatki[j]*N] ]
    // last element of the previous chunk has to be <= than the first elemet of the next one

    //simple insertion sort
    for(int i=0;i<N;i++)
    {
        int li = i;
        for(int j=i+1; j<N;j++)
        {
            if(tab[poczatki[li]*N + N-1] > tab[poczatki[j]*N])
                li = j;
        }

        //swap li with i
        swap(poczatki[li] , poczatki[i]);
    }

    //write into new array IN REVERSE
    for(int p=0;p<N;p++){
        for(int i =0;i<N;i++){
            nT[N*N-1 - (p*N+i)] = tab[poczatki[p]*N+i];
        }
    }

    //copy back into original array
    for(int i=0;i<N*N;i++)
        tab[i] = nT[i];
}

void print(int tab[], int N)
{
    for(int i =0; i<N;i++)
        cout<< tab[i] << " ";

    cout << endl;
}

int main()
{
    srand(time(NULL));
    const int N = 5;

    int tab[N*N];

    tab[0] = 1;

    for(int i=1; i<N*N;i++){
        tab[i] = tab[i-1] + rand()%4;
    }

    print(tab , N*N);

    //shuffle
    int iter = N;
    for(int k=0;k<iter;k++)
    {
        int i=0,j=0;
        while(i==j){
            j = rand()%N;
            i = rand()%N;
        }

        for(int l=0;l<N;l++){
            swap(tab[i*N+l] , tab[j*N+l]);
        }
    }

    print(tab , N*N);

    sortNNsequence(tab , N);

    print(tab , N*N);

    return 0;


}