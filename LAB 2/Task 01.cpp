#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
    };

    LinkedNode *Head;
    LinkedNode *Tail;


public:
    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
    }

    void Insert_front(int key)
    {
        if(Head == nullptr)
        {
            LinkedNode *temp= new LinkedNode(key);
            Head= temp;
            Tail= temp;
        }

        else
        {
            LinkedNode *temp= new LinkedNode(key);
            temp->next=Head;
            Head= temp;
        }
    }

    void Insert_back(int key)
    {
        if(Head == nullptr)
        {
            LinkedNode *temp= new LinkedNode(key);
            Head= temp;
            Tail= temp;
        }

        else
        {
            LinkedNode *temp= new LinkedNode(key);
            Tail->next=temp;
            Tail= temp;
        }
    }

    void Insert_after_node(int key, int v)
    {
        LinkedNode *temp= new LinkedNode(key);
        LinkedNode *n = Head;

        while(n!=NULL)
        {
            if(n->val == v)
            {
                temp->next= n->next;
                n->next=temp;
                return;
            }
            n= n->next;
        }

        cout<< "Node doesn't exist" <<endl;
    }
    

    void Update_node(int key, int v)
    {
        LinkedNode *n = Head;

        while(n!=NULL)
        {
            if(n->val == v)
            {
                n->val= key;

                return;
            }
            n= n->next;
        }

        cout << "Node doesn't exist" << endl;
    }

    void Remove_head()
    {
        if(Head==nullptr){
            cout << "List is Empty" << endl;
            return;
        }

        Head= Head->next;
    }

    void Remove_element(int key)
    {
        LinkedNode *temp= new LinkedNode(key);
        LinkedNode *n = Head;

        while(n!=NULL)
        {
            if(n->next->val == key)
            {
                n->next=n->next->next;
                return;
            }
            n= n->next;
        }

        cout << "Node doesn't exist" << endl;
    }

    void Remove_end()
    {
        LinkedNode *n = Head;

        while(n!=NULL)
        {
            if(n->next == nullptr)
            {
                Head= nullptr;
                Tail= nullptr;
            }

            else if(n->next->next == nullptr)
            {
                n->next=nullptr;
                return;
            }
            n= n->next;
        }
    }

    void print()
    {
        // print the full list;
        if (Head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }

        else
        {
            LinkedNode *n = Head;
            
            while(n!=NULL)
            {
                cout<< n->val << " ";
                n = n->next;
            }
            
            cout<< endl;
        }
    }
};

int main()
{
    LinkedList list= LinkedList();
     int input, key, value;

    while (input!=8)
    {
        cout<<" Press 1 to insert at front "<<endl;
        cout<<" Press 2 to insert at back "<<endl;
        cout<<" Press 3 to insert after a node "<<endl;
        cout<<" Press 4 to update a node "<<endl;
        cout<<" Press 5 to remove the first node "<<endl;
        cout<<" Press 6 to remove a node "<<endl;
        cout<<" Press 7 to remove the last node "<<endl;
        cout<<" Press 8 to exit. "<<endl;

        cout << "Enter your choice: ";
   
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter the key: ";
                cin >> key;
                list.Insert_front(key);
                list.print();
                break;
            case 2:
                cout << "Enter the key: ";
                cin >> key;
                list.Insert_back(key);
                list.print();
                break;
            case 3:
                cout << "Enter the key to insert: ";
                cin >> key;
                cout << "Enter the value to insert after: ";
                cin >> value;
                list.Insert_after_node(key, value);
                list.print();
                break;
            case 4:
                cout << "Enter the new key: ";
                cin >> key;
                cout << "Enter the value to update: ";
                cin >> value;
                list.Update_node(key, value);
                list.print();
                break;
            case 5:
                list.Remove_head();
                list.print();
                break;
            case 6:
                cout << "Enter the key to remove: ";
                cin >> key;
                list.Remove_element(key);
                list.print();
                break;
            case 7:
                list.Remove_end();
                list.print();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}