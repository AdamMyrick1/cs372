//Program: Homework 5 Problem 5.cpp
//Author:  Adam Myrick
//Purpose: Demonstrate use of standalone function "prune" that will take a tree structure and strip it's 
//         leaf nodes

#include <memory>
#include <functional>
#include <cassert>
#include <iostream>
#include "DeletableTree.h"
using namespace std;

template<class T>
Tree<T> prune(const Tree<T>& tree) {
    if (tree.isEmpty())
        return Tree<T>();
    else if (tree.left().isEmpty() && tree.right().isEmpty())
        return Tree<T>();
    else
        return Tree<T>(prune(tree.left()), tree.root(), prune(tree.right()));
}

int main() {
    Tree<int> tree = Tree<int>(Tree<int>(), 4, Tree<int>()).insert(2).insert(1).insert(3).insert(6).insert(5).insert(7);

    auto print = [](int val) { std::cout << val << " "; };
    std::cout << "Original Tree: ";
    tree.inorder(print);
    std::cout << std::endl;

    Tree<int> pruned_tree = prune(tree);
    std::cout << "Pruned Tree: ";
    pruned_tree.inorder(print);
    std::cout << std::endl;
}