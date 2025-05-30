#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const long long INF = 1LL << 60;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<long long> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0; int r = n - 1;
	long long res = INF;
	long long x = v[l]; long long y = v[r];

	while (l < r) {
		long long sum = v[l] + v[r];
		if (res > abs(sum)) {
			res = abs(sum);
			x = v[l];
			y = v[r];
		}

		if (sum < 0) l++;
		else r--;
	}

	cout << x << ' ' << y;
}