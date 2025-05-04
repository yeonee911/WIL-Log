#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long long MAX = 1LL << 60;
const long long MIN = -1 * MAX; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; long long d;
	cin >> n >> d;

	long long mn = MAX;
	long long mx = MIN;
	for (int i = 0; i < n;i++){
		long long x; cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
	}

	long long res;
	if (0 < mn) {
		res = 2 * mx + d;
	}
	else if (mx < 0) {
		res = -2 * mn + d;
	}
	else {
		res = 2 * mx - 2 * mn + 2 * d;
		res = min(res, 4 * mx - 2 * mn + d);
		res = min(res, -4 * mn + 2 * mx + d);
		res = min(res, 4 * (mx - mn) + max(0LL, d - 2 * (mx - mn)));
	}

	cout << res;
}