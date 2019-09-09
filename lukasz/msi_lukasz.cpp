#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct point
{
    int x;
    int y;
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

struct edge
{
    int src;
    int dst;
    int w;
    edge(int u, int v, int w)
    {
        this->src = u;
        this->dst = v;
        this->w = w;
    }

    edge() {}
};

struct node
{
    int val;
    node *parent;
    int rank;
    node(int v)
    {
        this->val = v;
        this->rank = 1;
        this->parent = this;
    }

};

node *findset(node *x)
{
    if(x->parent != x)
        x->parent = findset(x->parent);
    return x->parent;
}

void unionsets(node *x, node *y)
{
    x = findset(x);
    y = findset(y);
    if (x == y) return;
    if (x->rank > y->rank)
        y->parent = x;
    if (y->rank > x->rank)
        x->parent = y;
    else
    {
        x->rank++;
        y->parent = x;
    }    
}

bool ed_comp(edge a, edge b)
{
    return a.w < b.w;
}

edge *kruskal(edge *E, int n, int m)
{
    sort(E, E + m, ed_comp);
    node ** T = new node*[n];
    for (int i = 0; i < n; i++)
    {
        node *p = new node(i);
        T[i] = p;
    }

    edge *R = new edge[n-1];
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        int a = E[i].src;
        int b = E[i].dst;
        node *x = T[a];
        node *y = T[b];
        if (findset(x) == findset(y)) continue;
        unionsets(x, y);
        R[k] = E[i];
        k++;
    }

    return R;
}

int sq(int x) { return x*x; }

int main()
{
    const int N = 5;
    point pts[N] = {point(1,4) , point(2,6) , point(4,2) , point(3,7) , point(5,5)};

    int M = N*(N-1)/2;
    edge E[M];
    int k =0;
    for(int i=0;i<N;i++){
        for(int j=i+1 ; j<N;j++){
            E[k++] = edge( i , j , sq(pts[i].x - pts[j].x) + sq(pts[i].y - pts[j].y) );
            cout << k <<  " >>>> i: " << i << ", j: " << j << ", w(i->j) = " << E[k-1].w << endl;
        }
    }    

    //
    edge* R = kruskal(E , N , M);


    for(int i=0;i<N-1;i++){
        cout << R[i].src << " - " << R[i].dst << endl;
    }

    return 0;
}