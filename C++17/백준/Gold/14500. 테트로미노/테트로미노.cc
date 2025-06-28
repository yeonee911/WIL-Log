#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<int>> seen(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int res = 0;
	auto dfs = [&](auto &self, int r, int c, int dep, int sum) -> void {
		if (dep == 4) {
			res = max(res, sum);
			return;
		}

		seen[r][c] = 1;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (seen[nr][nc]) continue;
			self(self, nr, nc, dep + 1, sum + v[nr][nc]);
		}

		seen[r][c] = 0;
	};

	auto check = [&](int r, int c) {
		if (r >= 1 && r < n - 1 && c >= 1) {
			res = max(res, v[r][c] + v[r-1][c] + v[r+1][c] + v[r][c-1]);
		}
		if (r >= 1 && r < n - 1 && c < m - 1) {
			res = max(res, v[r][c] + v[r-1][c] + v[r+1][c] + v[r][c+1]);
		}
		if (r >= 1 && c >= 1 && c < m - 1) {
			res = max(res, v[r][c] + v[r-1][c] + v[r][c-1] + v[r][c+1]);
		}
		if (r < n - 1 && c >= 1 && c < m - 1) {
			res = max(res, v[r][c] + v[r+1][c] + v[r][c-1] + v[r][c+1]);
		}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			seen[i][j] = 1;
			dfs(dfs, i, j, 1, v[i][j]);
			seen[i][j] = 0;
			check(i, j);
		}
	}
	cout << res;
}