#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

int n,m,aa[N];
void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>aa[i];
	sort(aa,aa+n);
	int an=0;
	for(int i=n-1;i>-1;i--){
		int sd = min(n-i,aa[i]);
		an=max(an,sd);
	}
	cout<<an<<'\n';
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	
	return 0;
}
