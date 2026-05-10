#include <iostream>
using namespace std;
#define MAX 20

class Graph
{
    int adj[MAX][MAX];
    int parent[MAX];
    int n;

public:
    void input()
    {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter adjacency matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> adj[i][j];
            }
        }
    }
    int find(int v)
    {
        while (parent[v] != v)
        {
            v = parent[v];
        }
        return v;
    }

    void unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        parent[pu] = pv;
    }
    void kruskal()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int edges = 0;
        int total = 0;
        cout << "\nEdges in MST:\n";
        while (edges < n - 1)
        {
            int min = 999, u = -1, v = -1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][j] != 0 && adj[i][j] < min)
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
            if (find(u) != find(v))
            {
                cout << u << " - " << v << " = " << min << endl;

                total += min;
                unite(u, v);
                edges++;
            }
            adj[u][v] = adj[v][u] = 999;
        }
        cout << "\nTotal Minimum Cost = " << total << endl;
    }
};

int main()
{
    Graph g;
    g.input();
    g.kruskal();
    return 0;
}