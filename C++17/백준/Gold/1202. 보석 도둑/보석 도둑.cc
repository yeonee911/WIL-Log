#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	priority_queue<pair<int, int>> pq;
	vector<int> b(k, 0);
	vector<pair<int, int>> jw;

	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;
		jw.push_back({m, v});
	}
	sort(jw.begin(), jw.end());

	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		b[i] = c;
	}
	sort(b.begin(), b.end());

	int p = 0;
	long long res = 0;
	for (int i = 0; i < k; i++) {
		for (;p < n; p++) {
			if (jw[p].first <= b[i]) {
				pq.push({jw[p].second, jw[p].first});
			}
			else break;
		}

		if (!pq.empty()) {
			res += pq.top().first;
			pq.pop();
		}
	}

	cout << res << '\n';
} 