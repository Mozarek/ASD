#include <iostream>

using namespace std;

bool arrayLeader(int tab[] , int N)
{
    // Moore's voting algorithm

    int count =0;
    int leader_index;

    for(int i=0 ; i<N ; i++)
    {
        if(count == 0)
            leader_index = i;

        if(tab[i] == tab[leader_index])
        {
            count++;
        }else
        {
            count--;
        }
    }

    if(count > 0)
    {
        int check=0;
        for(int i=0;i<N;i++)
            if(tab[i] == tab[leader_index])
                check++;

        return check > N/2;
    }else
    {
        return false;
    }
    
}

int main()
{
    const int N = 10;
    int tab[N] = {1,3,2,2,4,3,2,3,2,2};

    cout << "Wynik: " << arrayLeader(tab , N);
    
    return 0;
}