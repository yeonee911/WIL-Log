#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while(1) {
		cin >> n;
		if (n == 0) break;

		vector<int> a(n, 0); 
		vector<int> b(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		vector<int> sa(n, 0);
		vector<int> sb(n, 0);
		sa[0] = a[0];
		sb[0] = b[0];

		for (int i = 1; i < n; i++) {
			sa[i] = sa[i - 1] + a[i];
			sb[i] = sb[i - 1] + b[i];
		}

		vector<int> w(n, 0);
		for (int i = 0; i < n; i++) {
			if (sa[i] < sb[i]) w[i] = 1;
			else if (sa[i] > sb[i]) w[i] = -1;
			else w[i] = 0;
		}

		stack<int> stk;
		for (int i = 0; i < n; i++) {
			if (w[i] == 0) continue;
			if (stk.empty() || (!stk.empty() && stk.top() != w[i])) stk.push(w[i]);
		}

		if (stk.empty()) cout << 0 << '\n';
		else cout << stk.size() - 1 << '\n';
	}
}