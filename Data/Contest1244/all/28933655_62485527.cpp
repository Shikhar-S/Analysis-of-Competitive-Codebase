#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, d, k;

        cin >> a >> b >> c >> d >> k;

        int x = (a+c-1)/c;
        int y = (b+d-1)/d;

        if (x+y <= k)
            cout << x << " " << y << "\n";
        else
            cout << -1 << "\n";
    }


    return 0;
}
