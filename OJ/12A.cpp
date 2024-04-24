#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, w[N], f[N][2];
vector<int> e[N];

void dfs(int u, int fa) {
    f[u][1] = w[u];
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) continue;
        dfs(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(f[1][0], f[1][1]) << endl;
    return 0;
}

