#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <sstream>
#include <string>
#include "Edge.h"
using namespace std;

class Graph {
private:
    int numVertices;
    vector<Edge> edges;

public:
    Graph(int vertices) : numVertices(vertices) {}

    void addEdge(int start, int end, int weight) {
        edges.push_back(Edge(start, end, weight));
    }

    vector<Edge>& getEdges() {
        return edges;
    }

    int getNumVertices() {
        return numVertices;
    }
};

void bellmanFord(Graph& graph, int source) {
    int V = graph.getNumVertices();
    vector<Edge>& edges = graph.getEdges();
    vector<int> distance(V + 1, numeric_limits<int>::max());
    vector<int> predecessor(V + 1, -1);

    distance[source] = 0;

