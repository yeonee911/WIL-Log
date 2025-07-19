#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;	cin >> n >> m;
	vector<pair<int, int>> v(n + 1, {0, 0});
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		v[i].first = x;
	}
	for (int i = 0; i < m; i++) {
		int u, x, c; cin >> u >> x >> c;
		if (u + 1 <= n) v[u + 1].second += c;
		if (x + 1 <= n) v[x + 1].second -= c;
	}
	for (int i = 1; i <= n; i++) {
		v[i].second = v[i].second + v[i - 1].second;	
	}

	for (int i = 2; i <= n; i++) {
		long long res = 0;
		long long w = v[i].first; long long c = v[i].second;
		if (w == 1) res += c * c;
		else if (w >= c) res += c;
		else {
			res += (c / w + 1) * (c / w + 1) * (c % w);
			res += (c / w) * (c / w) * (w - c % w); 
		}
		cout << res << '\n';
	}
}
