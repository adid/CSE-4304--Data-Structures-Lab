#include <iostream>
#include <vector>

using namespace std;



int main() {
    cout << "Enter Nodes || edges: ";
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adjMatrix(n, vector<char>(n, false));
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjMatrix[u][v] = true;
        adjMatrix[v][u] = true;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    

    cout << "List view:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] + 1;
            if (j < adjList[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "Matrix view:" << endl;
    cout << "  ";
    
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j]) {
                cout << "x ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
