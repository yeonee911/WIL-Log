#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str; cin >> str;
	if (str[0] != '-') str = "+" + str;
	stack<pair<int, int>> v;
	
	string num;
	bool f;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-') f = false;
		else if (str[i] == '+')	f = true;
		else {
			num += str[i];
			if (i + 1 == str.length() || str[i + 1] == '-' || str[i + 1] == '+') {
				v.push({f, stoi(num)});
				num = "";
			}
		}
	}

	int t = 0;
	f = v.top().first;
	stack<pair<int, int>> stk;
	while(!v.empty()) {
		if (v.top().first == f) {
			t += v.top().second;
		}
		else {
			stk.push({f, t});
			t = v.top().second;
			f = v.top().first;
		}
		v.pop();
	}
	stk.push({f, t});

	int res = stk.top().second;
	stk.pop();

	while(!stk.empty()){
		res += (-1) * stk.top().second; 
		stk.pop();
	}

	cout << res;
}