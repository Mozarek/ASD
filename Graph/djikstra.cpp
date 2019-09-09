#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 5;

struct vertex{
    int v;
    int dist;

    vertex(){}
    vertex(int _v , int _dist){
        v = _v;
        dist = _dist;
    }

};

class Comp
{
public:
    bool operator() (vertex a, vertex b)
    {
        return a.dist >= b.dist;
    }
};

int* djikstra(int weight[N][N] , int parent[N] , int source)
{
    int* dist = new int[N];
    for(int i=0;i<N;i++)
        dist[i] = INT32_MAX;
    dist[source] = 0;

    priority_queue <vertex , vector<vertex> , Comp> Q;

    Q.push(vertex(source, 0));
    parent[source] = -1;

    for(int processed = 0; processed <N ; processed++){
        int v = Q.top().v;
        Q.pop();
        //

        // iterating over adjacent vertices
        for(int i=0; i<N;i++) if(weight[v][i] >= 0) 
        {
            if(dist[i] > dist[v] + weight[v][i]){
                dist[i] = dist[v] + weight[v][i];
                Q.push( vertex(i , dist[i]) );
                parent[i] = v;
            }
        }

        cout << "Processed " << v << " with dist = " << dist[v] << endl;
    }

    return dist;
}


void printPath(int v , const int parent[]){
    if(v == -1) return;
    printPath(parent[v] , parent);
    cout << " -> " << v;
}

//prints path of minimal weight and the distance from each node to source
void printResults(const int dist[] , const int parent[]){
    cout << "Printing distances from nodes to source node:" << endl;
    for(int i=0;i<N;i++){
        cout << "dist[" << i << "] = " << dist[i] << endl;
        cout << "Path: ";
        printPath(i , parent);
        cout << endl;
    }
}

int main()
{
    int parent[N];
    int weights[N][N];
    for (int i = 0; i < N; i++)
        for(int j=0 ; j<N ; j++)
            weights[i][j] = -1;
    
    int source;

    cout << "Graph of " << N << " vertices." << endl;
    cout << "Give number of edges: " << endl;
    int m;
    cin>>m;


    cout << "Input edges: " << endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        weights[u][v] = w;
        weights[v][u] = w;
    }

    cout << "Give source node: ";
    cin >> source;
    
    int* dist = djikstra(weights , parent , source);

    printResults(dist , parent);


    delete[] dist;

    return 0;
}