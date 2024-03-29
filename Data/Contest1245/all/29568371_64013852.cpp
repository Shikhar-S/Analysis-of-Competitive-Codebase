#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int add(int a, int b){
    a += b;
    if(a >= M) a -= M;
    if(a < 0) a += M;
    return a;
}

int mul(int a, int b){
    return a * (long long)b % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();

    int f[n + 1];
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; ++i){
        f[i] = add(f[i - 1], f[i - 2]);
    }

    int ans = 1;
    int cnt = 1;
    for(int i = 0; i < n; ++i){
        if(s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')){
            ++cnt;
        }
        else{
            ans = mul(ans, f[cnt]);
            cnt = 1;
        }
        if(s[i] == 'm' || s[i] == 'w'){
            return cout << 0, 0;
        }
    } ans = mul(ans, f[cnt]);

    cout << ans;
}
