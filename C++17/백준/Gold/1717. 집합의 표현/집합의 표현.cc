#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector p(n + 1, -1);

	auto find = [&](int x) {
		int root = x;
		while (p[root] >= 0) root = p[root];

		while (x != root) {
			int nxt = p[x];
			p[x] = root;

			x = nxt;
		}
		return root;
	};

	auto merge = [&](int a, int b) -> bool{
		a = find(a);
		b = find(b);
		if (a == b) return 0;
		if (-p[a] < -p[b]) swap(a, b);

		p[a] += p[b];
		p[b] = a;
		return 1;
	};
	

	for (int i = 0;i < m;i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) merge(a, b);
		else {
			a = find(a);
			b = find(b);
			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}