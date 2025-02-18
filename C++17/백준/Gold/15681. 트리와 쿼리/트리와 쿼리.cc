#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
vector<int>dp;
vector<bool>seen;
vector<vector<int>>g;

void dfs(int cur) {
    if (seen[cur]) return;
    seen[cur] = true;
    dp[cur] = 1;

    for (auto nxt : g[cur]) {
        if (seen[nxt]) continue;
        dfs(nxt);
        dp[cur] += dp[nxt];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, q;
    cin >> n >> r >> q;

    dp.resize(n + 1, 0);
    g.resize(n + 1);
    seen.resize(n + 1, false);

    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(r);

    while (q--) {
        int u;
        cin >> u;
        cout << dp[u] << '\n';
    }
}