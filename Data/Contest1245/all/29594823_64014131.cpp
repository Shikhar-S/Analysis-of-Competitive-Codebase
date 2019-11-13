 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=3e5+5,MOD=1e9+7;

string a;

ll memo[N];
ll solve(int indx){
	if (indx==sz(a))
        	return 1;
    	ll &ret=memo[indx];
    	if (~ret)
       	 return ret;
    	ret=solve(indx+1)%MOD;
    	if (a[indx]=='w' || a[indx]=='m')
        	return 0;
    	if (a[indx]=='n' && a[indx+1]=='n')
       		ret+=(solve(indx+2)),ret%=MOD;
    	if (a[indx]=='u' && a[indx+1]=='u')
        	ret+=solve(indx+2),ret%=MOD;
   	
   	return ret;
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();

 	cin>>a;

 	memset(memo,-1,sizeof(memo));

 	cout<<solve(0)<<endl;



}