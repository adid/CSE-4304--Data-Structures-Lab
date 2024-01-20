#include <bits/stdc++.h>

using namespace std;

queue<int> q1, q2;

// Push into the Stack
void push_s(int x)
{
    q2.push(x);

    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    queue<int> q=q1;
    q1=q2;
    q2=q;
}
// Removes the element on top of the stack.
void pop_s()
{
    if(q1.empty())
    {
        return;
    }

    q1.pop();
}
// Get the top element.
int top_s()
{
    if(q1.empty())
    {
        return -1;
    }

    return q1.front();
}
// Return whether the stack is empty.
bool empty_s()
{
    if(q1.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;

    return 0;
}
