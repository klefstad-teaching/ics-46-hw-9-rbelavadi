#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        auto[currDist, u] = pq.top();
        pq.pop();
        if(currDist > distances[u]) continue;

        for(const Edge& e : G[u]){
            int v = e.dst;
            int weight = e.weight;
            
            if(distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if(distances[destination] == INF) return path;
    
    for(int v = destination; v != -1; v = previous[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    for (int node : v)
        cout << node << " ";
    cout << "\nThe total cost is " << total << endl;
}