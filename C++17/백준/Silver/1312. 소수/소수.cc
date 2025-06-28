#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n; cin >> a >> b >> n;
	a %= b;
	a *= 10;
	int r;
	while(n--) {
		r = a / b;
		a %= b;
		a *= 10;
	}
	cout << r;
}