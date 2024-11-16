#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

class Graph {
public:
    int numVertices;
    std::vector<std::vector<int>> adjaMatrix; // Adjacency matrix
    std::vector<std::list<int>> adjaList;     // Adjacency list
    struct Node {
        int id;
        std::vector<Node*> neighbors;
        Node(int val) : id(val) {}
    };
    std::vector<Node*> linkedObjects;        // Linked object representation

    Graph(int vertices) : numVertices(vertices) {
        adjaMatrix.resize(vertices, std::vector<int>(vertices, 0));
        adjaList.resize(vertices);
        linkedObjects.resize(vertices, nullptr);
        for (int i = 0; i < vertices; ++i) {
            linkedObjects[i] = new Node(i + 1);
        }
    }

    void addEdge(int v1, int v2) {
        // For adjacency matrix
        adjaMatrix[v1 - 1][v2 - 1] = 1;
        adjaMatrix[v2 - 1][v1 - 1] = 1;
        // For adjacency list
        adjaList[v1 - 1].push_back(v2);
        adjaList[v2 - 1].push_back(v1);
        // For linked objects
        linkedObjects[v1 - 1]->neighbors.push_back(linkedObjects[v2 - 1]);
        linkedObjects[v2 - 1]->neighbors.push_back(linkedObjects[v1 - 1]);
    }

    // Print adjacency matrix
    void printMatrix() {
        std::cout << "Adjacency Matrix:\n";
        for (const auto& row : adjaMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

    // Print adjacency list
    void printAdjaList() {
        std::cout << "Adjacency List:\n";
        for (size_t i = 0; i < adjaList.size(); ++i) {
            std::cout << (i + 1) << ": ";
            for (int neighbor : adjaList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
    void performDFS() {
        std::cout << "Depth-First Traversal:\n";
        std::vector<bool> visited(numVertices, false);
        for (Node* node : linkedObjects) {
            if (!visited[node->id - 1]) {
                depthFirstTraversal(node, visited);
            }
        }
        std::cout << "\n";
    }

    // BFS traversal for linked objects
    void performBFS() {
        std::cout << "Breadth-First Traversal:\n";
        std::vector<bool> visited(numVertices, false);
        for (Node* start : linkedObjects) {
            if (!visited[start->id - 1]) {
                std::queue<Node*> q;
                q.push(start);
                visited[start->id - 1] = true;
                while (!q.empty()) {
                    Node* node = q.front();
                    q.pop();
                    std::cout << node->id << " ";
                    for (Node* neighbor : node->neighbors) {
                        if (!visited[neighbor->id - 1]) {
                            visited[neighbor->id - 1] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }
};
