# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, c[4][N], b[N], cc[N];
long long ret;
vector <int> g[N];
int pos[4] = {1, 2, 3};

void dfs(int v, int cn = 0, int pr = -1) {
    ret += c[ pos[cn] ][v];
    for (int to : g[v]) {
        if (to == pr)
            continue;
        dfs(to, (cn + 1) % 3, v);
    }
}

void f(int v, int cn = 0, int pr = -1) {
    cc[v] = pos[cn];
    for (int to : g[v]) {
        if (to == pr)
            continue;
        f(to, (cn + 1) % 3, v);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int rt;

    for (int i = 1; i <= n; i++) {
        if(g[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
        if (g[i].size() == 1)
            rt = i;
    }

    long long ans = 1e18;

    do {
        ret = 0;
        dfs(rt);
        ans = min(ans, ret);
    } while (next_permutation(pos, pos + 3));

    pos[0] = 1, pos[1] = 2, pos[2] = 3;
    do {
        ret = 0;
        dfs(rt);
        if (ret == ans) {
            f(rt);
            cout << ans << endl;
            for (int i = 1; i <= n; i++)
                cout << cc[i] << " ";
            return 0;
        }
    } while (next_permutation(pos, pos + 3));
}
