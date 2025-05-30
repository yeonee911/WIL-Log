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

	int idx = -1;	// negative -> positive
	int ne = 0; int po = 0;	// negative, positive
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) ne++;
		else po++;

		if (i != 0 && (v[i - 1] * v[i] < 0)) idx = i;
	}

	long long res = INF;
	long long x, y;
	if (idx == -1) {
		if (ne) cout << v[n - 2] << ' ' << v[n - 1];
		else cout << v[0] << ' ' << v[1];
		return 0;
	}

	res = abs(v[idx - 1] + v[idx]);
	x = v[idx - 1];
	y = v[idx];

	if (ne >= 2 && res > abs(v[idx - 1] + v[idx - 2])) {
		 res = abs(v[idx - 1] + v[idx - 2]);
		 x = v[idx - 2];
		 y = v[idx - 1];
	}

	if (po >= 2 && res > v[idx] + v[idx + 1]) {
		res = v[idx] + v[idx + 1];
		x = v[idx];
		y = v[idx + 1];
	}

	int l = 0; 
	int r = n - 1;
	while (v[l] < 0 && v[r] > 0) {
		if (res > abs(v[l] + v[r])) {
			res = abs(v[l] + v[r]);
			x = v[l];
			y = v[r];
		}
		if (-v[l] > v[r]) l++;
		else r--;
	}

	cout << x << ' ' << y;
}