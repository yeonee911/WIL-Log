#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>dp;
vector<vector<int>>g;
vector<int> seen;

void dfs(int cur) {
    if (seen[cur]) return;
    seen[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (auto nxt : g[cur]) {
        if (seen[nxt]) continue;
        dfs(nxt);
        dp[cur][0] += dp[nxt][1];
        dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    dp.resize(n + 1, vector<int>(2, 0));
    g.resize(n + 1);
    seen.resize(n + 1, false);

    for (int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(2);

    cout << min(dp[2][0], dp[2][1]);
}