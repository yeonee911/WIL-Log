#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;


// 행렬 곱셈
vector<vector<long long>> matrix_mul(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
	vector acc(8, vector(8, 0LL));
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			for (int k = 0;k < 8;k++) {
				acc[i][j] += a[i][k] * b[k][j];
			}
			acc[i][j] %= 1000000007;
		}
	}
	return acc;
}

vector<vector<long long>> recursive(vector<vector<long long>>& a, int n) {
	if (n == 1) return a;
	vector<vector<long long>> b = recursive(a, n / 2);
	b = matrix_mul(b, b);
	if (n & 1) b = matrix_mul(b, a);
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 정보과학관 0
	// 전산관 1
	// 미래관 2
	// 신양관 3
	// 한경직기념관 4
	// 진리관 5
	// 학생회관 6
	// 형남공학관 7
	vector g(8, vector(8, 0LL));
	g[0][1] = 1; g[1][0] = 1;
	g[0][2] = 1; g[2][0] = 1;
	g[1][2] = 1; g[2][1] = 1;
	g[1][3] = 1; g[3][1] = 1;
	g[2][3] = 1; g[3][2] = 1;
	g[2][4] = 1; g[4][2] = 1;
	g[3][4] = 1; g[4][3] = 1;
	g[3][5] = 1; g[5][3] = 1;
	g[4][5] = 1; g[5][4] = 1;
	g[5][6] = 1; g[6][5] = 1;
	g[4][7] = 1; g[7][4] = 1;
	g[6][7] = 1; g[7][6] = 1;
	

	int d;
	cin >> d;
	auto ans = recursive(g, d);
	cout << ans[0][0];
}