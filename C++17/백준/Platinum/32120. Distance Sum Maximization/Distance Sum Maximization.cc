#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto bfs = [&](int s, vector<int> v) {
		vector<int> seen(n + 1, false);
		queue<int> q;
		int dist = 0;
		q.push(s);
		seen[s] = true;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			dist = v[cur] + 1;
			for (auto nxt : g[cur]) {
				if (seen[nxt]) continue;
				q.push(nxt);
				seen[nxt] = true;
				v[nxt] = dist;
			}
		}

		return v;
	};

	vector<int> v1(n + 1, 0);
	v1 = bfs(1, v1);
	int a = 0; int t = 0;
	for (int i = 1; i <= n; i++) {
		if (t < v1[i]) {t = v1[i]; a = i;}	
	}

	vector<int> va(n + 1, 0);
	va = bfs(a, va);
	int b = 0; t = 0;
	for (int i = 1; i <= n; i++) {
		if (t < va[i]) {t = va[i]; b = i;}
	}

	vector<int> vb(n + 1, 0);
	vb = bfs(b, vb);
	
	int c = 0; t = 0;
	for (int i = 1; i <= n; i++) {
		if (t < va[i] + vb[i]) {t = va[i] + vb[i]; c = i;}
	}

	vector<int> vc(n + 1, 0);
	vc = bfs(c, vc);

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		int res = max(va[u] + va[v], vb[u] + vb[v]);
		res = max(res, vc[u] + vc[v]);
		cout << res << '\n';;
	}
}