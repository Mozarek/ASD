#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node* next;
    int value;
};

Node* fixSortedList(Node* L)
{
    Node* sentinel = new Node;
    sentinel->next = L;
    sentinel->value = numeric_limits<int>::min(); // -INF

    Node* f = sentinel->next->next;
    Node* m = sentinel->next;
    Node* l = sentinel;

    //traversing the list with 3 pointers in such order:
    // l->m->f
    // l: last , m: middle , f: first


    //finding wrong element and extracting it from the list
    Node* wrong_element = NULL;

    while( f!=NULL ){
        if(f->value > l->value && !(f->value > m->value && m->value > l->value)){
            wrong_element = m;
            l->next = f;
            break;
        }
        
        l=m;
        m=f;
        f=f->next;
    }
    if(l->value > m->value){
        wrong_element = m;
        l->next = NULL;
    }

    //if the array was still sorted
    if(wrong_element==NULL){
        delete sentinel;
        return L;
    }

    //inserting wrong_element into proper spot in the list
    f = sentinel->next;
    m = sentinel;

    while(f!=NULL && f->value < wrong_element->value){
        m=f;
        f=f->next;
    }

    m->next = wrong_element;
    wrong_element->next = f;

    //returning the head of the fixed list and deleting sentinel
    L = sentinel->next;
    delete sentinel;

    return L;
}

////////////////////////////////////////////////////////
//      UTILITY     FUNCTIONS

void insertHead(Node* &first , int value)
{
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next = first;

    first = new_node;
}


Node* createList(int tab[] , int N)
{
    Node* first = NULL;
    for(int i =N-1 ; i>=0; i--)
        insertHead(first , tab[i]);

    return first;
}

void printList(Node* first)
{
    while(first != NULL){
        cout << first->value << "  ";
        first = first->next;
    }

    cout << endl;
}

int main()
{
    int T[5] = {2,5,7,11,6};

    Node* list = createList(T , 5);

    printList(list);
    list = fixSortedList(list);
    printList(list);

    return 0;

}