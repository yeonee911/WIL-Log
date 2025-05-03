#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m; cin >> m;
	vector<bool>s(21, false);

	auto add = [&](vector<bool> &s){
		int x; cin >> x;
		s[x] = true;
	};	

	auto remove = [&](vector<bool> &s) {
		int x; cin >> x;
		s[x] = false;
	};

	auto check = [&](vector<bool> &s) {
		int x; cin >> x;
		if (s[x]) cout << 1 << '\n';
		else cout << 0 << '\n';
	};

	auto toggle = [&](vector<bool> &s) {
		int x; cin >> x;
		if (s[x]) s[x] = false;
		else s[x] = true;
	};

	auto all = [&](vector<bool> &s) {
		for (int i = 1;i <= 20;i++) s[i] = true;
	};

	auto empty = [&](vector<bool> &s) {
		for (int i = 1;i <= 20;i++) s[i] = false;
	};

	for (int i = 0; i < m;i++) {
		string q; cin >> q;
		if (q == "add") add(s);
		else if (q == "remove") remove(s);
		else if (q == "check") check(s);
		else if (q == "toggle") toggle(s);
		else if (q == "all") all(s);
		else empty(s);
	}
}