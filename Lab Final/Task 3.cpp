#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

bool checkChild(int value, TreeNode *leftSubtree, TreeNode *rightSubtree)
{
    if (leftSubtree == nullptr && rightSubtree == nullptr)
    {
        return true;
    }

    if (leftSubtree->value > value || rightSubtree->value < value)
    {
        return false;
    }

    return
        checkChild(leftSubtree ->value,leftSubtree->left, leftSubtree->right) &&
        checkChild(rightSubtree ->value,rightSubtree->left, rightSubtree->right);
}

bool isBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return checkChild(root->value, root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isBST(root))
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
    return 0;
}
