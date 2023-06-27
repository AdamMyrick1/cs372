#include "LazyList.h"
#include <iostream>

using namespace std;

void printValue(int value) {
    cout << value << " ";
}

int main() {
    List<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);
    myList.push_front(15);
    myList.push_back(30);

    myList.markDeleted(5);
    myList.markDeleted(30);

    myList.traverse(printValue);
}
