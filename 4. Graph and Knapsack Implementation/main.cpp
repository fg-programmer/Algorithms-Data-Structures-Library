#include "Graph.h"
#include "Spice.h"

int main() {
    vector<string> files = {"graphs2.txt"};
    for (const auto& file : files) {
        Graph graph = parseGraph(file);
        cout << "Running Bellman-Ford on graph from " << file << endl;
        bellmanFord(graph, 1); // Run SSSP from vertex #1
    }

    vector<Spice> spices;
    vector<int> knapsack_capacities;

    parseInput("spice.txt", spices, knapsack_capacities);

    fractionalKnapsack(spices, knapsack_capacities);

    return 0;
}
