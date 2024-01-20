#include <iostream>
using namespace std;

void min_Heapify(int array[],int i, int n)              // makes parent less than child
{
    int smallest = i;
    int left= 2*i + 1;
    int right= 2*i + 2;

    if(array[left] < array[smallest] && left < n)       // left child is smaller than parent  
    {
        smallest= left;
    }

    if(array[right] < array[smallest] && right < n)     // right child is smaller than parent
    {
        smallest= right;
    }

    if(smallest!= i)                                    // recursion to heapify subtree
    {
        swap(array[i],array[smallest]);
        min_Heapify(array,smallest,n);
    }
}

int heap_Minimum(int array[], int n)
{
    int x = (n / 2);

    for (int i = x; i >= 0; i--)
    {
        min_Heapify(array, i, n);
    }

    return array[0];
}

int heap_Extract_Min(int array[], int n)
{
    int temp= array[0];
    
    for(int i = 1 ; i<n; i++)
    {
        array[i-1] = array[i];
    }

    array[n-1] = 0;

    heap_Minimum(array, n-1);

    return temp;
}

void min_Heap_Insert(int value, int array[], int n)
{
    array[n]= value;
    heap_Minimum(array,n+1);
}

void print_Heap(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void Heap_decrease_key(int heap[], int p, int k)
{
    heap[p-1] -= k;
    heap_Minimum(heap,p);
}

void Heap_increase_key(int heap[], int p, int k)
{
    heap[p-1] += k;
    heap_Minimum(heap,p);
}

int main()
{
    int a[100], n = 0;
    for(int i = 0 ; ; i++)
    {
        cin>>a[i];

        if(a[i] == -1)
        {
            break;
        }

        n++;
    }

    int input;

    while(true)
    {
        cin>>input;

        if(input == 1)
        {
            cout<<heap_Minimum(a,n)<<endl;
            print_Heap(a,n);
        }
        
        else if(input == 2)
        {
            cout<<heap_Extract_Min(a,n)<<endl;
            --n;
            print_Heap(a,n);
        }
        else if(input == 3)
        {
            int x;
            cin>>x;
            min_Heap_Insert(x,a,n);
            ++n;
            print_Heap(a,n);
        }
        else if(input == 4)
        {
            int p,k;
            cin>> p >> k;
            Heap_decrease_key(a,p,k);
            print_Heap(a,n);
        }
        else if(input == 5)
        {
            int p,k;
            cin>> p >> k;
            Heap_decrease_key(a,p,k);
            print_Heap(a,n);
        }
        else
        {
            break;
        }
    }

    return 0;
}