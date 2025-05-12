#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	auto bfs = [&](int s) {
		int res = 0;
		queue<pair<int, int>> q;
		vector<bool> seen(n + 1, false);
		q.push({s, 0});
		seen[s] = true;
		while(!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (auto x : g[cur.first]) {
				if (seen[x]) continue;
				q.push({x, cur.second + 1});
				seen[x] = true;
				res += (cur.second);
			}
		}
		return res;
	};

	int bacon = 1 << 30;
	int res = 0;
	for (int i = n; i > 0; i--) {
		int t = bfs(i);
		// cout << i << " : " << t << endl;
		if (t <= bacon) {
			bacon = t;
			res = i;
		}
	}

	cout << res;
}