#include <iostream>

using namespace std;

int goodThief(int A[] , int n)
{
    if(n==1) return A[0];

    int f[n];
    f[0]= A[0];
    f[1]= max(A[0] , A[1]);

    for(int i=2; i<n;i++){
        f[i] = max(f[i-1] , f[i-2] + A[i]);
    }

    return f[n-1];
}

int main()
{
    int N = 8;
    int A[N] = {1,45,8,10,23,43, 79, 28};

    cout << goodThief(A, N);
}