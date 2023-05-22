#include <iostream>

using namespace std;

void caseOne(int size);
void caseTwo(int size);
string* caseThreeA();
void caseThreeB();

int main()
{
    int arrSize = 50;
    caseOne(arrSize);
    cout << endl;
    caseTwo(arrSize);
    cout << endl;
    caseThreeB();
}

void caseOne(int size)
{
    int* thisArray = new int[size];

    for (int x = 0; x < size; x++)
    {
        thisArray[x] = x;
    }

    int* newPointer = thisArray;

    delete[] thisArray;

    for (int x = 0; x < 10; x++)
    {
        cout << newPointer[x] << " ";
    }
}

void caseTwo(int size)
{
    int* thisArray = new int[size];

    for (int x = 0; x < size; x++)
    {
        thisArray[x] = x;
    }

    int* newPointer = thisArray;

    delete thisArray;

    cout << "Address of second pointer: " << & newPointer << endl;

    for (int x = 0; x < 10; x++)
    {
        cout << newPointer[x] << " ";
    }
}

string* caseThreeA()
{
    string* pointer = new string("abcdefghijkl");
    return pointer;
}

void caseThreeB()
{
    string* newString = caseThreeA();
    cout << "Case Three string: " << newString;
}