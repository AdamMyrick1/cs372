//This is basically a morelimited version of our home-made vector class, with things such as 
//dynamic re-sizing, member functions, and re-sizing being stripped. I kept functions such as size() not
//for accuracy, but for a quality of life improvement when testing

#include <iostream>
#include <vector>
using namespace std;
template <typename T>

class Array {
private:
    vector<T> arr;
    int capacity;
public:
    Array(size_t size) : arr(size), capacity(size) {}

    size_t size() const {
        return arr.size();
    }

    void put(T data, int index) {
        arr[index] = data;
    }

    T& at(int index) {
       return arr[index];
    }

    T& operator[](size_t index) {
        return arr[index];
    }

    bool operator==(Array<T>& other) const {
        if (other.size() != capacity) {
            return false;
        }
        else {
            for (int i = 0; i < capacity; i++) {
                if (arr[i] != other.at(i)) {
                    return false;
                }
            }
        }
        return true;
    };

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            arr = other.arr;
        }
        return *this;
    }
};



