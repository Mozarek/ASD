#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    double value;   
};

void insert(Node* &list , Node* element)
{
    //find the proper spot for the element
    Node* first = list;
    Node* prev = NULL;

    while(first!= NULL && first->value < element->value){
        prev = first;
        first = first->next;
    }
    //now the element should be inserted between prev and first

    if(prev == NULL){
        element->next = list;
        list = element;
    }else{
        prev->next = element;
        element->next = first;
    }
}

void sort(Node* list)
{
    //count number of elements
    int n = 0;
    Node* tmp = list->next;
    while(tmp!= NULL){
        n++;
        tmp = tmp->next;
    }

    //create n buckets
    Node** buckets = new Node*[n];

    for(int i=0; i<n;i++)
        buckets[i] = NULL;
    
    //go through the list and insert nodes to proper buckets
    tmp = list->next;
    Node* prev =NULL;

    while(tmp!=NULL)
    {
        prev = tmp;
        tmp = tmp->next;

        //insertion keeps the list in the bucket sorted
        insert(buckets[int(prev->value/10.0*n)] , prev);
        prev = NULL;
    }


    //connecting all the buckets into one linked-list with sentinel being 'list';
    Node* prev_bucket = list;

    for(int i=0;i<n;i++)
    {
        prev_bucket->next = buckets[i];
        while(prev_bucket->next != NULL)
            prev_bucket = prev_bucket->next;
    }

    //freeing the space
    delete[] buckets;
}


///////////////////////////////////////////
//utility
void insertHead(Node* &first , double value)
{
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next = first;

    first = new_node;
}


Node* createList(double tab[] , int N)
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
    double T[10] = {1.02 , 5.08 , 6.3 , 2.0 , 9.7 , 3.97 , 2.45 , 2.76 , 7.01 , 2.51};

    Node* list = createList(T , 10);

    insertHead(list , -1);

    printList(list);
    sort(list);
    printList(list);

    return 0;

}