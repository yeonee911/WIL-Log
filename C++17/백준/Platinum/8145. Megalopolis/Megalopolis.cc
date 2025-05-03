#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int>dep(n + 1, 0);
	vector<int>par(n + 1, -1);
	vector<int>sz(n + 1, 1);
	auto dfs1 = [&](const auto& self, int cur)-> void {
		for (int& nxt : g[cur]){
			auto it = find(g[nxt].begin(), g[nxt].end(), cur);
			g[nxt].erase(it);
			dep[nxt] = dep[cur] + 1;
			par[nxt] = cur;
			self(self, nxt);
			sz[cur] += sz[nxt];
			if (sz[g[cur][0]] < sz[nxt]) swap(g[cur][0], nxt);
		}
	};
	dfs1(dfs1, 1);

	vector<int>in(n + 1, 0);
	vector<int>top(n + 1, 0);
	int cnt = 0;
	auto dfs2 = [&](const auto& self, int cur) -> void {
		in[cur] = ++cnt;
		for (int nxt : g[cur]){
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
	
	auto update = [&](int i) {	// i is children
		i = i - 1 + t_sz;
		if (tree[i] == 0) tree[i] = 1;
		else tree[i] = 0;

		while(i > 1) {
			i /= 2;
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	};

	auto query = [&](int l, int r) {
		l = l - 1 + t_sz;
		r = r - 1 + t_sz;
		int res = 0;
		while(l <= r) {
			if (l % 2 == 1) res += tree[l], l++;
			if (r % 2 == 0) res += tree[r], r--;

			l /= 2, r /= 2;
		}
		return res;
	};

	// init
	for (int i = 2; i <= n;i++) update(i);

	auto edge_update = [&](int a, int b) {
		// b is children
		if (par[a] == b) swap(a, b);
		update(in[b]);
	};

	auto path_query = [&](int a, int b) {
		int res = 0;
		while(top[a] != top[b]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			res += query(in[top[a]], in[a]);
			a = par[top[a]];
		}
		if (dep[a] > dep[b]) swap(a, b);
		res += query(in[a] + 1, in[b]);

		return res;
	};

	int m; cin >> m;
	for (int i = 1; i < m + n; i++) {
		string str; cin >> str;
		int a;	cin >> a;
		if (str == "A") {
			int b; cin >> b;
			edge_update(a, b);
		}
		else {
			cout << path_query(1, a) << '\n';
		}
	}
}
