#include <iostream>
#include <random>

using namespace std;

struct node
{
    int val;
    node* next;
};



node* partition(node* &first , node* &last)
{
    node* sentinel = new node;
    sentinel->next = first;
    first = sentinel;

    node* pivot = last;

    node* prev = sentinel;
    node* tmp = sentinel->next;

    while(tmp!= pivot)
    {
        if(tmp->val > pivot->val)
        {
            prev->next = tmp->next;
            last->next = tmp;
            tmp->next = NULL;
            last = tmp;

            tmp = prev->next;
        }else
        {
            prev = tmp;
            tmp = tmp->next;
        }
        
    }

    first = sentinel->next;

    if(prev  != sentinel)
    {
        delete sentinel;
        return prev;
    }else
    {
        delete sentinel;
        return first;
    }
    
}

void list_qsortR(node* &first , node* &last)
{
    //base condition
    if(first == last)
        return;

    //pivot element is assumed to be 'last' in the partition function
    node* pivot = last;
    node* pre_pivot = partition(first, last); //partition automatically updates first and last

    //recursively sort both sides of pivot
    // (in the left side we first disconnect pre_pivot from pivot and then reconnect)
    if(pre_pivot != pivot)
    {
        pre_pivot->next = NULL;
        list_qsortR(first , pre_pivot);
        pre_pivot->next = pivot;
    }

    if(pivot != last)
        list_qsortR(pivot->next , last);
}

node* getLast(node* first)
{
    node* prev = NULL;

    while(first != NULL){
        prev = first;
        first = first->next;
    }

    return prev;
}

void list_qsort(node* &first)
{
    node* end = getLast(first);

    list_qsortR(first , end);
    /*node* pivot = end;

    node* xd = partition(first , end);

    cout << "XD: " << xd->val << endl;
    cout << "PIVOT NEXT: " << pivot->next->val << endl;*/
}

void insertHead(node* &first , int value)
{
    node* new_node = new node;
    new_node->val = value;
    new_node->next = first;

    first = new_node;
}


node* createList(int tab[] , int N)
{
    node* first = NULL;
    for(int i =N-1 ; i>=0; i--)
        insertHead(first , tab[i]);

    return first;
}

int main()
{
    const int N = 10;

    int tab[N];

    for(int i=0; i<N ; i++)
        tab[i] = rand()%20+1;
    
    node* myList = createList(tab , N);
    printList(myList);

    list_qsort(myList);
    printList(myList);

    return 0;
}