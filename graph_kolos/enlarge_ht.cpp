#include <iostream>

using namespace std;

struct HT{
    int* table;
    int size;
};

int hashf(int x)
{
    return x;
}

void enlarge(HT* ht)
{
    int new_size = 2*ht->size;

    int * new_table = new int[new_size];
    for(int i=0;i<new_size;i++)
        new_table[i] = -1;


    for(int i=0;i<ht->size ; i++)
    {
        if(ht->table[i] >= 0)
        {
            int address = hashf(ht->table[i])%(new_size);
            if(new_table[address] < 0){
                new_table[address] = ht->table[i];
                ht->table[i] = -1;
            }
        }
    }

    for(int i=0;i<ht->size ; i++)
    {
        if(ht->table[i] >= 0)
        {
            int address = hashf(ht->table[i])%(new_size);
            
            while(new_table[address] >= 0) address = (address+1)%new_size;

            new_table[address] = ht->table[i];
        }
    }

    delete[] ht->table;
    ht->table = new_table;
    ht->size = new_size;

    return;
}

void print(HT* ht)
{
    cout << "Current hash_table: " << endl;
    for(int i=0;i<ht->size;i++)
        cout << ht->table[i] << " ";

    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    int *tab = new int[N];
    for(int i=0;i<N;i++)
        cin >> tab[i];

    HT* ht = new HT;
    ht->table = tab;
    ht->size = N;

    enlarge(ht);

    print(ht);

}


