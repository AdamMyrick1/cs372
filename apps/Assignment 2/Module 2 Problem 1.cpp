#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int>* v = new Vector<int>();
	v->push_back(1);
	v->push_back(2);
	v->push_back(3);
	v->traverse();
	cout << "Size: " << v->size() << endl;
	cout << "Capacity: " << v->capacity() << endl;
	v->expand(5);
	cout << "Size: " << v->size() << endl;
	cout << "Capacity: " << v->capacity() << endl;
	v->put(4, 4);
	v->traverse();
	cout << "Size: " << v->size() << endl;
	cout << "Capacity: " << v->capacity() << endl;
	//v->put(4, 0);
	//v->put(5, 1);
	//v->put(6, 2);
	//v->traverse();
	//cout << "Size: " << v->size() << endl;
	//cout << "Capacity: " << v->capacity() << endl;
	//v->expand(10);
	//cout << "Capacity: " << v->capacity() << endl;
}