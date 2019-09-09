#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    int el_count_to_left = 0;
};

struct BST{
    Node* root;
};

//replaces the subtree rooted at node u with subtree rooted at node v
void transplant(BST& T , Node* u , Node* v)
{
    if(T.root == u){
        T.root = v;
    }else if(u->key < u->parent->key){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }

    if(v!=NULL)
        v->parent = u->parent;
}

Node* tree_minimum(Node* t)
{
    while(t->left!=NULL)
        t=t->left;
    
    return t;
}

Node* find_successor(Node* x)
{
    if(x->right!=NULL)
    {
        //do gory until go right or NULL
        while(x->parent!=NULL && x->parent->right == x)
            x=x->parent;

        return x->parent;
    }else
    {
        return tree_minimum(x->right);
    }
}

BST BST_init()
{
    BST T;
    T.root = NULL;
    return T;
}

void insert(BST &T , int key)
{
    Node* new_node = new Node;
    new_node->key = key;

    Node* prev = NULL;
    Node* temp = T.root;
    while(temp!=NULL)
    {
        if(key < temp->key){
            temp->el_count_to_left++;
            prev = temp;
            temp = temp->left;
        }else{
            prev = temp;
            temp = temp->right;
        }
    }
    new_node->parent = prev;

    if(prev==NULL) // tree was empty
        T.root = new_node;
    else if(key < prev->key)
    {
        prev->left = new_node;
    }else
    {
        prev->right = new_node;
    }
}

Node* find(BST &T , int key)
{
    Node* tmp = T.root;

    Node* answer = NULL;
    while(tmp!=NULL)
    {
        answer = tmp;
        if(key < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if(answer->key == key)
        return answer;
    else
        return NULL;
}

//delete Node x from tree T
void delete_node(BST& T , Node* x)
{
    if(x->right == NULL){
        transplant(T , x , x->left);
    }else if(x->left == NULL){
        transplant(T , x , x->right);
    }else
    {
        //find succesor
        // (being a successor it is guaranteed it has no left child)
        Node* y = find_successor(x);

        //transplant y->right into y
        // (only if there are elements between y and x)
        if(y->parent != x){
            transplant(T , y , y->right);
            y->right = x->right;
            y->right->parent = y;
        }

        //transplant y into x
        transplant(T , x , y);
        y->left = x->left;
        y->left->parent = y;
    }

    delete x;
}

void inorder_search(Node* x)
{
    if(x!=NULL)
    {
        inorder_search(x->left);
        cout << x->key << " ";
        inorder_search(x->right);
    }
}

int main()
{
    int tab[5] = {7,3,5,2,1};

    BST T = BST_init();

    for(int x: tab)
        insert(T , x);

    inorder_search(T.root);
    cout << endl;

    Node* to_delete = find(T , 5);

    inorder_search(T.root);

    return 0;
}