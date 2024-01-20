#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkParentheses(string s) 
{
    stack<char> charStack;

    for (char c :s) 
    {
        if (c == '(' || c == '{' || c == '[') 
        {
            charStack.push(c);
        } 
        if (c == ')' && charStack.top()=='(')
        {
            charStack.pop();
        }
        if (c == '}' && charStack.top()=='{')
        {
            charStack.pop();
        }
        if (c == ']' && charStack.top()=='[')
        {
            charStack.pop();
        }

        cout<< charStack.top() << " ";
    }

    cout<< endl;

    if(charStack.empty())
    {
        cout << "Yes" << endl;
        return true;
    }

    else
    {
        cout << "No" << endl;
        return false;
    }
}

int main() {
    int n;
    
    cin >> n;
    cin.ignore(n);

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        checkParentheses(word);
    }

    return 0;
}
