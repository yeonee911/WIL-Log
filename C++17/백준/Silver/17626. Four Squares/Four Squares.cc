#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int sz = 1;
	vector<int> dp(n + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int sz = 1;
		while(sz * sz <= i) {
			dp[sz * sz] = 1;
			dp[i] = min(dp[i], dp[i - sz * sz] + dp[sz * sz]);
			sz++;
		}
	}

	cout << dp[n];
}