#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k, x, count=0;
    vector<int> cookies;

    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        cookies.push_back(x);
    }

    priority_queue<int, vector<int>, greater<int>> pririty(cookies.begin(), cookies.end());

    while(true)
    {
        if(pririty.top()>=k)
        {
            break;
        }

        else
        {
            int a=pririty.top();
            pririty.pop();
            int b=pririty.top();
            pririty.pop();
            pririty.push(a+b*2);

            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}