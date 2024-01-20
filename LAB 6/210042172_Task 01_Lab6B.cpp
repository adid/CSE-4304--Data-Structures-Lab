#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree
{
    public:
    TreeNode *root;

    Tree()
    {
        root= nullptr;
    }

TreeNode* findNode(TreeNode* node, int data) {
    if (node == nullptr) {
        return nullptr;
    }
        
    if (node->val == data) {
        return node;
    }

    TreeNode* leftResult = findNode(node->left, data);
        
    if (leftResult != nullptr) {
        return leftResult;
    }

    return findNode(node->right, data);
}

TreeNode* insert(int data, int parent, int child){
    
    TreeNode* newnode= new TreeNode(data);

    if(parent==0)
    {
        root= newnode;
    }

    TreeNode* node= findNode(root, parent);

    if(child==1){
        node->left= newnode;
    }

    if(child==2){
        node->right=newnode;
    }
}

TreeNode* node= root;

void preorderTraversal(TreeNode* node) {
    
    if (node == nullptr) {
        return;
    }

    cout << "Data: " << node->val << endl;
        
    preorderTraversal(node->left);
    preorderTraversal(node->right);

    return;
}

int height(TreeNode* node)
{
    if (node == nullptr)
        return 0;
    
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
};

int main()
{
    TreeNode* node= new TreeNode();
    Tree* tree= new Tree();

    int N;

    cin>>N;

    int data;
    int parent;
    int child;

    for(int i=0; i<N;i++){
        cin>> data>> parent>> child;
        tree->insert(data, parent, child);
    }

    tree->preorderTraversal(node);
}