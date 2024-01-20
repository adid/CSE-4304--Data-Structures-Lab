#include <iostream>
#include <vector>

using namespace std;

void replaceElements(vector<int>& A, int x, int y, int n)
{
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            A[i] = y;
        }
    }
}

void outputElement(vector<int> A, int idx) {
    if (idx >= 0 && idx < A.size()) {
        cout << "A[" << idx << "] = " << A[idx-1] << endl;
    }
}

void printElement(vector<int> A, int n) {
    cout << "A = {";
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    int n, q, test;

    cout << "Enter the number of Test cases to run: ";
    cin>> test;

for(int i=0 ; i<test; i++) {

    cout << "Enter the number of elements of array || number of operations to run: ";
    cin >> n >> q;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < q; i++) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int x, y;
            cin >> x >> y;
            replaceElements(A, x, y, n);
            printElement(A,n);

        } else if (operation == 2) {
            int idx;
            cin >> idx;
            outputElement(A, idx);
        }
    }
}
    return 0;
}