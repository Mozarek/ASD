#include <iostream>

#define N 100

#define MIN_INT -10000
#define MAX_INT 10000

struct node
{
    int n;
    int key[N];
    node* child[N+1];
    bool leaf;
};

bool is_b_tree_R(node* p , int l , int r , int &h_leaf , int h)
{   
    //empty tree
    if(p == NULL || p->n == 0)
        return true;

    //first and last element must be in range [l , r] 
    if(p->key[0] < l || p->key[p->n-1] > r)
        return false;

    //all leaves must be at the same height
    if(p->leaf)
    {
        if(h_leaf == -1)
            h_leaf = h;
        else if(h != h_leaf)
            return false;
    }

    //all keys must be sorted in non-decreasing order
    // + recursively for each child

    if( !is_b_tree_R(p->child[0] , l , p->key[0] , h_leaf , h+1) )
        return false;
    
    for(int i=1; i < p->n ; i++)
    {
        if( p->key[i-1] > p->key[i] || 
            !is_b_tree_R(p->child[i] , p->key[i-1] , p->key[i] , h_leaf , h+1) )
            return false;
            
    }

    if( !is_b_tree_R(p->child[p->n] , p->key[p->n-1] , r , h_leaf , h+1) )
        return false;
        
}

bool is_b_tree(node* p)
{
    int h_leaf = -1;
    return is_b_tree_R(p , MIN_INT , MAX_INT , h_leaf , 0);
}