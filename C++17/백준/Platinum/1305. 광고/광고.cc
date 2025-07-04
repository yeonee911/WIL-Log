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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l; cin >> l;
	string s; cin >> s;
	auto f = get_fail(s);
	cout << l - f[l - 1];
}