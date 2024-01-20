#include <bits/stdc++.h>

using namespace std;

#define MAX 3

class Queue
{
    int Front;
    int Rear;
    int Size;
    int* Queue;

public:

    void CreateQueue()              // create a queue
    {
        Rear = -1;
        Front = -1;
        Size=0;
        Queue=new int[MAX];
    }

    void pushLeft(int item) 
    {
        if(isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        
        if (Front == -1) 
        {
            Front = Rear = 0;
        } 
        else if (Front == 0) 
        {
            Front = MAX - 1;
        } 
        else 
        {
            Front--;
        }

        Queue[Front] = item;
        Size++;
    }

    void pushRight(int item) 
    {
        if(isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (Front == -1) 
        {
            Front = Rear = 0;
        } 
        else if (Rear == MAX - 1) 
        {
            Rear = 0;
        }
        else 
        {
            Rear++;
        }

        Queue[Rear] = item;
        Size++;
    }

    int popLeft() 
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int item = Queue[Front];
            if (Front == Rear) 
            {
                Front = Rear = -1;
            } 
            else if (Front == MAX - 1) 
            {
                Front = 0;
            } 
            else 
            {
                Front++;
            }

            Size--;
            return item;
    }

    int popRight() 
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int item = Queue[Rear];
        if (Front == Rear) 
        {
        Front = Rear = -1;
        } 
        else if (Rear == 0) 
        {
            Rear = MAX - 1;
        } 
        else 
        {
        Rear--;
        }
        
        Size--;
        return item;
    }

    int size()
    {
        return Size;
    }

    int front()
    {
        return Queue[Front];
    }

    int rear()
    {
        return Queue[Rear];
    }

    bool isEmpty()
    {
        if(Front == Rear)
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
        if(Size==MAX)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void showQueue()
    {
        for(int i=Front;i<=Rear; i++)
        {
            cout << Queue[i] << " ";
        }

        cout<< "\n";
    }

};

int main(void)
{
    class Queue MyQueue;
    MyQueue.CreateQueue();

    MyQueue.pushLeft(10);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.pushRight(20);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.popLeft();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.pushRight(30);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.pushLeft(40);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.pushRight(50);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.popRight();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.popRight();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.popLeft();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    return 0;
}
