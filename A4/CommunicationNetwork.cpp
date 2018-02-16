#include <iostream>
#include <fstream>
#include <sstream>
#include "CommunicationNetwork.h"
using namespace std;


City *searchList( City *head, string target ) {
	City *current;
	current = head;

	while( current!=nullptr )
	{
		if( current->cityName == target )
			return current;
		else
			current = current->next;
	}

	return nullptr;
}
City *insertHead( City *head, string cityName ) {
	// Create a new node and tmp poitner
	City *tmp;
  tmp = new City(cityName,head,nullptr,"" );
	return tmp;
}
void insertAfter( City *prevNode, string newCityName ){
	// Create new node
	City *tmp;
  City *nextNode;
  nextNode = prevNode->next;
  tmp = new City(newCityName,prevNode->next,nextNode->previous,"");
	prevNode->next = tmp;
  nextNode->previous = tmp;
  tmp = nullptr;

}
void insertEnd( City *head, string tailAdd, City *tail) {
	City *newTail;
  newTail = new City(tailAdd,nullptr,nullptr,"");
	City *current;
  current = tail;
  current->next = newTail;
  newTail->previous = current;
  tail = newTail;

  /*
  current = new City();
  current = head;
	City *last;
  last = new City();
	while( current != nullptr )
	{
		last = current;
		current = current->next;
	}
  last->next = tmp;
  tmp->previous = last;
	tmp->next = nullptr;
  tail = tmp;
  */

}


//CONSTRUCTOR
CommunicationNetwork::CommunicationNetwork()
{
  head = nullptr;
  tail = nullptr;
}
//DECONSTRUCTOR
CommunicationNetwork::~CommunicationNetwork()
{
  City *current = head;
  City *tmp;
  while (current != nullptr)
  {
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;

}
//BUILD NETWORK
void CommunicationNetwork::buildNetwork()
{
  string cities[] = {"Los Angeles","Phoenix", "Denver", "Dallas", "St.Louis"
  , "Chicago" , "Atlanta", "Washington, D.C.", "New York", "Boston"};
  City *current, *tmp;
  head = new City(cities[0],nullptr,nullptr,"");
  current = new City();
  current = head;
  int i = 1;
  while (i < 10)
  {
    tmp = new City(cities[i],nullptr,nullptr,"");
    current->next = tmp;
    tmp->previous = current;
    current = tmp;
    i++;
  }
  tail = current;
  //cout << tail->previous->cityName;
  currentTail = "Boston";

  /*cout << "===Current Path===" << endl;
  current = head;
  while(current != nullptr)
  {
    cout << current->cityName << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
  //cout << "==================" << endl;
  */

}
//PRINT NETWORK
void CommunicationNetwork::printNetwork()
{
  City *current;
  current = new City();
  cout << "===Current Path===" << endl;
  current = head;
  cout << "NULL" << " <- ";
  while(current != nullptr)
  {
    cout << current->cityName;
    current = current->next;
    if (current != nullptr)
    {
      cout << " <-> ";
    }
  }
  cout << " -> " << "NULL" << endl;
  cout << "==================" << endl;


}
void CommunicationNetwork::addCity(string newCity, string previousCity)
{
  currentTail = "Boston";
  if (previousCity == "First")
  {
    head = insertHead(head,newCity);
  }
  else if (previousCity == "" || previousCity == currentTail)
  {
    currentTail = newCity;
    //cout << currentTail << endl;
    insertEnd(head,newCity, tail);

  }
  else
  {
		City *searchCity;
		searchCity = searchList(head, previousCity);
		if (searchCity == nullptr)
		{
			cout << "not found" << endl;
		}
		else
		{
			insertAfter(searchCity,newCity);
		}


  }

}
void CommunicationNetwork::deleteCity(string target)
{
  City *compare;
  compare = searchList(head,target);
  if (target == currentTail)
  {
    currentTail = tail->previous->cityName;
    tail = tail->previous;
  }

  /* If node to be deleted is head node */
  if(head == compare)
    head = compare->next;

  /* Change next only if node to be deleted is NOT the last node */
  if(compare->next != nullptr)
    compare->next->previous = compare->previous;

  /* Change prev only if node to be deleted is NOT the first node */
  if(compare->previous != nullptr)
    compare->previous->next = compare->next;

  /* Finally, free the memory occupied by del*/
  delete compare;
}
void CommunicationNetwork::deleteNetwork()
{
  City *current = head;
  City *tmp;

  while (current != nullptr)
  {
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;

}
void CommunicationNetwork::transmitMsg(char *message)
{

}
