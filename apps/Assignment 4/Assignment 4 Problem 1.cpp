#include <iostream>
#include <queue>

using namespace std;

int josephusProblem(int n, int m);

int main() {
    int n = 5;
    int m = 5;
    int winner = josephusProblem(n, m);
    cout << "The winner is: " << winner << endl;
}

int josephusProblem(int n, int m) {
    queue<int> josephus;
    int front;

    for (int i = 1; i <= n; i++) {
        josephus.push(i);
    }

    while (josephus.size() > 1) {
        for (int i = 0; i < m - 1; i++) {
            front = josephus.front();
            josephus.pop();
            josephus.push(front);
        }
        josephus.pop();
    }
    return josephus.front();
}