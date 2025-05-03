#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int sz = 1;
	while(sz < n) sz *= 2;

	vector<long long> tree(sz * 2, 0);
	vector<long long> lazy(sz * 2, 0);

	auto push = [&](const auto& self, int node, int l, int r) -> void {
		if (lazy[node] != 0) {
			tree[node] += lazy[node] * (r - l + 1);
			if (l != r) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	};

	auto update = [&](int l, int r, long long x) {
		auto rec = [&](const auto& self, int node, int node_l, int node_r) -> void {
			push(self, node, node_l, node_r);
			if (r < node_l || node_r < l) return;
			if (l <= node_l && node_r <= r) {
				lazy[node] = x;
				push(self, node, node_l, node_r);
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
			push(self, node, node_l, node_r);
			if (r < node_l || node_r < l) return 0;
			if (l <= node_l && node_r <= r) return tree[node];
			int mid = (node_l + node_r) / 2;
			return self(self, node * 2, node_l, mid) + self(self, node * 2 + 1, mid + 1, node_r);
		};
		return rec(rec, 1, 1, sz);
	};


	for (int i = 1;i <= n;i++) {
		long long x; cin >> x;
		update(i, i, x);
	}

	for (int i = 1;i <= m + k;i++) {
		int t; cin >> t;
		if (t == 1) {
			int l, r;
			long long x;
			cin >> l >> r >> x;
			update(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}	}
}