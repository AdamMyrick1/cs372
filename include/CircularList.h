//SPECIAL NOTE: Credit for this code belongs to a post on stack overflow by someone facing a similar
//              problem. This code is not 1 - 1, but was written with the post in mind as a guide.
//              The link will be provided at the bottom.

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <list>

using namespace std;

template<typename T>
class CircularList : public list<T> 
{
public:

    using iterator = typename list<T>::iterator;
    using const_iterator = typename list<T>::const_iterator;

    void push_back(const T& value);
    iterator erase(iterator position);
};

template<typename T>
struct Node 
{
    T data;
    Node<T>* next;
    Node<T>* prev;

    explicit Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

//Implementations

template<typename T>
void CircularList<T>::push_back(const T& value) 
{
    list<T>::push_back(value);

    if (this->size() > 1) 
    {
        iterator tail = prev(list<T>::end());

        tail = next(list<T>::begin());
    }
}

template<typename T>
typename CircularList<T>::iterator CircularList<T>::erase(iterator position) 
{
    iterator nextPos = list<T>::erase(position);

    if (nextPos == list<T>::end() && this->size() > 1) 
    {
        iterator tail = prev(list<T>::end());
        tail = next(list<T>::begin());
    }

    return nextPos;
}

#endif

//https://stackoverflow.com/questions/2034916/is-it-okay-to-inherit-implementation-from-stl-containers-rather-than-delegate