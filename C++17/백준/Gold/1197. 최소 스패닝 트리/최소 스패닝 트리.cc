#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e; cin >> v >> e;
	vector edge(e, array{0, 0, 0});
	for (auto& [c, a, b] : edge) {
		cin >> a >> b >> c;
	}
	sort(edge.begin(), edge.end());

	vector<int> p(v + 1, -1);
	auto find = [&](int x) {
		while(p[x] >= 0) x = p[x];
		return x;
	};

	auto merge = [&](int a, int b) -> bool {
		a = find(a);
		b = find(b);

		if (a == b) return 0;
		if (-p[a] < -p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return 1;
	};

	int res = 0;
	for (auto [c, a, b] : edge) {
		if (merge(a, b) == 0) continue;		
		res += c;
	}

	cout << res << '\n';
}