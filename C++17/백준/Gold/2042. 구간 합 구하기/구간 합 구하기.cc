#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector v(n, 0LL);  
;	for (int i = 0;i < n;i++) cin >> v[i];

	int sz = 1;
	while (sz < n)	sz *= 2;
	vector tree(sz * 2, 0LL);

	auto init = [&] {
		for (int i = 0; i < n;i++) tree[i + sz] = v[i];
		for (int i = sz - 1;i >= 1;i--) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	};
	init();

	auto update = [&](int i, long long x) {
		i += sz;
		tree[i] = x;
		while (i > 1) {
			i /= 2;
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	};
	
	auto query = [&](int l, int r) {
		l += sz;
		r += sz;
		long long ans = 0;

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
		return ans;
	};

	for (int i = 0;i < m + k;i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			// Point update query
			update(b - 1, c);
		}
		if (a == 2) {
			// print
			cout << query(b - 1, c - 1) << '\n';
		}
	}
}