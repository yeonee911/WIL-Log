#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int k; cin >> k;

	queue<pair<int, int>> q;
	vector<bool> seen(100000+1, false);
	int f = n;
	int cnt = 0;
	while(f != k){
		if (!seen[f - 1] && f - 1 >= 0) {q.push({f - 1, cnt + 1}); seen[f - 1] = true;}
		if (!seen[f + 1] && f + 1 <= 100000) {q.push({f + 1, cnt + 1}); seen[f + 1] = true;}
		if (!seen[f * 2] && f * 2 <= 100000) {q.push({f * 2, cnt + 1}); seen[f * 2] = true;}

		f = q.front().first;
		cnt =  q.front().second;
		q.pop();
	}

	cout << cnt;
}