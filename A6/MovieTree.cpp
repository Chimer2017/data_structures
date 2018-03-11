#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"

int countPath(MovieNodeLL *head)
{
  MovieNodeLL *current;
  current = head;
  int count = 0;
  while(current != nullptr)
  {
    count++;
    cout << current->title << " ";
    current = current->next;
  }
  cout << count << endl;
  cout << endl;
  return count;
}
MovieNodeBST *treeMinHelper(MovieNodeBST *node)
{
  MovieNodeBST *current;
  current = node;

  /* loop down to find the leftmost leaf */
  while (current->leftChild != NULL)
      current = current->leftChild;

  return current;
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) //use this to find the left most leaf node of the BST, you'll need this in the delete function
{
    return treeMinHelper(root);
}

void deleteList(MovieNodeLL *head)
{
  MovieNodeLL *current = head;
  MovieNodeLL *tmp;
  while (current != nullptr)
  {
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
}
MovieNodeBST * deleteNode(MovieNodeBST *root, char letter)
{

    if (root == NULL) return root;


    if (letter < root->letter)
        root->leftChild = deleteNode(root->leftChild, letter);


    else if (letter > root->letter)
        root->rightChild = deleteNode(root->rightChild, letter);


    else
    {
        if (root->leftChild == NULL)
        {
            MovieNodeBST *temp = root->rightChild;
            delete root;
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            MovieNodeBST *temp = root->leftChild;
            delete root;
            return temp;
        }

        MovieNodeBST *current;
        current = root->rightChild;

        /* loop down to find the leftmost leaf */
        while (current->leftChild != NULL)
            current = current->leftChild;

        // Copy the inorder successor's content to this node
        root->letter = current->letter;

        // Delete the inorder successor
        root->rightChild = deleteNode(root->rightChild, current->letter);
    }
    return root;
}
MovieNodeLL *searchList( MovieNodeLL *head, string titleForCompare )
{
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
MovieNodeLL *insertHead( MovieNodeLL *head, int ranking, string title, int year, int quantity)
{
	// Create a new node and tmp poitner
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking, title, year, quantity );
  tmp->next = NULL;
	return tmp;
}
//*************************INSERT AFTER************************
void insertAfter( MovieNodeLL *prevNode, int ranking, string title, int year, int quantity )
{
	// Create new node
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking,title,year,quantity);
  tmp->next = prevNode->next;
	prevNode->next = tmp;
  tmp = NULL;

}
//*************************INSERT TAIL************************
void insertEnd( MovieNodeLL *head, int ranking, string title, int year, int quantity)
{
	MovieNodeLL *tmp;
  tmp = new MovieNodeLL(ranking, title, year, quantity);
	MovieNodeLL *current;
  current = head;
	MovieNodeLL *last;
	while( current != NULL )
	{
		last = current;
		current = current->next;
	}
  last->next = tmp;
	tmp->next = NULL;

}
MovieNodeLL *addMovieNodeLL(MovieNodeLL *head, int ranking, string title, int year, int quantity)
{
  if (head == NULL)
  {
    head = insertHead(head, ranking,title, year, quantity);
  }
  else if (head != NULL && head->next == NULL && head->title.compare(title) < 0 )
  {
    MovieNodeLL *t;
    t =  head;
    head = insertHead(head, ranking,title, year, quantity);
    head->next = t;
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
      MovieNodeLL *h;
      h = head;
      head = insertHead(head, ranking,title, year, quantity);
      head->next = h;
    }
    else
    {
      insertAfter(tmp,ranking,title,year, quantity);

    }

  }
  //countPath(head);





  return head;
}
MovieNodeBST *addNodeHelper(MovieNodeBST *curNode, char key, int ranking, std::string title, int releaseYear, int quantity)
{
  if (curNode == NULL)
  {
      curNode = new MovieNodeBST(key);
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
  root = NULL;
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
  int sum = 0;
  countMovieNodes(root,x);
}
/*void deleteMovieNodeHelper(MovieNodeLL *head_ref, string title)
{
    MovieNodeLL * temp, *prev;
    temp = head_ref;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->title == title)
    {
        head_ref = temp->next;   // Changed head
        delete temp;               // free old head
    }
    while (temp != NULL && temp->title != title)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
      cout << "Movie not found." << endl;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp;  // Free memory
}*/
MovieNodeLL * deleteMovieNodeHelper(MovieNodeLL *head_ref, string title)
{
    MovieNodeLL * temp, *prev;
    temp = head_ref;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->title == title)
    {
        head_ref = temp->next;   // Changed head
        delete temp;
        return head_ref;              // free old head
    }
    while (temp != NULL && temp->title != title)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
      cout << "Movie not found. Helper" << endl;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp;  // Free memory
}
void MovieTree::deleteMovieNode(std::string title)
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
            int listSize;
            listSize = countPath(tmp->head);

            if (listSize == 1 )
            {
              deleteList(tmp->head);
              tmp->head = NULL;
              deleteNode(root,title[0]);

            }
            else
            {
              if (tmp->head->title == title)
                tmp->head = deleteMovieNodeHelper(tmp->head, title);
              else
                deleteMovieNodeHelper(tmp->head,title);
            }

         }



   }
}
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
  MovieNodeBST *newNode;
  newNode = new MovieNodeBST(title[0]);
  if(root == NULL) {// if the BST is empty create the root
      root = newNode;
      addNodeHelper(root,title[0],ranking,title,releaseYear,quantity);}
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
void printPath(MovieNodeLL *head)
{
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
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
  if (node)
  {
         countMovieNodes( node->leftChild,c);
         *c = countPath(node->head);
         cout << c << endl;
         countMovieNodes( node->rightChild,c);

  }







  /*if (node == NULL)
    cout << "0" << endl;

  countMovieNodes( node->leftChild,c);
  tempCount = countPath(node->head);
  totalCount += tempCount;
  countMovieNodes( node->rightChild,c);

  //cout << totalCount << "io" << endl;
*/

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

    if (tmp2->quantity == 0)
    {
      int listSize;
      listSize = countPath(tmp->head);
      cout << listSize << endl;
      if (listSize == 1)
      {
        deleteList(tmp->head);
        tmp->head = NULL;
        deleteNode(root, tmp->letter);

      }
      else
      {
        deleteMovieNodeHelper(tmp->head,tmp2->title);

      }

    }
  }


}
