#include <iostream>
#include <string>

class BSTNode {
public:
    std::string data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const std::string& value) : data(value), left(nullptr), right(nullptr) {}
};
