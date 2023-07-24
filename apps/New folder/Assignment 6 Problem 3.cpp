#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include "Graph.h"
#include "AdjacencyListGraph.h"

using namespace std;

bool isConnectedToKevinBacon(AdjacencyListGraph<int>& graph, int start, int end, list<int>& path) {
    queue<int> baconQueue;
    map<int, int> baconMap;
    set<int> visited;
    
    baconQueue.push(start);
    visited.insert(start);
    
    while(!baconQueue.empty()) {
        int current = baconQueue.front();
        baconQueue.pop();

        if(current == end) {
            int node = end;
            while(node != start) {
                path.push_front(node);
                node = baconMap[node];
            }
            
            path.push_front(start);
            return true;
        }

        vector<int> neighbours = graph.neighbors(current);
        for(const int& neighbour : neighbours) {
            if(visited.find(neighbour) == visited.end()) {
                baconQueue.push(neighbour);
                visited.insert(neighbour);
                baconMap[neighbour] = current;
            }
        }
    }

    return false;
}

int main() {
    AdjacencyListGraph<int> socialGraph(20); 
    //Used adjacency graph populated with 20 integers, each one representing 
    //a person. You are represented by 0, and Kevin Bacon is represented by 1
    //with all people in between being represented by numbers 2 - 19

    for(int i = 0; i < 20; ++i) {
        socialGraph.addNode(i);
    }

    socialGraph.addEdge(0, 2); 

    for(int count = 2; count < 19; count++) { //Just a quick way to poulate. You can manually add connections
                                              //As well
        socialGraph.addEdge(count, count + 1);
    }
    socialGraph.addEdge(19, 1); 

    list<int> path;
    bool connected = isConnectedToKevinBacon(socialGraph, 0, 1, path);
    
    if(connected) {
        cout << "You are connected to Kevin Bacon through this path:" << endl;
        for(const int& person : path) {
            cout << person << " ";
        }
        cout << endl;
    }
    else {
        cout << "You are not connected to Kevin Bacon." << endl;
    }
}