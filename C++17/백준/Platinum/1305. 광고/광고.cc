#include <iostream>
#include <vector>

using namespace std;

auto get_fail = [](const string &s) {
	const int n = s.size();
	vector f(n, 0);
	for (int i = 1, j = 0; i < n; i++) {
		while(j && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
};

auto kmp = [](const string &s, const string &t) {
	vector ret(0, 0), f = get_fail(t);
	for (int i = 0, j = 0; i < s.size(); i++) {
		while(j && s[i] != t[j]) j = f[j - 1];
		if (s[i] == t[j] && ++j == t.size()) {
			ret.push_back(i - t.size() + 1);
			j = f[j - 1];
		}
	}
	return ret;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l; cin >> l;
	string s; cin >> s;
	string t = s + s;
	auto buc = kmp(t, s);
	auto f = get_fail(t);
	cout << buc[1] - f[buc[1] - 1];
}