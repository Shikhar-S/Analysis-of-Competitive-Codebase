#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<map>
#include<bitset>
#include<unordered_map>
#include<cstring>
#include<cctype>
using namespace std;
#define  ll long long
#define  ull unsigned long long
#define  ul unsigned long
#define all(v) v.begin(),v.end()
#define sz(n) (int)n.size()
#define pb(s) push_back(s);
#define format(n) fixed<<setprecision(n)
#define finl "\n"
#define Mohammed_Atef_Hassan fast();
#define mod 1000000007
#define INF LLONG_MAX
#define PI acos(-1)
#define clr(dp,n) memset(dp,n,sizeof dp)
#define ex(n) return cout<<n<<finl,0;
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll fix_mod(ll x, ll y)
{
	return (y + x % y) % y;
}
void fast() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

#ifdef ONLINE_JUDGE
	//freopen("crosses.in", "r", stdin);

	//freopen("crosses.out", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
int main()
{
	Mohammed_Atef_Hassan
		int k,n;
	cin >> k;
	while (k--)
	{
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (v[j] >= i)cnt++;
			}
			if (cnt >= i)ans = i;
		}
		cout << ans << finl;
	}

}