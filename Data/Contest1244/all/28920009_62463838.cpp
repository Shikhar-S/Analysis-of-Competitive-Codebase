#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;

        if (x + y <= k) {
            cout << x << " " << y << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
/*
*/
