#include <iostream>
#include <string>

using namespace std;

void sortString_onPos(string A[] , int l , int r , int pos)
{
    int n = r-l+1;
    int* B = new int[26];
    string* C = new string[n];

    for(int i=0; i<26 ; i++)
        B[i] = 0;

    for(int i=0; i<n ; i++)
        B[A[l+i][pos]-'a']++;

    for(int i=1;i<26;i++)
        B[i]+= B[i-1];

    for(int i=n-1; i>=0;i++)
    {
        B[A[l+i][pos]-'a']--;
        C[B[A[l+i][pos]-'a']] = A[l+i];
    }

    for(int i=0; i<n ; i++)
        A[l+i] = C[i];

    delete[] C;
    delete[] B; 
}


void sortString(string A[] , int n)
{
    sortString_onPos(A , 0 , n-1 , 0); 
}