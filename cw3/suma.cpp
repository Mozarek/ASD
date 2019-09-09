#include <iostream>

bool sum_to_x(int tab[], int N , int x)
{
    int i =0;
    int j = N-1;

    while(i<j)
    {
        if(tab[i] + tab[j] == x)
            return true;
        else if(tab[i] + tab[j] < x)
            i++;
        else
            j--;
        
    }

    return false;
}

int main()