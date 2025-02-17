#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (n != 0 || m != 0) {
        vector<tuple<int, int, int>> edge(m);
        for (int i = 0;i < m;i++) {
            string s;
            int a, b, w;
            cin >> s >> a >> b;
            if (s == "!") {
                cin >> w;
                if (a > b) {
                    swap(a, b);
                    w *= -1;
                }
                edge[i] = { a, b, w };    // 상근이가 무게를 잼
            }
            else edge[i] = { a, b, INF }; // 교수님이 질문을 함
        }

        vector parent(n + 1, -1);
        vector<int> value(n + 1, 0); // 루트와의 차이
        auto find = [&](int x) {
            int ans = 0;
            while (parent[x] >= 0) {
                ans += value[x];
                x = parent[x];
            }
            return make_pair(x, ans);
        };

        auto merge = [&](int a, int b, int w) -> bool {
            int ans = 0;
            // u < v 로 주어진다
            int u = find(a).first;
            int v = find(b).first;
            
            ans += (find(a).second - find(b).second);

            if (u == v) return 0;
            if (-parent[u] < -parent[v]) {
                swap(u, v);
                w *= -1;
                ans *= -1;
            }

            parent[u] += parent[v];
            parent[v] = u;

            ans += w;
            value[v] = ans;
            return 1;
        };

        for (int i = 0;i < m;i++) {
            auto [a, b, w] = edge[i];
            if (w == INF) {   // 교수님 질문
                if (find(a).first != find(b).first) {
                    cout << "UNKNOWN\n";
                    continue;
                }
                else {
                    int ans = 0;
                    ans += find(b).second;
                    ans -= find(a).second;
                    cout << ans << '\n';
                }
            }
            else merge(a, b, w);
        }

        cin >> n >> m;
    }
}