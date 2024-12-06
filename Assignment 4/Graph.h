#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
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

    // Check negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.start] != numeric_limits<int>::max() &&
            distance[edge.start] + edge.weight < distance[edge.end]) {
            cout << "Graph contains a negative weight cycle." << endl; 
            break;
        }
    }

    // Print results for each vertex, even if there is a negative weight cycle
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == numeric_limits<int>::max()) {
            cout << "Vertex " << i << " is not reachable from vertex " << source << "." << endl;
        } else {
            cout << "1 --> " << i << " cost is " << distance[i] << "; path: ";
            vector<int> path;
            for (int v = i; v != -1; v = predecessor[v]) {
                path.insert(path.begin(), v);
            }

            // Print the path in the format requested
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
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << inputFile << endl;
        exit(1);
    }

    string line;
    Graph* graph = nullptr;
    int numVertices = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "new" && iss >> command && command == "graph") {
            // Expect the next line to contain the number of vertices
            if (getline(file, line)) {
                istringstream numStream(line);
                numStream >> numVertices;
                graph = new Graph(numVertices);
            } else {
                cerr << "Error: Expected number of vertices after 'new graph' keyword." << endl;
                exit(1);
            }
        } else if (command == "add") {
            string type;
            iss >> type;

            if (type == "vertex") {
                int vertex;
                iss >> vertex;
                // No action needed for adding a vertex in the Graph class
            } else if (type == "edge") {
                int start, end, weight;
                char dash;
                if (iss >> start >> dash >> end >> weight && dash == '-') {
                    graph->addEdge(start, end, weight);
                } else {
                    cerr << "Error: Invalid edge format." << endl;
                    exit(1);
                }
            }
        }
    }

    if (graph == nullptr) {
        cerr << "Error: No graph data found in file." << endl;
        exit(1);
    }

    return *graph; 
}
