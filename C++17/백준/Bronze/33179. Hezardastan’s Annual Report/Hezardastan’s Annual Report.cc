#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	int res = 0;
	for (int i = 0; i < n; i++) res += ((v[i] + 1) / 2);
	cout << res;
}