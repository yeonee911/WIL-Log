#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector input(n, 0);
	for (int i = 0;i < n;i++) cin >> input[i];

	// coordinate compression
	auto compress = [](int n, auto v) {
		vector buc(n, pair(0, 0));
		for (int i = 0;i < n;i++) {
			buc[i].first = v[i];
			buc[i].second = i;
		}
		sort(buc.begin(), buc.end());

		vector ans(n, 0);
		int cnt = 0;
		for (int l = 0, r = 0; l < n; l = r) {
			while (r < n && buc[l].first == buc[r].first) r++;
			
			for (int i = l;i < r;i++) {
				ans[buc[i].second] = cnt;
			}
			cnt++;
		}
		return ans;
	};

	// max segment tree
	int sz = 1;
	while (sz < n) sz *= 2;
	vector tree(sz * 2, 0);
	auto update = [&](int i, int x) {
		i += sz;
		tree[i] = x;
		while (i > 1) {
			i /= 2;
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	};

	auto query = [&](int l, int r) {
		l += sz;
		r += sz;
		int ans = 0;	// 구간에서 최댓값

		while (l <= r) {
			if (l % 2 == 1) {
				ans = max(tree[l], ans);
				l++;
			}
			if (r % 2 == 0) {
				ans = max(tree[r], ans);
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	};

	vector v = compress(n, input);
	vector dp(n, 0);
	for (int i = 0;i < n;i++) {
		dp[i] = query(0, v[i] - 1) + 1;
		update(v[i], dp[i]);
	}

	cout << query(0, n - 1) << '\n';
}