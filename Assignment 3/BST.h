#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTNode.h"


class BST {
private:
    BSTNode* root;

        // In-order traversal helper function using recursion
    void inOrderSidekick(BSTNode* node) {
        if (node != nullptr) {
            inOrderSidekick(node->left);
            std::cout << node->data << "\n";
            inOrderSidekick(node->right);
        }
    }

    // Insert helper function using recursion
    void insertSidekick(BSTNode*& node, const std::string& value, std::string& path) {
        if (node == nullptr) {
            node = new BSTNode(value);
            std::cout << "Insert Path '" << value << "': " << path << "\n";
            return;
        }
        if (value < node->data) {
            path += "L, ";
            insertSidekick(node->left, value, path);
        } else {
            path += "R, ";
            insertSidekick(node->right, value, path);
        }
    }
    // Search helper function using recursion
bool searchSidekick(BSTNode* node, const std::string& value, std::string& path, int& comp) {
        if (node == nullptr) {
            return false;
        }
        comp++;
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            path += "L, ";
            return searchSidekick(node->left, value, path, comp);
        } else {
            path += "R, ";
            return searchSidekick(node->right, value, path, comp);
        }
    }
     
public:
    BST() : root(nullptr) {}

    void insert(const std::string& item) {
        std::string path;
        root = insert(root, item, path);
    }

    void printInOrder() const {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void searchItem(const std::string& item) const {
        std::string path;
        int comp = 0;
        if (search(root, item, path, comp)) {
            std::cout << "Found " << item << " | Path: " << path << "| Comparisons: " << comp << std::endl;
        } else {
            std::cout << "Not Found " << item << " | Path: " << path << "| Comparisons: " << comp << std::endl;
        }
    }
};

