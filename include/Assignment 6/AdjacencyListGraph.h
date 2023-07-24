#include <list>
#include <algorithm>

template <typename T>
class AdjacencyListGraph : public Graph<T> {
private:
    vector<list<T>> adjList;
public:
    AdjacencyListGraph(int initialValue) : adjList(initialValue) {}

    bool adjacent(T xValue, T yValue) override {
        auto it = find(adjList[xValue].begin(), adjList[xValue].end(), yValue);
        return it != adjList[xValue].end();
    }

    vector<T> neighbors(T xValue) override {
        return vector<T>(adjList[xValue].begin(), adjList[xValue].end());
    }

    void addEdge(T source, T destination) override {
        adjList[source].push_back(destination);
    }

    void addNode(T xValue) override {
        adjList.resize(max((size_t)xValue + 1, adjList.size()));
    }

    void deleteEdge(T source, T destination) override {
        adjList[source].remove(destination);
    }

    void deleteNode(T node) override {
        for(auto &list : adjList)
            list.remove(node);
        adjList[node].clear();
    }
};
