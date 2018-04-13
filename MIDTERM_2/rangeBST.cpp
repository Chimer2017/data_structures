#include <vector>
void RangeSearch(TreeNode *node, char m, char n)
{
    vector<char> v;
    if (node == NULL)
    {
          return;
    }
     RangeSearch(node->left, m, n);

    if (node->key >= m && node->key <= n)
    {
        v.push_back(node->key);
        cout << v.back() << " -> ";
    }


     RangeSearch(node->right,m,n);



}
