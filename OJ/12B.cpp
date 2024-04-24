#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, m, cnt;
int h[N], e[N], ne[N];
int dfn[N], low[N], id[N], stk[N], top;
bool st[N];
int ans[N];

void add(int a, int b) {
    e[cnt] = b, ne[cnt] = h[a], h[a] = cnt++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u, st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (st[j]) {
            low[u] = min(low[u], dfn[j]);
        }
    }
    if (dfn[u] == low[u]) {
        int y;
        do {
            y = stk[top--];
            st[y] = false;
            id[y] = u;
        } while (y != u);
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = h[i]; ~j; j = ne[j]) {
            int k = e[j];
            if (id[i] != id[k]) ans[id[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[id[i]] << endl;
    return 0;
}

