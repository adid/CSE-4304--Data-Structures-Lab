#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string value;
    Node* next;

    Node(string val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void print_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void insert_back(string value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } 
        else {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
    }

    void remove_duplicates() {
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->value == current->next->value) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
                length--;
            } 
            else {
                current = current->next;
            }
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    while (true) {
        string value;
        cout << "Enter a value (-1 to Stop): ";
        cin >> value;
        
        if (value == "-1") {
            break;
        }
        list.insert_back(value);
    }

    list.remove_duplicates();
    cout << "Linked list with duplicates removed:" << endl;
    list.print_list();

    return 0;
}
