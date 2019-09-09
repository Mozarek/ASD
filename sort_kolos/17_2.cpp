#include <iostream>
#include <algorithm>

using namespace std;

int median5(int T[] , int p , int n)
{
    sort(T+p , T+p+n);
    return T[p+n/2];
}

int partition(int T[] , int p , int q , int pivot)
{
    //swap the pivot with the last element
    int i=p;
    while(T[i] != pivot) i++;

    swap(T[i] , T[q]);

    i = p;
    for(int j = p; j<=q-1 ; j++)
    {
        if(T[j]<pivot)
        {
            swap(T[i] , T[j]);
            i++;
        }
    }

    swap(T[i] , T[q]);

    return i;
}

int select(int T[] , int p , int q , int k)
{
    if(p==k && k==0)
        return T[p];

    //find the pivot
    int n = q-p+1;
    int* t_piatki =  new int[(n+4)/5];

    int i;
    for(i=0; i<n/5 ; i++){
        t_piatki[i] = median5(T , p+i*5 , 5);
    }
    if(i*5<n){
        t_piatki[i] = median5(T , p+i*5 , n%5);
        i++;
    }

    int pivot = select(t_piatki , 0 , i-1 , i/2);
    delete[] t_piatki;

    int x = partition(T , p , q , pivot);
    
    if(p+k==x)
        return T[p+k];
    if(k > x)
        return select(T , x+1 , q , k-(x+1));
    else
        return select(T , p , x-1 , k);

}

int sumBetween(int T[] , int from , int to , int n)
{
    int low = select(T , 0 , n-1 , from);
    int high = select(T , 0 , n-1 , to);
    
    int sum = 0;

    for(int i=0;i<n;i++){
        if(T[i] >= low && T[i] <= high){
            sum+= T[i];
        }
    }

    return sum;
}

int main()
{
    int N = 10;
    int tab[N] = {3, 45, 23, 25 , 19 , 63 , 91 , 70 , 41 , 39};

    for(int i=0 ; i<N ; i++)
        cout << select(tab , 0  ,N-1 , i) << " ";
}