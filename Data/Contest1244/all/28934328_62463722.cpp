#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x, y;
        if (a % c == 0) x = a / c;
        else x = a / c + 1;
        if (b % d == 0) y = b / d;
        else y = b / d + 1;
        if (x + y > k) cout << -1 << endl;
        else cout << x << ' ' << y << endl;
    }
    return 0;
}
