#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX];   // 입력받은 수열
int lis[MAX];   // 임시 lis
int record[MAX];    // 인덱스 저장
int result_lis[MAX];    // 최종 lis : 내림차순으로 되어있다

// 이분 탐색
int binary_search(int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < target) 
            left = mid + 1;
        else right = mid;
    }

    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    int j = 0;  // lis 길이 - 1
    lis[0] = arr[0];    // 처음에 하나 넣고 시작
    record[0] = 1;      // arr[0]이 들어간 인덱스는 첫번째 최장 길이

    for (int i = 1;i < n;i++) {
        if (lis[j] < arr[i]) {  // lis 마지막 원소와 비교
            lis[j + 1] = arr[i];
            j++;
            record[i] = j + 1;
        }
        else {
            int idx = binary_search(0, j, arr[i]);
            lis[idx] = arr[i];
            record[i] = idx + 1;
        }
    }

    cout << j + 1 << '\n';  // lis  길이

    int cnt = 0;
    int result_MAX = j + 1;

    for (int i = n - 1;i >= 0;i--) {    // record 역순으로 조회
        if (record[i] == result_MAX) {
            result_lis[cnt++] = arr[i];
            result_MAX--;
        }
    }

    for (int i = cnt - 1;i >= 0;i--) {  // 역순으로 출력
        cout << result_lis[i] << ' ';   // 오름차순
    }

}