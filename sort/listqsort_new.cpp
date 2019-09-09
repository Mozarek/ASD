#include <iostream>

struct node
{
    int val;
    node* next;
}

node* quicksortR(node* head)
{
    //exit condition
    if(head== NULL || head->next == NULL)
        return head;

    // first element is the pivot and from the second onward we split the list
    node* pivot = head;
    node* current = pivot->next;

    //constructing two separate lists
    node* lower = NULL;
    node* higher = NULL;

    while(current != NULL)
    {
        if(current->val < pivot->val)
        {
            node* tmp = current->next;
            current->next = lower;
            lower = current;
            current = tmp;
        }else
        {
            node* tmp = current->next;
            current->next = higher;
            higher = current;
            current = tmp;
        }
    }

    // sorting both of them separately
    lower = quicksortR(lower);
    higher = quicksortR(higher);

    // merging two lists and the pivot as follows:
    // [lower->...->current] -> pivot -> [higher->...]
    current = lower;
    while(current->next != NULL) current = current->next;
    current->next = pivot;
    pivot->next = higher;

    return lower;
}