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

    // Relax edges up to V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.start] != numeric_limits<int>::max() &&
                distance[edge.start] + edge.weight < distance[edge.end]) {
                distance[edge.end] = distance[edge.start] + edge.weight;
                predecessor[edge.end] = edge.start;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.start] != numeric_limits<int>::max() &&
            distance[edge.start] + edge.weight < distance[edge.end]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

        // Print results
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == numeric_limits<int>::max()) {
            cout << "Vertex " << i << " is not reachable from vertex " << source << "." << endl;
        } else {
            cout << "1 --> " << i << " cost is " << distance[i] << "; path: ";
            vector<int> path;
            for (int v = i; v != -1; v = predecessor[v]) {
                path.insert(path.begin(), v);
            }
            for (size_t j = 0; j < path.size(); ++j) {
                cout << path[j];
                if (j != path.size() - 1) cout << " --> ";
            }
            cout << endl;
        }
    }
}





Graph parseGraph(const string& inputFile) {
    ifstream file(inputFile);
    string line;
    Graph* graph = nullptr;
    while (getline(file, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "new") {
            int numVertices;
            graph = new Graph(numVertices);
        } else if (command == "add") {
            string type;
            iss >> type;

            if (type == "vertex") {
                int vertex;
                iss >> vertex;
                // Adding a vertex may not require an action for adjacency list
            } else if (type == "edge") {
                int start, end, weight;
                char dash;
                iss >> start >> dash >> end >> weight;
                graph->addEdge(start, end, weight);
            }
        }
    }
    return *graph;
}
