#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int>parent;
vector<int>depth;
vector<vector<int>>g;
vector<int>seen;

void dfs(int r, int d) {
    if (seen[r]) return;

    depth[r] = d;
    seen[r] = true;

    for (auto x : g[r]) {
        if (seen[x]) continue;
        parent[x] = r;
        dfs(x, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    parent.resize(n + 1, 1);
    depth.resize(n + 1, 0);
    g.resize(n + 1);
    seen.resize(n + 1, false);
    for (int i = 0;i < n - 1;i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    auto lca = [&](int u, int v) {
        // 노드 depth 맞추기
        int du = depth[u];  // depth u
        int dv = depth[v];  // depth v
        
        if (du < dv) {        // du > dv
            swap(du, dv);
            swap(u, v);
        }

        while (du != dv) {
            u = parent[u];
            du--;
        }

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