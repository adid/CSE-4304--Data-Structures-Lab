#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void print_list() {

        if(head== nullptr){
            cout<<"Empty list"<<endl;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout<<endl;
    }

    void print_list_reverse() {

        if(tail== nullptr){
            cout<<"Empty list"<<endl;
        }

        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->prev;
        }

        cout<<endl;
    }

    bool insert_front(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } 
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        length++;
        return true;
    }

    bool insert_back(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } 
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        length++;
        return true;
    }

    bool insert_after_node(int key, int value) {
        Node* temp = head;
        Node* new_node = new Node(value);
        
        while (temp != nullptr) {
            if (temp->value == key) {
                new_node->prev = temp;
                new_node->next = temp->next;
                if (temp->next) {
                    temp->next->prev = new_node;
                }
                temp->next = new_node;
                length++;
                return true;
            }
            temp = temp->next;
        }

        cout << "Key value not found" << endl;
        return false;
    }

    void update_node(int key, int v)
    {
        Node* n = head;

        while(n!=NULL)
        {
            if(n->value == v)
            {
                n->value= key;

                return;
            }
            n= n->next;
        }

        cout << "Node doesn't exist" << endl;
    }

    bool remove_head() {
        if (length == 0) {
            return false;
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    bool remove_end() {
        if (length == 0) {
            return false;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    bool remove_element(int key) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->value == key) {
                if (prev) {
                    prev->next = temp->next;
                } 
                else {
                    head = temp->next;
                }
                if (temp->next) {
                    temp->next->prev = prev;
                } 
                else {
                    tail = prev;
                }
                delete temp;
                length--;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key value not found" << endl;
        return false;
    }
};

int main() {
    
     DoublyLinkedList list= DoublyLinkedList();
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
                list.insert_front(key);
                list.print_list();
                list.print_list_reverse();
                break;
            case 2:
                cout << "Enter the key: ";
                cin >> key;
                list.insert_back(key);
                list.print_list();
                list.print_list_reverse();
                break;
            case 3:
                cout << "Enter the key to insert: ";
                cin >> key;
                cout << "Enter the value to insert after: ";
                cin >> value;
                list.insert_after_node(key, value);
                list.print_list();
                list.print_list_reverse();
                break;
            case 4:
                cout << "Enter the new key: ";
                cin >> key;
                cout << "Enter the value to update: ";
                cin >> value;
                list.update_node(key, value);
                list.print_list();
                list.print_list_reverse();
                break;
            case 5:
                list.remove_head();
                list.print_list();
                list.print_list_reverse();
                break;
            case 6:
                cout << "Enter the key to remove: ";
                cin >> key;
                list.remove_element(key);
                list.print_list();
                list.print_list_reverse();
                break;
            case 7:
                list.remove_end();
                list.print_list();
                list.print_list_reverse();
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
