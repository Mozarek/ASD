#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printTable(int T[], int l ,int r)
{
    while(l<=r)
        cout << T[l++] << " ";

    cout << endl;
}

int median_of5(int tab[], int l, int r)
{
    // basically sorting half of the array (simple selection sort)

    //up to i-1 are sorted
    for(int i=l; i<=(l+r)/2 ; i++)
    {
        int li = i;
        //finding lowest among [i;l+r] inserting in i-th place
        for(int j=i; j<=r; j++)
        {
            if(tab[j]<tab[li])
                li = j;
        }

        swap(tab[li], tab[i]);
    }

    return tab[(l+r)/2];
}

int median_of_medians(int tab[] , int left, int right)
{
    int N = right-left+1;
    int *mTab = new int[N];

    for(int i =0; i<N; i++)
        mTab[i] = tab[left+i];

    while(N>1)
    {
        int j=0;
        int i;
        for(i =4; i<N ; i+=5)
        {
            mTab[j] = median_of5(mTab, i-4, i);
            j++;
        }
        if(i-4<=N-1)
        {
            mTab[j] = median_of5(mTab, i-4, N-1);
            j++;
        }
        N=j;
    }

    int res = mTab[0];
    delete[] mTab;

    return res;
}

int main()
{
    srand(time(NULL));

    const int N = 8;

    int T[N];

    for(int i =0; i<N ;i++)
    {
        T[i] = rand()%20+1;
        cout << T[i] << " ";
    }

    cout << endl;
    cout << "Median: "<< median_of_medians(T , 0  ,N-1);

    return 0;

}