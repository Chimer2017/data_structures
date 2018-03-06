#include <iostream>
#include <sstream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

MovieNodeLL *searchList( MovieNodeLL *head, string titleForCompare ) {
	MovieNodeLL *current, *prevNode;
	current = head;
  if (titleForCompare.compare(head->title) < 0)
  {
    return head;
  }
  else
  {
  prevNode = head;
  current = current->next;


	while( current!=NULL )
	{
    //cout << "Hello" << endl;

	  if( titleForCompare.compare(current->title) < 0 )//&& titleForCompare.compare(currentNext->title) < 0)
    {

      return prevNode;
    }
		else
    {
      current = current->next;
      prevNode = prevNode->next;
    }
	}

	return NULL;
}
}
//*************************INSERT HEAD************************/
MovieNodeLL *insertHead( MovieNodeLL *head, int ranking, string title, int year, int quantity) {
	// Create a new node and tmp poitner
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking, title, year, quantity );
  tmp->next = head;
	return tmp;
}

//*************************INSERT AFTER************************
void insertAfter( MovieNodeLL *prevNode, int ranking, string title, int year, int quantity ) {
	// Create new node
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking,title,year,quantity);
  tmp->next = prevNode->next;
	prevNode->next = tmp;
  tmp = NULL;

}
//*************************INSERT TAIL************************
void insertEnd( MovieNodeLL *head, int ranking, string title, int year, int quantity) {
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking, title, year, quantity);
	MovieNodeLL *current;
  current = new MovieNodeLL();
  current = head;
	MovieNodeLL *last;
  last = new MovieNodeLL();
	while( current != NULL )
	{
		last = current;
		current = current->next;
	}
  last->next = tmp;
	tmp->next = NULL;

}


MovieNodeLL *addMovieNodeLL(MovieNodeLL *head, int ranking, string title, int year, int quantity) {
  if (head == NULL)
  {
    head = insertHead(head, ranking,title, year, quantity);
  }
  else if (head != NULL && head->next == NULL && head->title.compare(title) < 0 )
  {
    head = insertHead(head, ranking,title, year, quantity);
  }
  else
  {
    MovieNodeLL *tmp;
    tmp = searchList(head,title);
    if (tmp == NULL)
    {
      insertEnd(head,ranking,title,year,quantity);
    }
    else if (tmp == head)
    {
      insertHead(head, ranking,title, year, quantity);
    }
    else
    {
      insertAfter(tmp,ranking,title,year, quantity);
    }
  }





  return head;
}

MovieNodeBST *addNodeHelper(MovieNodeBST *curNode, char key, int ranking, std::string title, int releaseYear, int quantity)
{
  if (curNode == NULL)
  {
      return new MovieNodeBST(key);
  }
  if (key < curNode->letter)
      curNode->leftChild  = addNodeHelper(curNode->leftChild, key, ranking, title, releaseYear, quantity);
  else if (key > curNode->letter)
      curNode->rightChild = addNodeHelper(curNode->rightChild, key, ranking, title, releaseYear, quantity);
  else if (key == curNode->letter)
      curNode->head = addMovieNodeLL(curNode->head,ranking,title,releaseYear,quantity);





  return curNode;

}

MovieTree::MovieTree()
{

}
MovieTree::~MovieTree()
{
  DeleteAll(root);
}
void MovieTree::printMovieInventory()
{
  printMovieInventory(root);
  cout << endl;

}
int MovieTree::countMovieNodes()
{
  int *x;
  countMovieNodes(root,x);
  return *x;
}
/*
void MovieTree::deleteMovieNode(std::string title)
{

}*/
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
  MovieNodeBST *newNode;
  newNode = new MovieNodeBST(title[0]);
  if(root == NULL) // if the BST is empty create the root
      root = newNode;
  else
    addNodeHelper(root,title[0],ranking, title, releaseYear,quantity);
}

void MovieTree::findMovie(std::string title)
{
  MovieNodeBST *tmp;
  MovieNodeLL *tmp2;

  tmp = searchBST(root,title);
  if (tmp == NULL)
  {
    cout << "Movie not found." << endl;
  }
  else
  {
    tmp2 = searchLL(tmp->head,title);

    if (tmp2 == NULL)
      cout << "Movie not found." << endl;
    else
      cout << "Movie Info:" << endl;
      cout << "===========" << endl;
      cout << "Ranking:" << tmp2->ranking << endl;
      cout << "Title:" << tmp2->title << endl;
      cout << "Year:" << tmp2->year << endl;
      cout << "Quantity:" << tmp2->quantity << endl;
  }

}

void MovieTree::rentMovie(std::string title)
{
  MovieNodeBST *tmp;
  MovieNodeLL *tmp2;

  tmp = searchBST(root,title);
  if (tmp == NULL)
  {
    cout << "Movie not found." << endl;
  }
  else
  {
    tmp2 = searchLL(tmp->head,title);

    if (tmp2 == NULL)
      cout << "Movie not found." << endl;
    else
    {
        tmp2->quantity = (tmp2->quantity) - 1;
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << tmp2->ranking << endl;
        cout << "Title:" << tmp2->title << endl;
        cout << "Year:" << tmp2->year << endl;
        cout << "Quantity:" << (tmp2->quantity)<< endl;
    }
  }

}
void MovieTree::DeleteAll(MovieNodeBST * node)
{
  if(node)
  {
      DeleteAll(node->leftChild);
      DeleteAll(node->rightChild);
      delete node;
      node = NULL;
  }
  //use this for the post-order traversal deletion of the tree
}
void printPath(MovieNodeLL *head) {
  MovieNodeLL *current;
  current = new MovieNodeLL();
  current = head;
  while(current != nullptr)
  {
    cout<<"Movie: "<<current->title<<" "<<current->quantity<<endl;
    current = current->next;
  }
}
void MovieTree::printMovieInventory(MovieNodeBST * node)
{
  if(node)
  {
         printMovieInventory( node->leftChild);
         //cout << " "<< node->letter;
         printPath(node->head);
         printMovieInventory( node->rightChild);
  }


}
int countPath(MovieNodeLL *head) {
  MovieNodeLL *current;
  current = new MovieNodeLL();
  current = head;
  int count = 0;
  while(current != nullptr)
  {
    count++;
    current = current->next;
  }
  return count;
}
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
  int totalCount;
  totalCount = 0;
  if(node)
  {
         countMovieNodes( node->leftChild,c);
         totalCount += countPath(node->head);
         countMovieNodes( node->rightChild,c);
  }
  c = &totalCount;
  cout << totalCount;
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title)
{
  char letter = title[0];
  if (node == NULL || node->letter == letter)
     return node;
  if (node->letter < letter)
     return searchBST(node->rightChild,title);
  return searchBST(node->leftChild, title);  //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
}


MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title) //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
{
  MovieNodeLL *current;
  current = head;

  while( current!=NULL )
  {
    if( current->title == title )
      return current;
    else
      current = current->next;
  }

  return NULL;

}

/*
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) //use this to find the left most leaf node of the BST, you'll need this in the delete function
{

}
*/
