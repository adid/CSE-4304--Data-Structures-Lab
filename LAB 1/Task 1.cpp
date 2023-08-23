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

// int Sort2(int Array[], int n, int array)
// {
//     int newarray[100000]={0};

//     for(int i=0;i<n;i++)
//     {
//         newarray[i]++;
//     }

//     for(int i=0;i<10000;i++)
//     {
//         if(newarray[i]!=0)
//         {
//              for(int j=0;j<newarray[j];j++)
//              {
//                 cout << i << " ";
//              }  
//         }
//     }

//     return 0;
// }

int main()
{
    int Array[]={8,7,2,5,3,1,8,5};
    int size=0;

    for(int i=1;Array[i]!='\0';i++)
    {
        size++;
    }

    Sort(Array,size);

    for(int i=0;i<size;i++)
    {
        cout<<Array[i]<<" ";
    }

    return 0;
}