#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define V 6

bool bfs(int rGraph[V][V], int s, int t, int p[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    p[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
              
                if (v == t) {
                    p[v] = u;
                    return true;
                }
                q.push(v);
                p[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
 
int FF(int graph[V][V], int s, int t)
{
    int x, y;
    int rGraph[V]
              [V]; 
    for (x = 0; x < V; x++)
        for (y = 0; y < V; y++)
            rGraph[x][y] = graph[x][y];
    int p[V];
    int max_flow = 0; 
   
    while (bfs(rGraph, s, t, p)) {
        
        int path_flow = INT_MAX;
        for (y = t; y != s; y = p[y]) {
            x = p[y];
            path_flow = min(path_flow, rGraph[x][y]);
        }
 
        for (y = t; y != s; y = p[y]) {
            x = p[y];
            rGraph[x][y] -= path_flow;
            rGraph[y][x] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}
 
int main()
{
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "<< FF(graph, 0, 5);
 
    return 0;
}
