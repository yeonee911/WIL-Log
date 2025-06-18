#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		bool flag = false;
		for (int j = 1; j * j <= n; j++) {
			if (j * j == n) {
				flag = 1;
				break;
			}
		}

		cout  << flag << '\n';
	}
}