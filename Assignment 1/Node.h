#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>


// Node class definition
class Node {
public:
    char data;  // Each node holds one character
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with data
    Node(char d) : data(d), next(nullptr) {}
};
#endif
