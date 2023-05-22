#include <iostream>
#include "circularList.h"

using namespace std;

template<typename T>
void printCircularList(const CircularList<T>& circularList) 
{
    for (const auto& element : circularList) 
    {
        cout << element << " ";
    }
    cout << endl;
}

int main() 
{
    CircularList<int> circularList;

    //Testing the push_back method
    circularList.push_back(1);
    circularList.push_back(2);
    circularList.push_back(3);
    circularList.push_back(4);

    //Test the actual printing of the circular list
    cout << "Circular List: ";
    printCircularList(circularList); //Expected Output: 1 2 3 4

    //Test the erase()
    CircularList<int>::iterator it = circularList.begin();
    ++it;  //Move to the second element
    it = circularList.erase(it);  //Erase the second element (2)

    cout << "After erasing the second element: ";
    printCircularList(circularList); //Expected output: 1 3 4

    //Test erasing the last element
    it = circularList.end();
    --it; //Move to the last element
    it = circularList.erase(it); //Erase the last element (4)

    cout << "After erasing the last element: ";
    printCircularList(circularList); //Output: 1 3

    //Test erasing the only remaining element
    it = circularList.begin();
    it = circularList.erase(it); //Erase the remaining element (1)

    cout << "After erasing the only remaining element: ";
    printCircularList(circularList); // Output: empty
}
