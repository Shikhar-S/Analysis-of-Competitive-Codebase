#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int op1 = min(b, c / 2);
        b -= op1;
        int op2 = min(a, b / 2);
        cout << 3*(op1 + op2) << endl;
    }    
}