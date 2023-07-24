#include <iostream>
#include "Graph.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

using namespace std;

int main() {

    int value = 5;

    AdjacencyListGraph<int> adjListGraph(value);

    adjListGraph.addEdge(0, 1);
    adjListGraph.addEdge(1, 2);
    adjListGraph.addEdge(2, 3);
    adjListGraph.addEdge(3, 4);
    adjListGraph.addEdge(4, 0);

    cout << "Adjacency List Graph:" << endl;
    for (int count = 0; count < value; count++) {
        cout << "Neighbors of node " << count << ": ";
        for (int neighbor : adjListGraph.neighbors(count)) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    AdjacencyMatrixGraph<int> adjMatrixGraph(5);

    adjMatrixGraph.addEdge(0, 1);
    adjMatrixGraph.addEdge(1, 2);
    adjMatrixGraph.addEdge(2, 3);
    adjMatrixGraph.addEdge(3, 4);
    adjMatrixGraph.addEdge(4, 0);

    cout << endl << "Adjacency Matrix Graph:" << endl;
    for (int count = 0; count < value; count++) {
        cout << "Neighbors of node " << count << ": ";
        for (int neighbor : adjMatrixGraph.neighbors(count)) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
