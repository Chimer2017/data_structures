void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);

     /* now recur on right child */
     printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}



TreeNode * min(TreeNode *node)
{
  TreeNode *current;
  current = node;

  /* loop down to find the leftmost leaf */
  while (current->leftChild != NULL)
      current = current->leftChild;

  return current;
}

TreeNode * max(TreeNode *node)
{
  TreeNode *current;
  current = node;

  /* loop down to find the leftmost leaf */
  while (current->rightChild != NULL)
      current = current->rightChild;

  return current;
}




void replaceMaxWithMin(TreeNode *root)
{
    TreeNode *small, *big;
    small = min(root);
    big = max(root);

    big->key = small->key;



}
