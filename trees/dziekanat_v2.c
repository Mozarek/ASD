#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) {

    node* tmp = malloc(sizeof(node));

    tmp->number = number;
    tmp->left = NULL;
    tmp->parent = NULL;
    tmp->right = NULL;
    tmp->name = malloc(MAX_NAME_SIZE*sizeof(char));
    strcpy(tmp->name , name);

    return tmp;
}

void delete_tree(node* root) {
    if(root==NULL)
        return;
    
    delete_tree(root->left);
    delete_tree(root->right);
    free(root->name);
    free(root);
}

node* insert (node* root, node* to_insert)
{
    //empty tree
    if(root == NULL){
        return to_insert;
    }

    //finding proper place to insert
    node* prev = NULL;
    node* tmp = root;

    while(tmp!=NULL){
        prev=tmp;
        if(to_insert->number < tmp->number)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    //inserting
    to_insert->parent = prev;
    if(to_insert->number < prev->number)
        prev->left = to_insert;
    else
        prev->right = to_insert;

    
    return root;
}

node* find (node* root, int number)
{
    while(root!=NULL && root->number != number){
        if(number < root->number)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

node* find_successor(node* x)
{
    if(x->right == NULL)
        return NULL;
    
    x=x->right;
    while(x->left!=NULL)
        x=x->left;
    
    return x;
}

// transplant u into v (returns new root)
// v and root must be non-NULL
node* transplant(node* root , node* u , node* v)
{
    if(v==root)
        return u;

    if(u!=NULL)
        u->parent = v->parent;

    if(v->parent->left == v)
        v->parent->left = u;
    else
        v->parent->right = u;

    return root;
}

node* delete_node(node* root, int number)
{
    node* to_del = find(root , number);

    if(to_del==NULL)
        return root;

    if(to_del->left == NULL)
        root = transplant(root , to_del->right , to_del);
    else if(to_del->right == NULL)
        root = transplant(root , to_del->left , to_del);
    else
    {
        //next has no left child (as then it would be the successor instead)
        node* next = find_successor(to_del);

        if(next == to_del->right)
        {
            //1st case
            root = transplant(root , next , to_del);
            next->left = to_del->left;
            next->left->parent = next;

        }else
        {
            //2nd case
            root = transplant(root , next->right , next);
            next->right = to_del->right;
            next->right->parent = next;

            root = transplant(root , next , to_del);
            next->left = to_del->left;
            next->left->parent = next;
        }
    }

    free(to_del);

    return root;
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }

    while (r-- > 0) {
        scanf("%d", &number);
        root = delete_node(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}
