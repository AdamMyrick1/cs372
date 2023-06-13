#include <iostream>
#include "addone.h"

using namespace std;

int main ()
{
    cout << "This program adds 1 to a number!" << endl;
    addone number(1);
    cout << "Number incremented by one is: " << number.incrementNumber() << endl;
    cout <<"Goodbye!";
    return 0;
}