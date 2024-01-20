#include<iostream>
using namespace std;

int Sort(int Array[], int n)
{
    for(int k=0,i=1;i<n;i++)
    {
        if(Array[k]>Array[i])
        {
            int temp=Array[i];
            Array[i]=Array[k];
            Array[k]=temp;
        }

        if(i==n-1)
        {
            k++;
            i=k;
        }
    }

    return 0;
}

int main()
{
    int size= 0;
    int Array[1000]={0};

    cout<<"Array Elements: ";
    for(int i=0;; i++)
    {
        cin >> Array[i];
        if(Array[i]== -1)
        {
            break;
        }
        size++;
    }

    cout<<size<<"\n";

    for(int i=0; i<size-1; i++)
    {
        Sort(Array,size);
        
        while(Array[size-1]==Array[(size-2)])
        {
            size--;
        }
        
        Array[(size-2)]= Array[size-1]-Array[(size-2)];
        size--;
        
        for(int j=0;j<size;j++)
        {
        cout<<Array[j]<<" ";
        }
        cout<<"\n";
    }

    cout<< Array[0] << endl;

    return 0;
}


