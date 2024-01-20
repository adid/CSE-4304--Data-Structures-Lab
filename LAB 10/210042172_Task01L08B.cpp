#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int key, bool &reservation) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->value-3) {
            root->left = insert(root->left, key, reservation);
        } 
        else if (key > root->value+3) {
            root->right = insert(root->right, key, reservation);
        }
        else if (key >= (root->value-3) || key <= (root->value+3)){
            reservation = false;
            return root;
        }

        return root;
    }

    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << root->value << " ";
            inOrderTraversal(root->right);
        }
    }

public:
    BST() : root(nullptr) {
    }

    void insert(int key) {
        bool res= true;
        root = insert(root, key, res);
        inOrderTraversal(root);
        if(res== false) {
            cout << " (Reservation failed)";
        }
        cout<<"\n";
    }
};

int main() {
    
    BST bst;
    int val;

    while (true)
    {
        cin >> val;
        if(val== -1){
            break;
        }
        bst.insert(val);
    }

    return 0;
}