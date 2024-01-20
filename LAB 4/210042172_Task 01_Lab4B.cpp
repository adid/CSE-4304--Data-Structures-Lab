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

    void Enqueue(int x)
    {
        if(isFull())                            // can't enqueue due  to queue full
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (Front == -1)                   // queue is empty
        {
            Front = Rear = 0;
            Queue[Rear] = x;
            Size++;
        }
        else if (Rear == Size-1 && Front != 0)  // queue reached to its last element
        {
            Rear = 0;
            Queue[Rear] = x;
            Size++;
        }
        else                                    // normal queue
        {
            Rear++;
            Queue[Rear] = x;
            Size++;
        }

        cout<< "The queue is: ";
        showQueue();
    }

    void Dequeue()
    {
        if (isEmpty())            //queue is empty
        {
            cout << "Queue is empty" << endl;
            Size = 0;
            return;
        }

        int val = Queue[Front];
        Queue[Front] = -1;

        if (Front == Rear)          //queue has only one element
        {
            Front = -1;
            Rear = -1;
            Size = 0;
        }
        else if (Front == Size-1)   //initial queue is at its last
        {
            Front = 0;
            Size--;
        }
        else                        //normal queue
        {
            Front++;
            Size--;
        }

        cout<< "The queue is: ";
        showQueue();

        return;
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

    MyQueue.Enqueue(10);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Enqueue(20);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Dequeue();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Enqueue(30);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Enqueue(40);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Enqueue(50);
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Dequeue();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Dequeue();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    MyQueue.Dequeue();
    cout<< "Size: "<< MyQueue.size() << endl;
    cout<< "Front: "<< MyQueue.front() << endl;
    cout<< "Rear: "<< MyQueue.rear() << endl;
    cout<< "Full: "<< MyQueue.isFull() << endl;
    cout<< "Empty: "<< MyQueue.isEmpty() << endl;
    cout<< endl;

    return 0;
}
