#include <iostream>
#include <sstream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

MovieNodeBST *addNodeHelper(MovieNodeBST *curNode, char key )
{
  if (curNode == NULL)
  {
      return new MovieNodeBST(key);
  }
  if (key < curNode->letter)
      curNode->leftChild  = addNodeHelper(curNode->leftChild, key);
  else if (key > curNode->letter)
      curNode->rightChild = addNodeHelper(curNode->rightChild, key);

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

}/*
int MovieTree::countMovieNodes()
{

}
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
    addNodeHelper(root,title[0]);




}
/*
void MovieTree::findMovie(std::string title)
{

}
void MovieTree::rentMovie(std::string title)
{

}*/
void MovieTree::DeleteAll(MovieNodeBST * node)
{
  if(node)
  {
      DeleteAll(node->leftChild);
      DeleteAll(node->rightChild);
      delete node;
      node = nullptr;
  }
  //use this for the post-order traversal deletion of the tree
}

void MovieTree::printMovieInventory(MovieNodeBST * node)
{
  if(node)
  {
         printMovieInventory( node->leftChild);
         cout << " "<< node->letter;
         printMovieInventory( node->rightChild);
  }

}/*
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{

}
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title)
{
  //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
}
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title) //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
{

}
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) //use this to find the left most leaf node of the BST, you'll need this in the delete function
{

}
*/
