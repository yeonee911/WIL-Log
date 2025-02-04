#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector v(n, 0);
	for (int i = 0;i < n;i++) cin >> v[i];

	auto compress = [](int n, auto v) {
		vector buc(n, pair(0, 0));
		for (int i = 0;i < n;i++) {
			buc[i].first = v[i];
			buc[i].second = i;
		}
		sort(buc.begin(), buc.end());

		vector ans(n, 0);
		int cnt = 0;
		for (int l = 0, r = 0; l < n; l = r) {
			while (r < n && buc[l].first == buc[r].first) r++;
			
			for (int i = l;i < r;i++) {
				ans[buc[i].second] = cnt;
			}
			cnt++;
		}
		return ans;
	};

	vector ans = compress(n, v);
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}