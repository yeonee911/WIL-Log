#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int>parent;
vector<int>depth;
vector<vector<int>>g;
vector<int>seen;

void dfs(int r) {
    if (seen[r]) return;
    seen[r] = true;

    for (auto x : g[r]) {
        if (seen[x]) continue;
        parent[x] = r;
        depth[x] = depth[r] + 1;
        dfs(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    parent.resize(n + 1, 0);
    depth.resize(n + 1, 0);
    g.resize(n + 1);
    seen.resize(n + 1, false);
    for (int i = 0;i < n - 1;i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        while (depth[u] != depth[v]) u = parent[u];
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    };

    int m; cin >> m;
    for (int i = 0;i < m;i++) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}