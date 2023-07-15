//Program: Homework 5 Module 3.cpp
//Author:  Adam Myrick
//Purpose: Demonstrate use of added deletion function to provided tree structure class

#include "DeletableTree.h"
#include <iostream>

int main() {
    Tree<int> tree;
    tree = tree.insert(10);
    tree = tree.insert(5);
    tree = tree.insert(15);
    tree = tree.insert(3);
    tree = tree.insert(7);
    tree = tree.insert(12);
    tree = tree.insert(18);

    std::cout << "Initial tree:" << std::endl;
    tree.inorder([](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;

    int valueToDelete = 10;
    bool deleted = tree.remove(valueToDelete);

    std::cout << "Tree after deleting " << valueToDelete << ":" << std::endl;
    tree.inorder([](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;

    if (deleted) {
        std::cout << "Deleted " << valueToDelete << " from the tree." << std::endl;
    } else {
        std::cout << valueToDelete << " not found in the tree." << std::endl;
    }
}
