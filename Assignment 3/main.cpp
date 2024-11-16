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