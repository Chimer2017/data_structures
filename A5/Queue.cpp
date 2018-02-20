#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

Queue::Queue(int qs)
{
  queueSize = qs;
  arrayQueue = new std::string[queueSize];
  queueHead = 0;
  queueTail = 0;
  queueCount = 0;
}

Queue::~Queue()
{
  delete [] arrayQueue;
  arrayQueue = nullptr;
}

void Queue::enqueue(string word)
{
  if (!queueIsFull())
  {
    arrayQueue[queueTail] = word;
    queueCount++;
    if (queueTail == queueSize - 1)
    {
      queueTail = 0;
    }
    else
    {
      queueTail++;
    }
    cout << "E: " << word << endl;
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
  }
  else
  {
    cout << "Queue full" << endl;
  }


}

void Queue::dequeue()
{
  string out;
  if (!queueIsEmpty())
  {
    out = arrayQueue[queueHead];
    queueCount--;
    if (queueHead == queueSize - 1)
    {
      queueHead = 0;
    }
    else
    {
      queueHead++;
    }
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
    cout << "word: " << out << endl;
  }
  else
  {
    cout << "Queue empty" << endl;
    out = "";
  }

}

void Queue::printQueue()
{

}

void Queue::enqueueSentence(string str)
{

}

bool Queue::queueIsFull()
{
  if (queueCount == queueSize)
  {
    return true;
  }
  else
  {
    return false;
  }

}

bool Queue::queueIsEmpty()
{
  if (queueCount == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
