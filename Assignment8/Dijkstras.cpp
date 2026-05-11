#include<iostream>
#include<climits>
using namespace std;

#define MAX 20
#define inf INT_MAX

class Graph
{public:

    int graph[MAX][MAX];
    int n;

    void input()
    {
        cout<<"Enter the number of vertices : ";
        cin>>n;
        cout<<"Enter the adjacency Matrix : ";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>graph[i][j];
            }
        }
    }
    
    int minimum_dist(int dist[], bool visited[])
    {
        int min = inf;
        int min_index = -1;

        for(int i=0; i<n; i++)
        {
            if(!visited[i] && dist[i]<min)
            {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }


    // Dijkstra ALgorithm
    void dijkstra(int source)
    {
        int dist[MAX];
        bool visited[MAX];

        for(int i=0; i<n; i++)
        {
            dist[i] = inf;
            visited[i] = false;
        }

        dist[source] = 0;

        for(int i=0; i<n-1; i++)
        {
            int u = minimum_dist(dist, visited);

            if(u == -1)
                break;

            visited[u] = true;

            for(int v=0; v<n; v++)
            {
                if(!visited[v] && graph[u][v] && dist[u]!=inf && 
                        dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout<<"\nShortest Distance from source node :\n";

        for(int i=0; i<n; i++)
        {
            cout<<"To Node : "<<i<<" = "<<dist[i]<<endl;
        }
    }
};

int main()
{
    Graph g;

    g.input();
    
    int source;
    
    cout << "Enter source vertex : ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}