/* Apaar */

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> pos;
		for (i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				cnt++;
				pos.pb(i);
			}
		}
		if (cnt == 2) {
			int l = pos[0], r = pos[1];
			if (s[l] == s[r] && t[l] == t[r]) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
		else {
			cout << "No\n";
		}
	}
}