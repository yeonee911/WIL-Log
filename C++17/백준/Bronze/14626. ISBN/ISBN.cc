#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str; cin >> str;
	int idx = 0;
	vector<int>v(13, 0);
	for (int i = 0; i < 13; i++) {
		if (str[i] != '*') v[i] = str[i] -'0';
		else {idx = i;}
	}

	int sum = 0;
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 0) sum += v[i];
		else sum += v[i] * 3;
	}

	if (idx == 12) {
		cout << (10 - sum % 10) % 10;
		return 0;
	}

	int target = (10 - v[12]) % 10;
	for (int i = 0; i < 10; i++) {
		int x = i;
		if (idx % 2 == 1) x *= 3;
		if ((sum + x) % 10 == target) {
			cout << i;
			return 0;
		}
	}
}