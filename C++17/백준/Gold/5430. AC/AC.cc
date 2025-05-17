#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--) {
		string p; cin >> p;
		int n; cin >> n;
		deque<int> dq;
		string v; cin >> v;
		string num = "";
		if (n == 0) v = {};
		else {
			for (int i = 1; i < v.length(); i++) {
				if (v[i] == ']' || v[i] == ',') {
					dq.push_back(stoi(num));
					num = "";
					continue;
				}
				num += v[i];
			}
		}

		bool flag = true;
		bool cnt = false;
		for (auto s : p) {
			if (s == 'R') {
				if (cnt) cnt = false;
				else cnt = true;
			}
			if (s == 'D') {
				if (dq.empty()) {
					flag = false;
					break;
				}
				if (cnt) dq.pop_back();
				else dq.pop_front();
			}
		}

		if (cnt) reverse(dq.begin(), dq.end());

		if (!flag)	{cout << "error\n"; continue;}
		cout << '[';
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
			if (i == dq.size() - 1) continue;
			cout << ',';
		}
		cout << "]\n";
	}
}