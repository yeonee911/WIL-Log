#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAX = pow(10, 6) + 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> left(MAX);
	vector<vector<int>> right(MAX);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		left[l].push_back(r);
		right[r].push_back(l);
	}

	for (int i = 0; i < MAX;i++) {
		sort(left[i].begin(), left[i].end());
		sort(right[i].begin(), right[i].end());
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		if (left[l].empty() || right[r].empty()) {
			cout << -1 << '\n';
			continue;
		}

		if (left[l][left[l].size() - 1] < r || right[r][0] > l) {
			cout << -1 << '\n';
			continue;
		}

		if (binary_search(left[l].begin(), left[l].end(), r)) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}