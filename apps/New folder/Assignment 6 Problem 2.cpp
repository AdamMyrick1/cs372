#include <iostream>
#include <vector>
#include <list>
#include "Graph.h"
#include "AdjacencyListGraph.h"

using namespace std;

template <typename T>
bool isSimpleCycle(Graph<T>& paramGraph, const vector<T>& path) {
    if (path.size() < 3)
        return false;

    if (path.front() != path.back()) 
        return false;

    set<T> visited;

    for (size_t count = 0; count < path.size() - 1; count++) {
        if (!paramGraph.adjacent(path[count], path[count+1])) 
            return false;
        if (visited.count(path[count]))
            return false;
        visited.insert(path[count]);
    }

    return true;
}

int main() {
    AdjacencyListGraph<int> Adjacent(5);

    Adjacent.addEdge(0, 1);
    Adjacent.addEdge(1, 2);
    Adjacent.addEdge(2, 3);
    Adjacent.addEdge(3, 0);

    vector<int> cycle = {0, 1, 2, 3, 0};
    vector<int> not_cycle = {0, 1, 2, 3, 3, 0};

    if (isSimpleCycle(Adjacent, cycle)) {
        cout << "The path forms a simple cycle." << endl;
    } else {
        cout << "The path does not form a simple cycle." << endl;
    }

    if (isSimpleCycle(Adjacent, not_cycle)) {
        cout << "The path forms a simple cycle." << endl;
    } else {
        cout << "The path does not form a simple cycle." << endl;
    }
};