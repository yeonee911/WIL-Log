#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m, ' '));
	vector<vector<bool>> seen(n, vector<bool>(m, false));

	int sx = 0; int sy = 0;	// start
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				sx = i;
				sy = j;
			}
		}
	}

	int cnt = 0; 
	queue<pair<int, int>> q;
	q.push({sx, sy});
	seen[sx][sy] = true;
	while(!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		if (v[r][c] == 'P') cnt++;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (seen[nr][nc] || v[nr][nc] == 'X') continue;

			seen[nr][nc] = true;
			q.push({nr, nc});
		}
	}

	if (!cnt) cout << "TT";
	else cout << cnt;
}