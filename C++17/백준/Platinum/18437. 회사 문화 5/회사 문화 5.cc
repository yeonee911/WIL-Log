#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> par(n + 1);
	vector<vector<int>>g(n + 1);
	for(int i = 1;i <=n;i++) cin >> par[i];
	for (int i = 1; i <= n;i++) {
		if (par[i] == 0) continue;
		g[par[i]].push_back(i);
	}

	vector<int> in(n + 1, 0);
	vector<int> out(n + 1, 0);

	int cnt = 0;
	auto recursive = [&](const auto&self, int cur) -> void {
		in[cur] = ++cnt;
		for (auto nxt : g[cur]) {
			self(self, nxt);
		}
		out[cur] = cnt;
	};
	recursive(recursive, 1);

	int sz = 1;
	while(sz < n) sz *= 2;

	vector<long long> tree(sz * 2, 0);
	vector<long long> lazy(sz * 2, 0);

	auto push = [&](int node, int l, int r) -> void {
		if (lazy[node] != 0) {
			if (lazy[node] == 1) tree[node] = r - l + 1;
			else tree[node] = 0;	// lazy[node] == -1
			if (l != r) {
				lazy[node * 2] = lazy[node];
				lazy[node * 2 + 1] = lazy[node];
			}	
			lazy[node] = 0;
		}
	};

	auto update = [&](int l, int r, int x) {
		auto rec = [&](const auto& self, int node, int node_l, int node_r) -> void {
			push(node, node_l, node_r);
			if (r < node_l || node_r < l) return;
			if (l <= node_l && node_r <= r) {
				lazy[node] = x;
				push(node, node_l, node_r);
				return;
			}
			int mid = (node_l + node_r)/2;
			self(self, node *2, node_l, mid);
			self(self, node * 2 + 1, mid + 1, node_r);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
		rec(rec, 1, 1, sz);
	};

	auto query = [&](int l, int r) -> long long {
		auto rec = [&](const auto& self, int node, int node_l, int node_r) -> long long {
			push(node, node_l, node_r);
			if (r < node_l || node_r < l) return 0;
			if (l <= node_l && node_r <= r) return tree[node];
			int mid = (node_l + node_r) / 2;
			return self(self, node * 2, node_l, mid) + self(self, node * 2 + 1, mid + 1, node_r);
		};
		return rec(rec, 1, 1, sz);
	};


	update(1, n, 1);
	int m; cin >> m;
	for (int i = 1;i <= m;i++) {
		int t, j;
		cin >> t >> j;
		if (t == 1)	update(in[j] + 1, out[j], 1);
		else if (t == 2)	update(in[j] + 1, out[j], -1);
		else {	// t == 3
			cout << query(in[j] + 1, out[j]) << '\n';
		}	
	}
}