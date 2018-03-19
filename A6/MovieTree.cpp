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
    //cout << current->title << " ";
    current = current->next;
  }
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
MovieNodeBST * minValue(MovieNodeBST *node) {

      if (node->leftChild == NULL)

            return node;

      else

            return minValue(node->leftChild);

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
        else
        {
            root = minValue(root->rightChild);
            return deleteNode(root->rightChild, letter);
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
MovieTree::MovieTree()
{
  root = NULL;
 }
MovieTree::~MovieTree()
{
  DeleteAll(root);
}
MovieNodeBST* searchParent(MovieNodeBST* node, MovieNodeBST* tmp){
    if (node == NULL){
        cout << "Movie not found." << endl;
    }
    else{
        //
        if (tmp->letter < node->letter){
	        if (node->leftChild == NULL){
	            return node;
	        }
	        else{
	            return searchParent(node->leftChild, tmp);
	        }
    	}
    	else{
    	    if (node->rightChild == NULL){
    	        return node;
    	    }
    	    else{
    	        return searchParent(node->rightChild, tmp);
    	    }
    	}
    }
}
bool movieGoesBefore(MovieNodeLL* node, string titleCom){
    int len;
    if (node == NULL){
        cout << "Movie Not Found." << endl;
    }
    else{
        //what if the title is the same but less characters?
        string nodeTitle = node->title;
        if (titleCom.length() > nodeTitle.length()){
            len = titleCom.length();
        }
        else{
            len = nodeTitle.length();
        }

        for (int i= 0; i< len; i++){

            //cout << title[i] << " to " <<  nodeTitle[i] << endl;
            if (titleCom[i] != nodeTitle[i]){
                if (titleCom[i] < nodeTitle[i]){
                    if (i== nodeTitle.length()){
                        return false;
                    }
                    return true;
                }
                return false;
            }
        }
        return false;
    }
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
	MovieNodeBST* letterNode = searchBST(root, title);
	MovieNodeLL* newMovie = new MovieNodeLL(ranking, title, releaseYear, quantity);

	MovieNodeBST* temp = root;

	if (letterNode != NULL){
		//if found
		//add to the end of Linked List in order

		MovieNodeLL* temp= letterNode->head;
		if (movieGoesBefore(temp, title)){
		    //make new head
		    //cout << newMovie->title << "at head before" << temp->title << endl;
		    newMovie->next = letterNode->head;
		    letterNode->head = newMovie;

		}
		else{
		    if (temp->next == NULL){
		        //cout << newMovie->title << " at end" << endl;
		        temp->next = newMovie;
		        return;
		    }
		    MovieNodeLL* prev= letterNode->head;
		    temp= temp->next;
		    while(!movieGoesBefore(temp, title)){
		        if (temp->next == NULL){
		            //cout << newMovie->title << " at end" << endl;
		            temp->next = newMovie;
		            return;
		        }
		        temp= temp->next;
		        prev=prev->next;
		    }
		    //temp is now next Node
		    //cout << newMovie->title << "before" << temp->title << endl;
		    newMovie->next = temp;
		    prev->next= newMovie;

		}
	}
	else{
		//if not created
		//create Nodes
		MovieNodeBST *newNode = new MovieNodeBST(title[0]);
		//set as first MovieNodeLL
		newNode->head = newMovie;
		//find the correct Node to create after
		MovieNodeBST* parent;
		bool left=false;
		if (root == NULL) {
    		root = newNode;
    		return;
    	}
		else{
		    parent = searchParent(root, newNode);
		    if (newNode->letter < parent->letter){
		        parent->leftChild = newNode;
		        newNode->parent = parent;
		    }
		    else{
		        parent->rightChild = newNode;
		        newNode->parent= parent;
		    }
		}
	}

}

void MovieTree::printMovieInventory()
{
  printMovieInventory(root);
  cout << endl;

}
int MovieTree::countMovieNodes()
{
  int x = 0;
  countMovieNodes(root,&x);
  return x;
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
void printDelPath(MovieNodeLL *head)
{
  MovieNodeLL *current;
  current = new MovieNodeLL();
  current = head;
  while(current != nullptr)
  {
    cout<<"Deleting: "<<current->title<<endl;
    current = current->next;
  }
}
void MovieTree::DeleteAll(MovieNodeBST * node)
{
  if(node)
  {
      DeleteAll(node->leftChild);
      DeleteAll(node->rightChild);
      printDelPath(node->head);
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
void MovieTree::countMovieNodes(MovieNodeBST* node, int *c){
	//copy printMovieInventory, but increase count every time
	MovieNodeBST* startNode= node;
    if (startNode != nullptr){
		if (startNode->leftChild != nullptr){
			countMovieNodes(startNode->leftChild, c);
		}
		MovieNodeLL* temp = startNode->head;
		while(temp != NULL){
		    *c = *c +1;
		    temp= temp->next;
		}
		if(startNode->rightChild != nullptr){
			countMovieNodes(startNode->rightChild, c);
		}
	}
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
void MovieTree::rentMovie(std::string title){
	MovieNodeBST* letterNode = searchBST(root, title);
	if (letterNode != NULL){
		MovieNodeLL* movieNode = searchLL(letterNode->head, title);
		if (movieNode != NULL){
			//if found
			//decrease count by 1
            movieNode->quantity = movieNode->quantity -1;
			cout << "Movie has been rented." << endl;
			findMovie(movieNode->title);
			if (movieNode->quantity == 0){
				deleteMovieNode(movieNode->title);
			}
		}
		else{
		    //cout << "Movie not found." << endl;
		}
	}
	else{
	    //cout << "Movie not found." << endl;
	}
}
