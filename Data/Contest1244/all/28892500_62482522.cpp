#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> c(3, vector<int>(n)), g(n);
  for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < n; ++i) {
      cin >> c[j][i];
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  int leaf = -1;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 2) {
      cout << -1;
      return 0;
    } else if (g[i].size() == 1) {
      leaf = i;
    }
  }
  vector<int> topsort, pos(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    for (int to : g[v]) {
      if (to != p) {
        dfs(to, v);
      }
    }
    topsort.push_back(v);
  };
  dfs(leaf, -1);
  for (int i = 0; i < n; ++i) {
    pos[topsort[i]] = i;
  }
  vector<int> kek = {0, 1, 2};
  pair<long long, vector<int>> ans(1e18, {});
  do {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int v = topsort[i];
      res += c[kek[i % 3]][v];
    }
    ans = min(ans, pair<long long, vector<int>>(res, kek));
  } while (next_permutation(kek.begin(), kek.end()));
  cout << ans.first << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans.second[pos[i] % 3] + 1 << ' ';
  }


  return 0;
}