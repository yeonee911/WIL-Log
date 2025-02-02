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
	vector tree(sz * 2, pair{INF, -1});	// 값, 인덱스

	auto init = [&] {
		for (int i = 0; i < n;i++) tree[i + sz] = { v[i], i };
		for (int i = sz - 1;i >= 1;i--) {
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
			// cout << i << " : " << tree[i].first << " " << tree[i].second << endl;
		}
	};
	init();

	auto update = [&](int i, long long x) {
		i += sz;
		tree[i].first = x;
		while (i > 1) {
			i /= 2;
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
		}
	};
	
	auto query = [&](int l, int r) {
		l += sz;
		r += sz;
		pair<int, int> mn = { INF, -1 };

		while (l <= r) {
			if (l % 2 == 1) {
				mn = min(mn, tree[l]);
				l++;
			}
			if (r % 2 == 0) {
				mn = min(mn, tree[r]);
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return mn.second + 1;
	};

	for (int i = 0;i < m;i++) {
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