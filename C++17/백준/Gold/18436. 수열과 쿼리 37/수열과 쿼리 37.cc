#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	vector v(n, 0);  
;	for (int i = 0;i < n;i++) cin >> v[i];

	cin >> m;

	int sz = 1;
	while (sz < n)	sz *= 2;
	vector tree(sz * 2, 0);

	auto init = [&] {
		for (int i = 0; i < n;i++) {
			if (v[i] % 2 == 0) tree[i + sz] = 1;
		}
		for (int i = sz - 1;i >= 1;i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	};
	init();

	auto update = [&](int i, long long x) {
		i += sz;
		if (x % 2 == 0) tree[i] = 1;
		else tree[i] = 0;
		while (i > 1) {
			i /= 2;
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	};
	
	auto query = [&](int q, int l, int r) {
		int cnt = r - l + 1;
		l += sz;
		r += sz;
		
		int ans = 0;

		while (l <= r) {
			if (l % 2 == 1) {
				ans += tree[l];
				l++;
			}
			if (r % 2 == 0) {
				ans += tree[r];
				r--;
			}
			l /= 2;
			r /= 2;
		}
		if (q == 2) return ans;
		else return cnt - ans;
	};

	for (int i = 0;i < m;i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			// Point update query
			update(b - 1, c);
		}
		else {
			// print
			cout << query(a, b - 1, c - 1) << '\n';
		}
	}
}