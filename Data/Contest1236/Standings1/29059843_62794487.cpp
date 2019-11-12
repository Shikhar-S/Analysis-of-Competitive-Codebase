/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author indy256
 */

#include <bits/stdc++.h>

using namespace std;

void solve(istream &in, ostream &out) {
    int n;
    in >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0, cnt = 0; i < n; ++i) {
        if (i % 2 == 0)
            for (int j = 0; j < n; ++j) {
                a[i][j] = ++cnt;
            }
        else
            for (int j = n - 1; j >= 0; --j) {
                a[i][j] = ++cnt;
            }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << a[j][i] << " ";
        }
        out << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solve(in, out);
}