#include <iostream>

using namespace std;

struct SLNode
{
    int value;
    SLNode**;
}

struct SkipList
{
    SLNode* head;
    SLnode* tail;
    int max_level;
}

int getLevel()
{
    int i=0;
    if(rand()%2)
        i++;

    return i;
}

void insert(SkipList& Slist , int val)
{
    int k = getLevel();

    if(k > Slist.max_level)
        k=Slist.max_level;

    SLNode* el = new SLNode;
    el->value = val;
    v->next = new SLNode*[k+1];

    SLNode* temp = Slist.head;

    for(int lvl = Slist.max_level ; lvl >=0; lvl--)
    {
        while(temp->next[lvl]->value < val)
        {
            temp = temp->next[lvl];
        }
        if(lvl<=k)
        {
            el->next[lvl] = temp->next[lvl];
            temp->next[lvl] = el;
        }
    }
}



void deleteElement(SkipList & Slist , int val)
{
    SLNode* tmp = Slist.head;

    for(int lvl = Slist.max_level ; lvl>=0 ; lvl--)
    {
        while(tmp->next[lvl]->value < val)
            tmp= tmp->next[lvl]->value;

        if(tmp->next[lvl]->value == val)
        {
            if(lvl==0)
            {
                SLNode* nextone = tmp->next[lvl]->next[lvl];
                delete[] tmp->next[lvl]->next;
                tmp->next[lvl] = nextone;
            }else
                tmp->next[lvl] = tmp->next[lvl]->next[lvl];
        }
    }
}

int main()
{

}