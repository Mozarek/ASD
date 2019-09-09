/*

t(pesel) -> nazwisko

baza ~40mln osób

1) sortujemy tablice i query to bin_search

2) mamy tablice t[40 mln] , query to O(1)

3) tablica[data urodzenia] - lista osob urodzonych w tym samym dniu

4)hash table

hash(key) = address

//////////////////
adresowanie otwarte:

//zwraca adres pod ktorym znajduje sie klucz
int find(T , key)
{
    int kn = numerize(key);

    for(int i=0;i<N;i++)
    {
        int address = hash(kn , i);
        if(!T[address].taken)
            return -1;
        if(T[address].surname == key)
            return address;
    }

    cout << "Problem: tablica przepelniona. Przeszukano całą tablice :(" << endl;
    return -1;
}