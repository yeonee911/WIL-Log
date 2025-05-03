#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n;i++) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// path decomposition
	vector<int> dep(n + 1, 0);
	vector<int> par(n + 1, -1);
	vector<int> sz(n + 1, 1);
	auto dfs1 = [&](const auto& self, int cur) -> void {
		for (auto& nxt : g[cur]) {
			auto it = find(g[nxt].begin(), g[nxt].end(), cur);
			g[nxt].erase(it);
			dep[nxt] = dep[cur] + 1;
			par[nxt] = cur;
			self(self, nxt);
			sz[nxt] += sz[cur];
			if (sz[g[cur][0]] < sz[nxt]) swap(g[cur][0], nxt);
		}
	};
	dfs1(dfs1, 1);

	vector<int> in(n + 1, 0);
	vector<int> top(n + 1, 0);
	int cnt = 0;
	auto dfs2 = [&](const auto& self, int cur)-> void {
		in[cur] = ++cnt;
		for (int nxt : g[cur]) {
			if (nxt == g[cur][0]) top[nxt] = top[cur];
			else top[nxt] = nxt;
			self(self, nxt);
		}
	};
	top[1] = 1;
	dfs2(dfs2, 1);

	int t_sz = 1;
	while(t_sz < n) t_sz *= 2;
	vector<int> tree(t_sz * 2, 0);
	vector<int> lazy(t_sz * 2, 0);

	auto push = [&](int node, int l, int r) -> void {
		if (lazy[node] != 0) {
			tree[node] += lazy[node] * (r - l + 1);
			if (l != r) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}; 

	auto update = [&](int l, int r) {
		auto rec = [&](const auto& self, int node, int node_l, int node_r) -> void {
			push(node, node_l, node_r);
			if (r < node_l || node_r < l) return;
			if (l <= node_l && node_r <= r) {
				lazy[node] = 1;
				push(node, node_l, node_r);
				return;
			}
			int mid = (node_l + node_r) / 2;
			self(self, node * 2, node_l, mid);
			self(self, node * 2 + 1, mid + 1, node_r);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
		rec(rec, 1, 1, t_sz);
	};

	auto query = [&](int l, int r) -> long long {
		auto rec = [&](const auto& self, int node, int node_l, int node_r) -> long long {
			push(node, node_l, node_r);
			if (r < node_l || node_r < l) return 0;
			if (l <= node_l && node_r <= r) return tree[node];
			int mid = (node_l + node_r) / 2;
			return self(self, node * 2, node_l, mid) + self(self, node * 2 + 1, mid + 1, node_r);
		};
		return rec(rec, 1, 1, t_sz);
	};

	auto path_update = [&](int u, int v) {
		while(top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			update(in[top[u]], in[u]);
			u = par[top[u]];
		}
		if (dep[u] > dep[v]) swap(u, v);
		update(in[u] + 1, in[v]);
	};

	auto path_query = [&](int u, int v) -> long long {
		int res = 0;
		while(top[u] != top[v]){
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			res += query(in[top[u]], in[u]);
			u = par[top[u]];
		}
		if (dep[u] > dep[v]) swap(u, v);
		res += query(in[u] + 1, in[v]);
		return res;
	};

	for (int i = 0;i < m;i++) {
		string q; cin >> q;
		int u, v; cin >> u >> v;
		if (q == "P") path_update(u, v); 
		else cout << path_query(u, v) << '\n';
	}
}