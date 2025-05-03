#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	if (n == 0) {cout << 0; return 0;}

	vector<double> p(n + 1, 0);
	vector<int> l(n + 1, 0);
	vector<double> v(n + 1, 0);

	auto cal = [&](int y, int m, int d, int h, int min, int sec) {
		double res = 0;
		// start 2019
		if (y == 2020) y = 365;
		else if (y == 2021) y = 365 + 366;			
		else if (y == 2022) y = 365 * 2 + 366;
		else y = 0;
		res += y * 24 * 60 * 60;

		// start 1
		if (m == 1) m = 0;
		else if (m == 2) m = 31;
		else if (m == 3) m = 31 + 28;
		else if (m == 4) m = 31 * 2 + 28;
		else if (m == 5) m = 31 * 2 + 28 + 30;
		else if (m == 6) m = 31 * 3 + 28 + 30;
		else if (m == 7) m = 31 * 3 + 30 * 2 + 28;
		else if (m == 8) m = 31 * 4 + 30 * 2 + 28;
		else if (m == 9) m = 31 * 5 + 30 * 2 + 28;
		else if (m == 10) m = 31 * 5 + 30 * 3 + 28;
		else if (m == 11) m = 31 * 6 + 30 * 3 + 28;
		else m = 31 * 6 + 30 * 4 + 28;

		if (y == 365 && m > 31) m += 1;

		m *= 24 * 60 * 60;

		d *= 24 * 60 * 60;
		h *= 60 * 60;
		min *= 60;

		return res += (m + d + h + min + sec);
	};

	for (int i = 1;i <= n;i++) {
		string t; cin >> t;
		string time; cin >> time;
		cin >> l[i];
		int y = stoi(t.substr(0, 4));
		int m = stoi(t.substr(5, 2));
		int d = stoi(t.substr(8, 2));
		int h = stoi(time.substr(0, 2));
		int min = stoi(time.substr(3, 2));
		int sec = stoi(time.substr(6, 2));

		v[i] = cal(y, m, d, h, min, sec);
	}

	for (int i = 1;i <= n;i++) {
		p[i] = (v[n] - v[i])/(double)(365 * 24 * 60 * 60);
		p[i] = max(pow(0.5, p[i]), pow(0.9, n - i));
	}

	double x = 0.0;
	double sum = 0.0;
	for (int i = 1; i <= n;i++) {
		x += p[i] * l[i];
		sum += p[i];
	}

	x /= sum;
	cout << (int)(x + 0.5);
}