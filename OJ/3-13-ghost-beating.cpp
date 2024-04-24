#include <cstdio>
#include <vector>

const int maxn = 1005;

int n, m, t;
int mch[maxn], vistime[maxn];

std::vector<int> e[maxn];

bool dfs(const int u, const int tag);

int main() {
  scanf("%d %d %d", &n, &m, &t);
  for (int u, v; t; --t) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (dfs(i, i)) {
    ++ans;
  }
  printf("%d\n", ans);
}

bool dfs(const int u, const int tag) {
  if (vistime[u] == tag) return false;
  vistime[u] = tag;
  for (auto v : e[u]) if ((mch[v] == 0) || dfs(mch[v], tag)) {
    mch[v] = u;
    return true;
  }
  return false;
}
