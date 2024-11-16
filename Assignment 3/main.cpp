#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include "Graph.h"

int main() {
    std::ifstream file("graphs1.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
     std::string line;
    Graph* graph = nullptr;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        if (command == "new") {
            std::string type;
            iss >> type; //"graph"
            int vertices; 
            iss >> vertices;
            graph = new Graph(vertices);
        } else if (command == "add") {
            std::string element;
            iss >> element;
            if (element == "vertex") {
            } else if (element == "edge") {
                int v1, v2;
                iss >> v1 >> v2;
                if (graph) {
                    graph->addEdge(v1, v2);
                }
            }
        }
    }

    if (graph) {
        graph->printMatrix();
        graph->printAdjList();
        graph->performDFS();
        graph->performBFS();
    }

    return 0;
}