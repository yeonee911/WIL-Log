#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, w;
    cin >> p >> w;  // p : node, w : edge

    int c, v;
    cin >> c >> v;

    vector<tuple<int, int, int>> edge(w);
    for (int i = 0;i < w;i++) {
        int s, e, width;
        cin >> s >> e >> width;
        edge[i] = { width, s, e };
    }

    sort(edge.begin(), edge.end(), greater<>());

    vector parent(p, -1);
    auto find = [&](int x) {
        while (parent[x] >= 0) x = parent[x];
        return x;
    };

    auto merge = [&](int u, int v) -> bool{
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        if (-parent[u] < -parent[v]) swap(u, v);
        parent[u] += parent[v];
        parent[v] = u;
        return 1;
    };

    for (int i = 0;i < w;i++) {
        auto [width, s, e] = edge[i];
        merge(s, e);
        if (find(c) != find(v)) continue;
        cout << width;
        return 0;
    }
}