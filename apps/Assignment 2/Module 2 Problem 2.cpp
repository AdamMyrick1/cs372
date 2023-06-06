#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    const int SIZE = 5;
    Array<int> arr(SIZE);

    arr.put(1, 0);
    arr.put(2, 1);
    arr.put(3, 2);
    arr.put(4, 3);
    arr.put(5, 4);

    for (int i = 0; i < SIZE; i++) {
        cout << arr.at(i) << " ";
    }
}


//#include <iostream>
//#include "Array.h"

//using namespace std;

//int main()
//{
//    Array<int> newArray(5);
//
//    newArray.put(1, 3);
//    newArray.traverse();
//}