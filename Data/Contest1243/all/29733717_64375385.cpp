#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        vector<int> pos;
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) {
                pos.pb(i);
            }
        }
        if (pos.empty()) {
            cout << "Yes\n";
            continue;
        }
        if (pos.size() != 2) {
            cout << "No\n";
            continue;
        }
        if (s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]]) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
