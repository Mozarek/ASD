#include <iostream>
#include <cstdlib>

using namespace std;

void merge(int*, int, int, int);

void mergeSort(int tab[] , int left , int right, int& inv_count)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(tab, left , mid , inv_count);
        mergeSort(tab, mid+1 , right , inv_count);
        merge(tab , left, mid, right , inv_count);
    }
}

void merge(int tab[] , int left, int mid, int right , int &inv_count)
{
    int* n_tab = new int[right-left+1];

    int i = left;
    int j = mid+1;

    int k=0;

    while(i<=mid && j<=right)
    {
        if(tab[i]<tab[j])
            n_tab[k++] = tab[i++];
        else
        {
            n_tab[k++] = tab[j++];
            inv_count+= mid-i+1;
    }

    while(i<=mid)
    {
        n_tab[k++] = tab[i++];
        inv_count
    }
    while(j<=right)
        n_tab[k++] = tab[j++];
    
    for(k=0 ; k<right-left+1 ; k++)
        tab[left+k] = n_tab[k];

    delete[] n_tab;
}

int main()
{
    const int N = 10;

    int tablica[N];

    for(int i =0; i<N ;i++)
    {
        tablica[i] = rand()%20+1;
        cout << tablica[i] << " ";
    }
    cout << endl;

    mergeSort(tablica , 0 , N-1);

    for(int i =0; i<N ;i++)
        cout << tablica[i] << " ";
    cout << endl;

    return 0;
}