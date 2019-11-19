#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,c[4][N],deg[N];
vector<int> e[N];
long long val[4][4];
int out[N];
long long dfs(int pos,int fa,int l1,int l2)
{
    for (int i = 1;i <= 3;i++)
        if (i != l1 && i != l2)
        {
            if (e[pos].size() == 1) return c[i][pos];
            int nxt = e[pos][0];
            if (nxt == fa) nxt = e[pos][1];
            return c[i][pos] + dfs(nxt,pos,i,l1);
        }
    throw;
}
void print(int pos,int fa,int l1,int l2)
{
    for (int i = 1;i <= 3;i++)
        if (i != l1 && i != l2)
        {
            out[pos] = i;
            if (e[pos].size() == 1) return;
            int nxt = e[pos][0];
            if (nxt == fa) nxt = e[pos][1];
            return print(nxt,pos,i,l1);
        }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= n;j++) cin >> c[i][j];
    int t1,t2;
    for (int i = 1;i < n;i++)
    {
        cin >> t1 >> t2;++deg[t1];++deg[t2];
        e[t1].push_back(t2);e[t2].push_back(t1);
    }
    int pos = 0,cnt = 0;
    for (int i = 1;i <= n;i++)
        if (deg[i] == 1) ++cnt,pos = i;
        else if (deg[i] > 2) {cout << -1 << endl;return 0;}
    if (cnt != 2) {cout << -1 << endl;return 0;}
    int nxt = e[pos][0],nn = nxt;
    if (e[nxt][0] == pos) nxt = e[nxt][1];else nxt = e[nxt][0];
    // cout << pos << ' ' << nxt << endl;
    long long ans = LLONG_MAX;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
            if (i != j)
                ans = min(ans,
                val[i][j] = dfs(nxt,nn,i,j) + c[j][pos] + c[i][nn]);
    for (int i = 1;i <= 3 && !out[1];i++)
        for (int j = 1;j <= 3;j++)
            if (i != j && ans == val[i][j])
            {
                cout << ans << endl;
                // cout << j << ' ' << i << ' ';
                out[pos] = j;out[nn] = i;
                print(nxt,nn,i,j);
                break;
            }
    for (int i = 1;i <= n;i++) cout << out[i] << ' ';
    return 0;
}