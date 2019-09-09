#include <iostream>

using namespace std;

struct node{
    int neighbour;
    node* next;
};

bool dfs(node* G[] , bool visited[] , bool released[] ,  int relSeq[] , int i , int& count)
{
    cout << "Visiting " << i << " vertice..." << endl;
    visited[i] = true;

    int preys_released = 0;

    node* tmp = G[i];
    while(tmp!=NULL && preys_released < 2)
    {
        cout << "[in " << i << " vertice] Checking " << tmp->neighbour << " neighbour" << endl; 
        if(released[tmp->neighbour] == true){
            preys_released++;
        }else if(visited[tmp->neighbour] == false){
            if (dfs(G , visited , released , relSeq , tmp->neighbour , count) )
                preys_released++;
        }

        tmp=tmp->next;
    }

    visited[i] = false;

    cout << "...finished visiting " << i << " vertice" << endl;

    if(preys_released == 2 || G[i] == NULL){
        cout << "## Marked " << i << " as released" << endl;
        released[i] = true;
        relSeq[count] = i;
        count++;
        return true;
    }

    return false;
}

bool releaseThemAll(node* G[] , const int n , int relSeq[])
{
    bool visited[n];
    bool released[n];
    for(int i=0;i<n;i++){
        released[i] = false;
        visited[i] = false;
    }
    
    int count = 0;

    for(int i=0;i<n;i++)
    {
        cout << "Trying to launch from " << i << "-vertice" << endl;
        if(!released[i] && !dfs(G , visited , released , relSeq ,  i , count)){
            return false;
        }
    }

    return true;
}

void insertEdge(node* G[] , int u, int v)
{
    node* edge = new node;
    edge->neighbour = v;

    edge->next = G[u];
    G[u] = edge;
}

int main()
{
    int N , E;
    cin>>N >> E;
    node* Graph[N];
    for(int i=0;i<N;i++)
        Graph[i] = NULL;

    for(int i=0 ; i<E;i++)
    {
        int u,v;
        cin >> u >> v;
        insertEdge(Graph , u-1  ,v-1);
    }

    int Sequence[N];

    if(!releaseThemAll(Graph , N , Sequence))
    {
        cout << "IMPOSSIBLE"<<endl;
        return 0;
    }

    for(int i=0;i<N;i++)
    {
        cout << Sequence[i] << " ";
    }
    return 0;
}