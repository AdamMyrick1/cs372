template <typename T>
class AdjacencyMatrixGraph : public Graph<T> {
private:
    vector<vector<int>> adjMatrix;
public:
    AdjacencyMatrixGraph(int initialValue) : adjMatrix(initialValue, vector<int>(initialValue, 0)) {}

    bool adjacent(T xValue, T yValue) override {
        return adjMatrix[xValue][yValue] == 1;
    }

    vector<T> neighbors(T xValue) override {
        vector<T> result;
        for(int count = 0; count < adjMatrix[xValue].size(); count++)
            if(adjMatrix[xValue][count] == 1)
                result.push_back(count);
        return result;
    }

    void addEdge(T source, T destination) override {
        adjMatrix[source][destination] = 1;
    }

    void addNode(T xValue) override {
        if(xValue >= adjMatrix.size()) {
            for(auto &row : adjMatrix)
                row.resize(xValue + 1, 0);
            adjMatrix.resize(xValue + 1, vector<int>(xValue + 1, 0));
        }
    }

    void deleteEdge(T source, T destination) override {
        adjMatrix[source][destination] = 0;
    }

    void deleteNode(T node) override {
        for(auto &row : adjMatrix)
            row[node] = 0;
        adjMatrix[node] = vector<int>(adjMatrix.size(), 0);
    }
};
