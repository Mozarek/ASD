#include <iostream>
#include <algorithm> 

using namespace std;

struct n_el_table
{
    int a_pos;
    int sum=0;
};

bool comp(n_el_table a, n_el_table b)
{
    return a.sum <= b.sum;
}

void SumSort(int A[] , int B[] , int n)
{
    n_el_table b_positions[n];

    for(int i=0; i<n ;i++)
    {
        b_positions[i].a_pos = i;
        b_positions[i].sum = 0;
        for(int j=0 ; j<n ; j++)
            b_positions[i].sum += A[n*i+j];
    }

    sort(b_positions , b_positions + n , comp);

    for(int i=0; i<n;i++)
    {
        for(int j=0 ; j<n ; j++)
            B[n*i+j] = A[n*b_positions[i].a_pos+j];
    }
}

int main()
{
    int N = 4;
    int A[N*N] = {2,4,5,6,10,15,20,17,95,91,86,75,50,46,39,62};
    int B[N*N];

    SumSort(A , B , N);

    for(int i=0; i<N*N ; i++)
        cout << B[i] << " ";
}