#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define ppa     pair<pair<int,int>,int>
#define pap     pair<int,pair<int,int>>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)      for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;

#define qqq 400005


void pontifex_maximus(){
    T{
        int n;cin>>n;
        v1d v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        RS(v);
        int ans=1;
        for(int i=0;i<n;i++){
            if(v[i]>=i+1)ans=i+1;
            else break;
        }
        cout<<ans<<endl;
    }



























}


int32_t main(){

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif

    pontifex_maximus();
    
}



