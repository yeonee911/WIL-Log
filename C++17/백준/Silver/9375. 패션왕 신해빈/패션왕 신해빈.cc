#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map<string, vector<string>> m;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m[b].push_back(a);	
		}

		int res = 1;
		for (auto &[a, b] : m) {
			int v = m[a].size() + 1;
			res *= v;
		}	
		cout << res - 1 << '\n';
	}
}
