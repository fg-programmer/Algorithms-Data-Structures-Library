#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include "BST.h"
#include "BSTNode.h"

int main() {
    BST bst;

    // Read and insert from magicitems.txt
    std::ifstream inputFile("magicitems.txt");
    std::string item;
    while (inputFile >> item) {
        bst.insert(item);
    }
    inputFile.close();

    // Print in-order traversal of BST
    std::cout << "In-order Traversal of BST:" << std::endl;
    bst.printInOrder();

    // Search and lookup from magicitems-find-in-bst.txt
    std::ifstream searchFile("magicitems-find-in-bst.txt");
    std::vector<std::string> itemsToFind;
    while (searchFile >> item) {
        itemsToFind.push_back(item);
    }
    searchFile.close();

    int totalComparisons = 0;
    for (const auto& findItem : itemsToFind) {
        bst.searchItem(findItem);
    }

    return 0;
}
