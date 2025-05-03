#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1 << 30;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;	cin >> n;

	vector<vector<int>> g(n + 1);

	for (int i = 1;i < n;i++) {
		int u, v;	
		cin >> u >> v;
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
			if (g[cur][0] == par[cur] || sz[g[cur][0]] < sz[nxt]) swap(g[cur][0], nxt);
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
	vector<int>tree(t_sz * 2, INF);

	vector<int> ans(n + 1, 0);
	for (int i = 1;i <= n;i++) {
		ans[in[i]] = i;
	}

	auto update = [&](int i) {
		int idx = i;
		i = i - 1 + t_sz;
		if (tree[i] != INF) tree[i] = INF; // black -> white
		else tree[i] = idx;	// white -> black

		while (i > 1) {
			i /= 2;
			tree[i] = min(tree[i * 2], tree[i  * 2 + 1]);
		}
	};

	auto query = [&](int l, int r) {
		l = l - 1 + t_sz;
		r = r - 1 + t_sz;

		int res = INF;
		while(l <= r) {
			if (l % 2 == 1) res = min(res, tree[l]), l++;
			if (r % 2 == 0) res = min(res, tree[r]), r--;
			l /= 2, r /= 2;
		}

		return res;
	};

	auto path_query = [&](int a, int b) {
		int res = INF;
		while(top[a] != top[b]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			res = min(res, query(in[top[a]], in[a]));
			a = par[top[a]];
		}
		if (dep[a] > dep[b]) swap(a, b);
		res = min(res, query(in[a], in[b]));

		if (res == INF) return -1;
		else return ans[res];
	};

	int m;	cin >> m;
	for (int i = 0; i < m; i++) {
		int q, a;	cin >> q >> a;
		if (q == 1) update(in[a]);
		else cout << path_query(1, a) << '\n';
	}
}