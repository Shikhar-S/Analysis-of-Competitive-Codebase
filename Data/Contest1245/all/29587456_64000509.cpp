#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

void solve() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    string s;
    cin >> s;

    int ans = 0, stn = 0;
    vector <char> out(n, '#');
    for(auto i : s) {

        if (i == 'R') {
            if (b) {
                b--;
                ans++;
                out[stn] = 'P';
            }
        }

        if (i == 'P') {
            if (c) {
                c--;
                ans++;
                out[stn] = 'S';
            }
        }

        if (i == 'S') {
            if (a) {
                a--;
                ans++;
                out[stn] = 'R';
            }
        }

        stn++;
    }

    if (ans >= (n + 1) / 2) {
        cout << "yes\n";
        for(auto i : out) {
            if (i == '#') {
                if (a) {
                    i = 'R';
                    a--;
                }
                else {
                    if (b) {
                        i = 'P';
                        b--;
                    }
                    else {
                        i = 'S';
                    }
                }
            }

            cout << i;
        }
        cout << "\n";
    }
    else {
        cout << "no\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test;
    cin >> test;

    while(test--) {
        solve();
    }

    return 0;
}
/*
*/
