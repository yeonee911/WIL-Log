#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    int cnt = 0;
    int ans = 0;
    for (int i = 1; i < m - 1; ) {
        if (str[i-1] == 'I' && str[i] == 'O' && str[i+1] == 'I') {
            cnt++;
            if (cnt == n) {
                ans++;
                cnt--; 
            }
            i += 2; 
        } else {
            cnt = 0;
            i++;
        }
    }

    cout << ans << '\n';
}