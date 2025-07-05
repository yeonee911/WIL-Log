#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto get_fail = [](const string &s){
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

	int n; cin >> n;
	string s(n, '\0');
	for (int i = 0; i < n; i++) cin >> s[i];
	string t(n, '\0');
	for (int i = 0; i < n; i++) cin >> t[i];
	t += t;
	t.pop_back();
	auto buc = kmp(t, s);

	auto gcd = [](const auto& self, int x, int y) -> int {
		if (y) return self(self, y, x % y);
		return x;
	};

	int x = buc.size();
	int y = n;
	int r = gcd(gcd, x, y);
	cout << x / r << "/" << y / r;
}