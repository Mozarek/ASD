#include <iostream>
#include <random>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* findMiddle(node* first , node* last)
{
    node* f = first; //fast pointer
    node* s = first; //slow pointer

    while(f!=last)
    {
        f = f->next;

        if(f!=last)
        {
            s = s->next;
            f = f->next;
        }
    }

    return s;
}

void mergeLists(node* sentinel , node* mid , node* &last)
{
    node* end_sentinel = last->next;

    node* i_prev = sentinel;
    node* i = i_prev->next;

    node* j_prev = mid;
    node* j = j_prev->next;

    while(j!=end_sentinel && i!=j)
    {
        if(j->data < i->data)
        {
            // inserting j between i_prev and i
            j_prev->next = j->next;
            i_prev->next = j;
            j->next = i;

            //adjusting the pointers
            i_prev = j;
            j = j_prev->next;

        }else
        {
            i_prev = i;
            i = i->next;
        }
        
    }

    //if it happened that mid>last 
    //  we adjust the pointers to maintain 'last' pointing to the indeed last element in the list 
    if( j==end_sentinel )
    {
        last = mid;
        last->next = end_sentinel;
    }
}

void mergeListSort_R(node* sentinel, node* &last)
{
    if(sentinel->next != last)
    {
        node* mid = findMiddle(sentinel->next , last);
        mergeListSort_R(sentinel , mid);
        mergeListSort_R(mid , last);
        mergeLists(sentinel , mid , last);
    }
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

void mergeListSort(node* &first)
{
    node* sentinel = new node;
    sentinel->next = first;

    node* last = getLast(first);
    mergeListSort_R(sentinel , last);

    first = sentinel->next;

    delete sentinel;
}

void insertHead(node* &first , int value)
{
    node* new_node = new node;
    new_node->data = value;
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

void printList(node* first)
{
    while(first != NULL)
    {
        cout << first->data << "  ";
        first = first->next;
    }

    cout << endl;
}

int main()
{
    const int N = 20;

    int tab[N];

    for(int i=0; i<N ; i++)
        tab[i] = rand()%20+1;
    
    node* myList = createList(tab , N);
    printList(myList);

    mergeListSort(myList);
    printList(myList);

    return 0;
}