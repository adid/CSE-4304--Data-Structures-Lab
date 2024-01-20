#include<iostream>

using namespace std;

class Stack
{
private:
    int max_size;
    int *stack;
    int index;

public:
    Stack(int size)
    {
        max_size = size;
        stack= new int[size];
        index= 0;
    }

    void push(int a)
    {
        if(index== max_size)
        {
            cout << "Overflow" << endl;
        }

        else
        {
            stack[index]= a;
            index++;
        }
    }

    int pop()
    {
        if(index == 0)
        {
            cout << "Underflow" << endl;
        }

        else
        {
            return stack[--index];
        }
    }

    bool isEmpty()
    {
        if(index== 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(index== max_size)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    int size()
    {
        return index;
    }

    int top()
    {
        return stack[index-1];
    }

    void display() {
        cout << "Stack Contents: ";
        for (int i = 0; i < index; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    int max_size;
    cin >> max_size;

    Stack stack(max_size);

    while (true) {
        int button;
        cin >> button;

        if (button == -1)
        {
            break;
        }

        else if (button == 1)
        {
            int item;
            cin >> item;
            stack.push(item);
            stack.display();
        }

        else if (button == 2)
        {
            int popped_item = stack.pop();
            if (popped_item != -1)
            {
                cout << "Popped: " << popped_item << endl;
            }
        }

        else if (button == 3)
        {
            cout << stack.isEmpty() << endl;
        }

        else if (button == 4)
        {
            cout << stack.isFull() << endl;
        }

        else if (button == 5)
        {
            cout << stack.size() << endl;
        }

        else if (button == 6)
        {
            int top_item = stack.top();
            if (top_item != -1)
            {
                cout << "Top: " << top_item << endl;
            }
        }
    }

    return 0;
}
