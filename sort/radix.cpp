#include <iostream>
#include <random>

using namespace std;

void counting_sort(int A[], int N , int k) // A - input ; B - output
{
    // C - auxillary table
    int* C = new int[N];
    int* B = new int[N];

    // initialize C with zeroes
    for(int i =0; i<N;i++)
        C[i] = 0;

    // C[i] will contain number of elements equal to i
    for(int i =0; i<N; i++)
        C[ (A[i]/k)%N ]++;

    // C[i] will contain number of elements less or equal to i
    //      => i in a sorted array should be at position C[i] (more or less) 
    for(int i =1; i<N; i++)
        C[i] += C[i-1];

    // iterating backwards to ensure stability
    for(int i= N-1 ; i>=0 ; i--)
    {
        C[ (A[i]/k)%N ]--;
        B[ C[ (A[i]/k)%N ] ] = A[i];
    }

    //copy B -> A
    for(int i =0; i<N ; i++)
        A[i] = B[i];

    delete[] C;
    delete[] B;
}

void radix_sort(int T[] , int N)
{
    //assuming k = N^2 as in the task


    cout << "XD";
    counting_sort(T , N , 1);
    cout <<"XDD";
    counting_sort(T , N , N);
}

int main()
{

    const int N = 20;
    int T[N];

    for(int i =0; i<N; i++)
    {
        T[i] = rand()%(N*N);
        cout << T[i] << " ";
    }
        cout << endl;
    
    radix_sort(T , N);

    for(int i =0; i<N; i++)
        cout << T[i] << " ";

    cout << endl;

    return 0;
}