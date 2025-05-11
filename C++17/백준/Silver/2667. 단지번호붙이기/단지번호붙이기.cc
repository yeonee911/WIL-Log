#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<int> res;
	vector<vector<int>> g(n * n);
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < n; j++) {
			int x = str[j] - '0';
			v[i][j] = x;
		}
	}

	for (int r = 0; r < n;r++) {
		for (int c = 0; c < n; c++) {
			if (v[r][c] == 0) continue;
			int idx = r * n + c;
			for (int i = 0; i < 4; i++) {
				int new_r = r + dr[i];
				int new_c = c + dc[i];
				if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n) continue;
				int new_idx = new_r * n + new_c;
				if (v[new_r][new_c] == 1) g[idx].push_back(new_idx);
			}
		}
	}
	
	vector<bool>seen(n * n, false);
	auto bfs = [&](int num) {	// start num
		queue<int>q;
		q.push(num);
		seen[num] = true;
		int res = 1;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto nxt : g[cur]) {
				if (seen[nxt]) continue;
				q.push(nxt);
				res++;
				seen[nxt] = true;
			}
		}
		return res;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int idx = i * n + j;
			if (v[i][j] == 1 && !seen[idx]) {
				res.push_back(bfs(idx));
			}
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto x : res) {
		cout << x << '\n';
	}
}