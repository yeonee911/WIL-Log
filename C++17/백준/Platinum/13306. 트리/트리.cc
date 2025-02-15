#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    auto find = [&](int x) {
        int root = x;
        while (p[root] != root) root = p[root];
        while (x != root) {
            int nxt = p[x];
            p[x] = root;

            x = nxt;
        }
        return root;
    };

    auto merge = [&](int u, int v) {
        p[u] = v;
    };

    vector<int> parent(n + 1);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        parent[i + 1] = x;
    }

    stack<tuple<int, int, int>> query;
    stack<string> ans;

    for (int i = 0; i < n - 1 + q; i++) {
        int x, u, v;
        cin >> x;
        if (x == 0) {
            cin >> u;
            query.push({0, u, parent[u]});
        } else {
            cin >> u >> v;
            query.push({1, u, v});
        }
    }

    while (!query.empty()) {
        auto [x, u, v] = query.top();
        query.pop();
        if (x == 0) {
            merge(u, v);
        } else {
            if (find(u) == find(v)) ans.push("YES\n");
            else ans.push("NO\n");
        }
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}