#include "Graph.h"
#include "Edge.h"
int main() {
    vector<string> files = {"graphs2.txt"};
    for (const auto& file : files) {
        Graph graph = parseGraph(file);
        cout << "Running Bellman-Ford on graph from " << file << endl;
        bellmanFord(graph, 1); // Run SSSP from vertex #1
    }
    return 0;
}
