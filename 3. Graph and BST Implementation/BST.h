#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTNode.h"


class BST {
private:
    BSTNode* root;

    // Recursive in-order traversal
    void inOrderSidekick(BSTNode* node) const {
        if (node != nullptr) {
            inOrderSidekick(node->left);
            std::cout << node->data << " ";
            inOrderSidekick(node->right);
        }
    }


    // Recursive insert helper
      BSTNode* insert(BSTNode* node, const std::string& item, std::string& path) {
        if (node == nullptr) {
            std::cout << "Insertion Path: " << path << std::endl;
            return new BSTNode(item);
        }
        if (item < node->data) {
            path += "L, ";
            node->left = insert(node->left, item, path);
        } else if (item > node->data) {
            path += "R, ";
            node->right = insert(node->right, item, path);
        }
        return node;
    }


    // Search helper function using recursion
    bool search(BSTNode* node, const std::string& item, std::string& path, int& comp) const {
        if (node == nullptr) {
            return false;
        }
        comp++;
        if (item == node->data) {
            return true;
        } else if (item < node->data) {
            path += "L, ";
            return search(node->left, item, path, comp);
        } else {
            path += "R, ";
            return search(node->right, item, path, comp);
        }
    }

     
public:
    BST() : root(nullptr) {}

    void insert(const std::string& item) {
        std::string path;
        root = insert(root, item, path);
    }
    

    void printInOrder() const {
        inOrderSidekick(root);
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

