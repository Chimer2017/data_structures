#include <vector>
Node *newNode(int item)
{
    Node *temp =  new Node(NULL,NULL,NULL);
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}


Node* insert(Node *root, int value)
{
    //Node * prev = NULL;
    Node * node = root;
    if (node == NULL){

        return newNode(value);

    }
    if (node!= NULL && node->left==NULL && node->right == NULL)
    {
        if ( value < node->key)
            cout << "inserted: " << value << " left child of: " << node->key <<endl;
        else
            cout << "inserted: " << value << " right child of: " << node->key <<endl;

    }


    if (value < node->key)
    {
        Node *lchild = insert(node->left, value);
        node->left  = lchild;
        //prev = node;
        lchild->parent = node;

    }
    else if (value > node->key)
    {
        Node *rchild = insert(node->right, value);
        node->right  = rchild;
        //prev = node;
        rchild->parent = node;

    }
    return node;
}
