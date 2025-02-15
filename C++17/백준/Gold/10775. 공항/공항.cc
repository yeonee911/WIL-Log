#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, p;
    cin >> g >> p;

    set<int>s;
    for (int i = 1; i <= g;i++) s.insert(i);

    for (int i = 1;i <= p;i++) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.begin()) {  // 더 이상 삭제할 값이 없다
            cout << i - 1;  // 해당 비행기부터 도킹 불가하므로 -1
            return 0;
        }
        else {
            s.erase(--it);
        }
    }
    cout << p;
}