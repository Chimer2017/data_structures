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
    // if (heapSize <= 0)
    //     return INT_MAX;
    // if (heapSize == 1)
    // {
    //     heapSize--;
    //     return harr[0];
    // }
    //
    // // Store the minimum value, and remove it from heap
    // node root = harr[0];
    // harr[0] = harr[heapSize-1];
    // heapSize--;
    // MinHeapify(0);
    //
    // return root;


}

void swap(node *x, node *y)
{
    node temp = *x;
    *x = *y;
    *y = temp;
}

void mh::enqueueH(node arr[])
{
  int index = 0;
  while(index < arraySize)
  {
    if (heapSize == arraySize)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    node temp = node(arr[index].name,arr[index].pri,arr[index].treat);
    heapSize++;
    int i = heapSize - 1;
    harr[i] = temp;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].pri >= harr[i].pri)
    {
      if (harr[parent(i)].pri == harr[i].pri)
      {
        while (i != 0 && harr[parent(i)].treat >= harr[i].treat)
        {
          cout << "hello" << endl;
          cout << "treat: " << harr[parent(i)].treat << " " << harr[i].treat << endl;

          swap(&harr[i], &harr[parent(i)]);
          i = parent(i);
        }
        break;
      }
        cout << harr[parent(i)].pri << " " << harr[i].pri << endl;
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);


    }
    cout <<index << ": Added " << harr[i].name << endl;
    index++;
  }


}
