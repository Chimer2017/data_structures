#include <iostream>
#include "PQSLL.hpp"
using namespace std;



void pqList::enqueue(string n, int p, int t )
{

   listNode *start = head;

    // Create new Node
   listNode *temp = new listNode(n,p,t);
   if (head == NULL)
      head = temp;
      return;
    if (head->pri > p)
    {

        // Insert New Node before head
        temp->next = head;
        head = temp;
    }
    else
    {

        while (start->next != NULL && start->next->pri < p)
        {
            start = start->next;
        }

        if ( temp->pri == start->next->pri)
        {

          while(start->pri == temp->pri && start->next->treat < t)
          {
            start = start->next;
          }
        }


          temp->next = start->next;
          start->next = temp;



    }


}

void pqList::dequeue()
{
  while (head != NULL)
  {
    listNode * temp = head;
    cout << temp->name << " dequeued\n";
    head = head->next;
    delete temp;
  }





}

void pqList::printQueue()
{
  listNode * current;
  current = head;
  int count = 1;
  while (current!= NULL)
  {
    cout <<count << ": " << current->name << " " << current->pri << " " << current->treat << endl;
    count++;
    current = current->next;
  }


}
