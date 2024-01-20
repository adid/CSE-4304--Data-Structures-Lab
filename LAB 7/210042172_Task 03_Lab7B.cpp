#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        if(size[x] < size[y]) {
            swap(x, y);
        }
        
        parent[y] = x;
        size[x]+=size[y];
    }
};

int main() {
    int n, m;

    cout << "Enter Number of Nodes and Edges: ";
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        cout << "Enter Number 2 Nodes to connect: ";
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.unite(u, v);
    }

    int q;
    cout << "Enter Number of Queries: ";
    cin >> q;

    while (q--) {
        int x, y;
        
        cin >> x >> y;
        
        x--;
        y--;

        if (dsu.find(x) == dsu.find(y)) {
            cout << "Yes" << endl;
        } 
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}