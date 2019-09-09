#include <iostream>

using namespace std;

const int N = 20;

struct data
{
    int key;
    int val;
    bool taken;
    bool deleted;
};

//returns index
int find(data h_tab[] , int N , int key)
{
    int ind = key%N;
    int init_ind = ind;
    while(h_tab[ind].deleted || h_tab[ind].key != key ){
        if(h_tab[ind].taken == false)
            
        ind = (ind+1)%N;
        if(ind==init_ind)
            return -1;
    }

    return ind;
}

//inserts new_pair -> new_value
void insert(data h_tab[] , int N , int new_key , int new_value)
{
    int ind = new_key%N;
    while(h_tab[ind].taken) ind = (ind+1)%N;

    h_tab[ind].taken = true;
    h_tab[ind].deleted = false;
    h_tab[ind].key = new_key;
    h_tab[ind].val = new_value;
}


void delete_element(data h_tab[] , int N , int key)
{
    int i=find(h_tab , N , key);

    if(i!=-1 && h_tab[i].taken){
        h_tab[i].deleted = true;
        h_tab[i].taken = false;
    }
}



void init(data h_tab[] , int N)
{
    for(int i=0 ; i<N ; i++)
    {
        h_tab[i].taken = false;
        h_tab[i].deleted = false;
    }
}

void reorganize(data h_tab[], int N)
{
    for()
    {

    }
}

int main()
{
    data hash_table[N];
    init(hash_table , N);
    


}