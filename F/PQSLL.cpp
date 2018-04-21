#include <iostream>
#include "PQSLL.hpp"
using namespace std;



void pqList::enqueue(string n, int p, int t )
{

   listNode *start = head;

    // Create new Node
   listNode *temp = new listNode(n,p,t);




    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if (head->pri > p) {

        // Insert New Node before head
        temp->next = head;
        head = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL && start->next->pri < p)
        {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        if ( start->treat == start->next->treat)
        {
          while(start->next != NULL && start->next->treat < t)
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

bool pqList::queueIsFull()
{

}

bool pqList::queueIsEmpty()
{

}
