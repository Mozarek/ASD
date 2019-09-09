#include <iostream>
#include <vector>
using namespace std;
const int n = 5;

void dfstopo(bool G[n][n], bool visited[n], int u, int result[n], int &x)
{
    if (visited[u])
        return;
    visited[u] = true;
    for (int i = 0; i < n; i++)
    {
        if (G[u][i])
            dfstopo(G, visited, i , result, x);
    }
    result[x] = u;
    x--;
}

bool toposort(bool G[n][n], bool visited[n])
{
    int *result = new int[n];
    int x = n-1;
    for (int i = 0; i < n; i++)
    {
        dfstopo(G, visited, i, result, x);
    }

    for(int i=0;i<n;i++)
        cout << result[i] << " ";

    for (int i = 0; i < n-1; i++)
    {
        if (!G[result[i]][result[i+1]])
            return false;
    }
    return true;
}

int main()
{
    bool G[n][n] = 
    {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
    };
    bool visited[n] = {false};
    cout << toposort(G, visited);
    return 0;
}