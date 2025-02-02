#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long>tree;
vector<long long>arr;
long long init(long long n, long long s, long long e);
long long update(long long i, long long x, long long n, long long s, long long e);
long long query(long long qs, long long qe, long long n, long long s, long long e);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	arr.resize(n, 0);

	int tree_size = 4 * n + 1;
	tree.resize(tree_size, 0);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	init(1, 0, n-1);	// 트리 생성

	long long a, b, c;
	//	a==1 : b번째 수를 c로 바꾸기
	//	a==2 : b~c 까지의 합 구하기

	for (int i = 0;i < m + k;i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c, 1, 0, n - 1);
		}
		if (a == 2) {
			cout << query(b-1, c-1, 1, 0, n - 1) << '\n';
		}
	}

}

// 트리를 초기화하는 함수
long long init(long long n, long long s, long long e){
	if (s == e)
		tree[n] = arr[s];
	else {
		int mid = (s + e) / 2;
		tree[n] = init(n * 2, s, mid) + init(n * 2 + 1, mid+1, e);
	}

	return tree[n];
}

// arr배열의 i번째 값을 x로 변경하는 함수
long long update(long long i, long long x, long long n, long long s, long long e) {
	if (e < i || i < s)	// 나랑 무관한 경우 <=> 구간이 안 겹침
		return tree[n];	// 원래 값 반환
	if (i <= s && e <= i)
		return tree[n]=x;	// 값 변경
	
	long long mid = (s + e) / 2;
	long long left = update(i, x, 2 * n, s, mid);
	long long right = update(i, x, 2 * n + 1, mid + 1, e);

	return tree[n] = left+right;
}

long long query(long long qs, long long qe, long long n, long long s, long long e) {
	if (e < qs || qe < s)	// 나랑 무관한 경우 <=> 구간이 안 겹침
		return 0;
	if (qs <= s && e <= qe)
		return tree[n];
	long long mid = (s + e) / 2;
	long long left = query(qs, qe, 2 * n, s, mid);
	long long right = query(qs, qe, 2 * n + 1, mid + 1, e);

	return left + right;
}