#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int sz = 1;
	while (sz < MAX + 1) sz *= 2;
	vector tree(sz * 2, 0);

	// prefix sum
	auto update = [&](int i , int x) {
		i += sz;
		tree[i] += x;
		while (i > 1) {
			i /= 2;
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	};

	auto kth = [&](int k) {
		int i = 1;
		while (i < sz) {
			if (tree[i * 2] >= k) i *= 2;
			else k -= tree[i * 2], i = 2 * i + 1;
		}
		return i - sz;
	};

	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b;
			int ans = kth(b);
			cout << ans << '\n';
			update(ans, -1);
		}
		else {
			cin >> b >> c;
			update(b, c);
		}
	}
}