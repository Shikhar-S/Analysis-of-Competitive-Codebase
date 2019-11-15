#include <bits/stdc++.h>
using namespace std;

const int MAX = 210000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    COMinit();
    string s; cin >> s;
    int n = s.size();
    long long res = 1;
    int cnt = 1;
    for(int i=1; i<n; ++i) {
        if(s[i] == s[i - 1]) {
            ++cnt;
        } else {
            if(s[i - 1] == 'u' || s[i - 1] == 'n') {
                long long tmp = 1;
                for(int k=1; cnt - k >= k; ++k) {
                    tmp = (tmp + COM(cnt - k, k)) % MOD;
                }
                res = (res * tmp) % MOD;
            } else if((s[i - 1] == 'w' || s[i - 1] == 'm') && cnt == 1) {
                res = 0;
            }
            cnt = 1;
        }

        if(i + 1 == n) {
            if(s[i - 1] == 'u' || s[i - 1] == 'n') {
                long long tmp = 1;
                for(int k=1; cnt - k >= k; ++k) {
                    tmp = (tmp + COM(cnt - k, k)) % MOD;
                }
                res = (res * tmp) % MOD;
            } else if((s[i - 1] == 'w' || s[i - 1] == 'm') && cnt == 1) {
                res = 0;
            }
        }
    }
    cout << res << '\n';
}