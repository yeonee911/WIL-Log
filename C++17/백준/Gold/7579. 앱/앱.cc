#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m; cin >> n >> m;
	vector<int> memory(n + 1, 0);
	vector<int> cost(n + 1, 0);
	vector<int> dp(10001, -1);

	for (int i = 1; i <= n; i++) cin >> memory[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];
	dp[0] = 0;

	for (int i = 1; i <= n;i++) {
		int x = memory[i];
		int y = cost[i];
		for (int j = 10000; j >= y; j--) {
			if (dp[j - y] == -1) continue;
			dp[j] = max(dp[j - y] + x, dp[j]);
		}
	}

	for (int i = 0; i < 10001; i++) {
		if (dp[i] >= m) {cout << i; return 0;}
	}
}