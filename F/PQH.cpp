#include "PQH.hpp"
using namespace std;


mh::mh(int cap)
{
    heapSize = 0;
    arraySize = cap;
    harr = new node[cap];
}
void swap(node *x, node *y)
{
    node temp = *x;
    *x = *y;
    *y = temp;
}
void mh::minHeapify(int i)
{

    int l = left(i);
    int r = right(i);
    int smallest = i;

      if (l < heapSize && harr[l].pri < harr[i].pri)
          smallest = l;
      else if (l < heapSize && harr[l].pri == harr[i].pri)
      {
        cout << "L: equal" << endl;
        if (harr[l].treat < harr[i].treat)
          smallest = l;
      }


      if (r < heapSize && harr[r].pri < harr[smallest].pri)
          smallest = r;
      else if (r < heapSize && harr[r].pri == harr[i].pri)
      {
          cout << "R: equal" << endl;
          if (harr[r].treat < harr[i].treat)
            smallest = r;
      }



      if (smallest != i)
      {
          swap(&harr[i], &harr[smallest]);
          minHeapify(smallest);
      }







}

void mh::dequeueH()
{
  int index = 0;
  while(index < arraySize)
  {
    if (heapSize <= 0)
        return;
    if (heapSize == 1)
    {
        heapSize--;
    }

    // Store the minimum value, and remove it from heap
    node root = harr[0];
    cout << root.name << " " << root.pri << " " << root.treat << endl;
    harr[0] = harr[heapSize-1];
    heapSize--;
    minHeapify(0);
    index++;
  }
  cout << index << endl;


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
        while (i != 0 && harr[parent(i)].treat > harr[i].treat)
        {
          // cout << "hello" << endl;
          // cout << "treat: " << harr[parent(i)].treat << " " << harr[i].treat << endl;

          swap(&harr[i], &harr[parent(i)]);
          i = parent(i);
        }

      }

        //cout << harr[parent(i)].pri << " " << harr[i].pri << endl;
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);



    }
    //cout <<index << ": Added " << harr[i].name << endl;
    index++;
  }


}
