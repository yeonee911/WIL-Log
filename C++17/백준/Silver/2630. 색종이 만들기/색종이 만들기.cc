#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> v[i][j];
		}
	}

	int w = 0;	// white
	int b = 0;	// blue
	auto sol = [&](auto &self, int r, int c, int k, int &w, int &b) -> void {
		int color = v[r][c];
		int flag = false;
		for (int i = r; i < r + k; i++) {
			for (int j = c; j < c + k; j++) {
				if (color != v[i][j]) {flag = true; break;}
			}
		}
		if (flag) {
			self(self, r, c, k/2, w, b);
			self(self, r + k/2, c, k/2, w, b);
			self(self, r, c + k/2, k/2, w, b);
			self(self, r + k/2, c + k/2, k/2, w, b);
		}
		else {
			if (color == 0) w++;
			else b++;
			return;
		}
	};

	sol(sol, 0, 0, n, w, b);
	cout << w << '\n';
	cout << b << '\n';
}