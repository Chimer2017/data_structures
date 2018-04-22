#include "PQH.hpp"
using namespace std;


mh::mh(int cap)
{
    heapSize = 0;
    arraySize = cap;
    harr = new node[cap];
}

void mh::minHeapify(node*)
{

}

node mh::dequeueH()
{

}

void swap(node *x, node *y)
{
    node temp = *x;
    *x = *y;
    *y = temp;
}

void mh::enqueueH(node tmp)
{
    if (heapSize == arraySize)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heapSize++;
    int i = heapSize - 1;
    harr[i] = tmp;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].pri >= harr[i].pri)
    {

       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }


}
