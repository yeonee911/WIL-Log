#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> v(n, 0);
	for (int i = 0;i <n;i++) cin >> v[i];
	sort(v.begin(), v.end());

	auto sol = [&](int j, int x) {
		int res = 0;
		int t = 0;
		for (int i = 0, p = 0; i < n; i++) {
			if (j == 0) t += b * x;
			if (j > 0) t += a;
			else t += (a - x);
			j--;

			while (p < n && t > v[p]) p++;
			if (p < n) res++, p++;
		}
		return res;
	};
	
	int res = 0;
	for (int x = 0; x < a; x++) {
		for (int j = 0;j < n;j++) {	// assignments before sleep
			res = max(res, sol(j, x));
		}
	}
	cout << res;
}		