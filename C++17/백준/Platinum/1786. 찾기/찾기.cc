#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	auto get_fail = [](const string& s) {
		const int n = s.size();
		vector f(n, 0);
		for (int i = 1, j = 0; i < n; i++) {
			while (j && s[i] != s[j]) j = f[j - 1];
			if (s[i] == s[j]) f[i] = ++j;
		}
		return f;
	};

	auto kmp = [&](const string& s, const string& t) {
		vector ret(0, 0), f = get_fail(t);
		for (int i = 0, j = 0; i < s.size(); i++) {
			while (j && s[i] != t[j]) j = f[j - 1];
			if (s[i] == t[j] && ++j == t.size()) {
				ret.push_back(i - t.size() + 1);
				j = f[j - 1];
			}	
		}
		return ret;
	};

	string t; getline(cin, t);
	string p; getline(cin, p);

	vector<int> res = kmp(t, p);
	cout << res.size() << '\n';
	for (auto x : res) {
		cout << x + 1 << ' ';
	}
}
