//Program: Homework 5 Problem 4.cpp
//Author:  Adam Myrick
//Purpose: Demonstrate use of standalone function mean to carry out a "level traversal" within 
//         provided tree  structure class 

#include "DeletableTree.h"
#include <queue>
#include <iostream>

template <class T, typename Func>
void levelOrderTraversal(const Tree<T>& tree, Func visit) {
    if (tree.isEmpty()) {
        return;
    }

    queue<Tree<T>> q;
    q.push(tree);

    while (!q.empty()) {
        Tree<T> nodeTree = q.front();
        q.pop();

        visit(nodeTree.root());

        if (!nodeTree.left().isEmpty()) {
            q.push(nodeTree.left());
        }

        if (!nodeTree.right().isEmpty()) {
            q.push(nodeTree.right());
        }
    }
}

int main() {
    Tree<int> tree;
    tree = tree.insert(7);
    tree = tree.insert(5);
    tree = tree.insert(9);
    tree = tree.insert(3);
    tree = tree.insert(6);
    tree = tree.insert(8);
    tree = tree.insert(10);

    //For this problem, I determined "what needs to be done" to simply be outputting the values
    //for the sake of simplicity. However, any operation could be acceptable.
    auto printNode = [](const auto& node) { cout << node << " "; };
    cout << "Level order traversal: ";
    levelOrderTraversal(tree, printNode); 
}
