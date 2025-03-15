#include "dijkstras.cpp"

int main(){
    Graph G;
    file_to_graph("small.txt", G);
    int source = 0, destination = 2;
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> path = extract_shortest_path(distances, previous, destination);
    print_path(path, distances[destination]);
    return 0;
}