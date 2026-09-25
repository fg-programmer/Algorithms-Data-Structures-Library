#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode {
public:
    std::string data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const std::string& value) : data(value), left(nullptr), right(nullptr) {}
};
#endif