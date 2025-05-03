#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;	cin >> n;

	vector<pair<int, int>> edge(n);
	vector<int> cost(n, 0);
	vector<vector<int>> g(n + 1);

	for (int i = 1;i < n;i++) {
		int u, v, w;	
		cin >> u >> v >> w;
		edge[i] = {u, v};
		cost[i] = w;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// path decomposition
	vector<int> dep(n + 1, 0);
	vector<int> par(n + 1, -1);
	vector<int> sz(n + 1, 1);

	auto dfs1 = [&](const auto& self, int cur) -> void {
		for (int& nxt : g[cur]) {
			if (nxt == par[cur]) continue;
			dep[nxt] = dep[cur] + 1;
			par[nxt] = cur;
			self(self, nxt);
			sz[cur] += sz[nxt];
			if (sz[g[cur][0]] < sz[nxt]) swap(g[cur][0], nxt);
		}	
	};
	dfs1(dfs1, 1);

	// update in, top array
	vector<int> in(n + 1, 0);
	vector<int> top(n + 1, 0);

	int cnt = 0;
	auto dfs2 = [&](const auto& self, int cur) -> void {
		in[cur] = ++cnt;
		for(int nxt : g[cur]) {
			if (nxt == par[cur]) continue;
			if (nxt == g[cur][0])	top[nxt] = top[cur];
			else top[nxt] = nxt;
			self(self, nxt);
		}
	};
    top[1] = 1;
	dfs2(dfs2, 1);

	int t_sz = 1;
	while(t_sz < n) t_sz *= 2;
	vector<int>tree(t_sz * 2, 0);

	auto update = [&](int i, int w) {
		i = i - 1 + t_sz;
		tree[i] = w;
		while (i > 1) {
			i /= 2;
			tree[i] = max(tree[i * 2], tree[i  * 2 + 1]);
		}
	};

	auto query = [&](int l, int r) {
		l = l - 1 + t_sz;
		r = r - 1 + t_sz;

		int res = 0;
		while(l <= r) {
			if (l % 2 == 1) res = max(res, tree[l]), l++;
			if (r % 2 == 0) res = max(res, tree[r]), r--;
			l /= 2, r /= 2;
		}
		return res;
	};

	for (int i = 1; i < n;i++) {
		auto& [a, b] = edge[i];
		if (par[b] != a) swap(a, b);
		update(in[b], cost[i]);
	}

	auto edge_update = [&](int i, int c) {
		auto [a, b] = edge[i];
		update(in[b], c);
	};

	auto path_query = [&](int a, int b) {
		int res = 0;
		while(top[a] != top[b]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			res = max(res, query(in[top[a]], in[a]));
			a = par[top[a]];
		}
		if (dep[a] > dep[b]) swap(a, b);
		res = max(res, query(in[a] + 1, in[b]));
		return res;
	};


	int m;	cin >> m;
	int q, x, y;
	for (int i = 0; i < m; i++) {
		cin >> q >> x >> y;
		if (q == 1) edge_update(x, y);
		else cout << path_query(x, y) << '\n';
	}
}