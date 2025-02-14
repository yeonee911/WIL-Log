#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> p;

int find(int x) {
	// 배열의 인덱스와 값이 같으면 루트 노드이다
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	p.resize(n + 1);
	for (int i = 0;i <= n;i++) p[i] = i;

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