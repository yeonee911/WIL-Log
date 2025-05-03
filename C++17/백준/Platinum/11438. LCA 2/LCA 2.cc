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
    int m; cin >> m;
    
    dfs(1);
    int maxDepth = 0;
    for (auto x : depth) maxDepth = max(x, maxDepth);

    int tmp = 1; int k = 0;
    while (tmp < maxDepth) tmp *= 2, k++;
    
    vector table(k + 1, vector<int>(n + 1, 0));
    for (int i = 0;i <= n;i++) table[0][i] = parent[i];
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= n;j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0;i <= k;i++) {
            if (diff >> i & 1) {
                u = table[i][u];
            }
        }

        if (u == v) return u;
        for (int i = k;i >= 0;i--) {
            if (table[i][u] == table[i][v]) continue;
            u = table[i][u];
            v = table[i][v];
        }
        return parent[u];
    };

    for (int i = 0;i < m;i++) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}