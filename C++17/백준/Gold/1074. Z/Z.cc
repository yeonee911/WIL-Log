#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;
	int res = 0;

	auto sol = [&](auto &self, int n, int r, int c) -> void {
		if (n == 0) return;

		int sz = 1 << (n - 1);
		if (r < sz && c < sz) {}
		else if (r < sz && c >= sz) { 
			res += sz * sz;
			c -= sz;
		}
		else if (r >= sz && c < sz) {
			res += sz * sz * 2;
			r -= sz;
		}
		else { 
			res += sz * sz* 3;
			r -= sz; c -= sz;
		}

		self(self, n - 1, r, c);
	};

	sol(sol, n, r, c);
	cout << res;
}