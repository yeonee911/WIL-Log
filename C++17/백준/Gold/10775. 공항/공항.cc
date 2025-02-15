#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, p;
    cin >> g >> p;

    parent.resize(g + 1);
    for (int i = 1; i <= g;i++) parent[i] = i;

    auto merge = [&](int u, int v) -> bool {
        u = find(u);
        v = find(v);

        if (u == v) return 0;
        if (u > v) swap(u, v);
        parent[v] = u;
        return 1;
    };

    for (int i = 1;i <= p;i++) {
        int x; cin >> x;
        x = find(x);
        if (x == 0) {
            cout << i - 1;
            return 0;
        }
        merge(x, x - 1);
    }
    cout << p;
}