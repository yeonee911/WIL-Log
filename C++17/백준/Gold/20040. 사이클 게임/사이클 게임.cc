#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> p(n, -1);
    
    auto find = [&](int x) {
        int root = x;
        while(p[root] >= 0) root = p[root];
        while(x != root) {
            int nxt = p[x];
            p[x] = root;
            x = nxt;
        }
        return root;
    };
    
    auto merge = [&](int u, int v) -> bool {
        u = find(u);
        v = find(v);
        
        if (u == v) return 0;
        if (-p[u] < -p[v]) swap(u, v);
        
        // u의 rank가 더 크다
        p[u] += p[v];
        p[v] = u;
        return 1;
    };
    
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        
        if (!merge(u, v)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}