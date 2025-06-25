#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(101);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back({0, y});
	}

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back({0, y});
	}

	for (int i = 1; i <= 100; i++) {
		if (!g[i].empty()) continue;
		for (int j = 1; j <= 6; j++) {
			if (i + j > 100) continue;
			int u = i + j;
			int v = (!g[u].empty() ? g[u][0].second : u);
			g[i].push_back({1, v});		
		}
	}

	auto dijkstra = [&](int s, int e) {
		priority_queue<pair<int, int>> pq;
		vector<int> dist(101, INF);

		dist[s] = 0;
		pq.push({0, s});

		while(!pq.empty()) {
			int cur_dist = -pq.top().first;
			int cur_node = pq.top().second;
			pq.pop();

			if (dist[cur_node] != cur_dist) continue;

			for (auto x : g[cur_node]) {
				int nxt_dist = x.first + cur_dist;
				int nxt_node = x.second;

				if (nxt_dist < dist[nxt_node]) {
					dist[nxt_node] = nxt_dist;
					pq.push({-nxt_dist, nxt_node});
				}
			}
		}

		return dist[e];
	};

	cout << dijkstra(1, 100);
}