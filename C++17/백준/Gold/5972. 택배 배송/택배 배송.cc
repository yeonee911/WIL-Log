#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
const int INF = 1 << 30;
int n, m;

void dijkstra(int s, int e, vector<vector<pair<int, int>>>& g);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);

	int a, b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		g[a].push_back({ c, b });	// cost, node
		g[b].push_back({ c, a });
	}


	dijkstra(1, n, g);
}

void dijkstra(int s, int e, vector<vector<pair<int, int>>> &g) {
	priority_queue<pair<int, int>> pq;
	vector<int>dist(n + 1, INF);
	
	dist[s] = 0;
	pq.push({ 0, s });	// cost, node

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] != cur_dist) continue;

		for (auto x : g[cur_node]) {
			int nxt_dist = x.first + cur_dist;
			int nxt_node = x.second;

			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({ -nxt_dist, nxt_node });
			}
		}
	}

	cout << dist[e] << '\n';
}