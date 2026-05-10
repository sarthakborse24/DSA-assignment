#include <iostream>
using namespace std;
#define MAX 20

class Graph
{
    int cost[MAX][MAX];
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
                cin >> cost[i][j];
                if (i != j && cost[i][j] == 0)
                    cost[i][j] = 999;
            }
        }
    }
    void prims()
    {
        int visited[MAX] = {0};
        visited[0] = 1;

        int total = 0;
        int edges = 0;
        cout << "\nEdges in MST:\n";
        while (edges < n - 1)
        {
            int min = 999, u = -1, v = -1;
            for (int i = 0; i < n; i++)
            {
                if (visited[i])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (!visited[j] && cost[i][j] < min)
                        {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
            if (u == -1 || v == -1)
            {
                cout << "Graph is disconnected\n";
                break;
            }
            cout << u << " - " << v << " = " << cost[u][v] << endl;
            total += cost[u][v];
            visited[v] = 1;
            edges++;
        }
        cout << "\nTotal Minimum Cost = " << total << endl;
    }
};
int main()
{
    Graph g;
    g.input();
    g.prims();
    return 0;
}