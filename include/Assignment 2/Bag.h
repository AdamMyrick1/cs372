#pragma once
using namespace std;
#include <vector>
template <typename Thing>

class Bag
{
private:
    vector<Thing> bagVector;
    vector<int> receiptNumber;
    bool isSameThing(Thing a, Thing b)
    {
        return (a == b);
    }
    int receipt;

public:
    Bag() = default;

    int insert(Thing aThing)
    {
        bagVector.push_back(aThing);

        srand((unsigned)time(NULL));

        receipt = rand();

        receiptNumber.push_back(receipt);

        return receipt;
    }

    Thing& pop(int receipt)
    {
        Thing aValue;
        for (int i = 0; i < receiptNumber.size(); i++) {
            if (receiptNumber[i] == receipt) {
                aValue = bagVector[i];
                bagVector[i] = NULL; // Best method I could think of since deleting specific vector indexes is appearantly not possible
            }
        }
        //bagVector.pop_back();
        return aValue;
    }

    int getReceipt(int i) {
        return receiptNumber[i];
    }

    int size()
    {
        bagVector.size();
    }

    int count(Thing& aThing)
    {
        int count = 0;
        for (auto anotherThing : bagVector)
        {
            if (anotherThing = aThing)
            {
                count++;
            }
        }
        return count;
    }
};