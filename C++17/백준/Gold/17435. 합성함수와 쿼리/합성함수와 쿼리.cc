#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp = 1;
    int k = 0;
    while (tmp < 500000) {
        tmp *= 2;
        k++;
    }

    int m;
    cin >> m;
    vector<vector<int>> table(k + 1, vector<int>(m + 1, 0));
    for (int i = 1;i <= m;i++) cin >> table[0][i];
    
    int q;
    cin >> q;

    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= m;j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
    

    auto query = [&](int n, int x) {
        for (int i =  k; i >= 0; i--) {
            if (n & (1 << i)) {
                x = table[i][x];
            }
        }
        return x;
    };
    
    while (q--) {
        int n, x;
        cin >> n >> x;
        cout << query(n, x) << '\n';
    }
}