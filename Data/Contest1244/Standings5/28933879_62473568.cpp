#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n;
string s;

void solv(){
	cin>>n>>s;
	int ans = n;
	fr(i, 0, n){
		if(s[i] == '1'){
			ans = max(2*(n - i), max(ans, 2*(i + 1)));
		}
	}
	cout<<ans<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
	
	int t;
	cin>>t;
	while(t--) solv();	
}