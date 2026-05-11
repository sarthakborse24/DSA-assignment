#include <iostream>
#include <climits>
using namespace std;
int V;
#define INF INT_MAX

int minDistance(int dist[], bool visited[])
{
    int min = INF, min_index = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] <= min)   
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[100][100], int source)
{
    int dist[100];
    bool visited[100];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        if (u == -1)
            break;
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To node " << i << " = " << dist[i] << endl;
    }
}

int main()
{
    int graph[100][100];
    int source;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {

            cin >> graph[i][j];
        }
    }
    cout << "Enter source vertex: ";
    cin >> source;
    dijkstra(graph, source);
    return 0;
}