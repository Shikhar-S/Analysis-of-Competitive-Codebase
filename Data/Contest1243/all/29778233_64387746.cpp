#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ipair pair<ll int,ll int>
#define veci vector<ll int>
#define vecb vector<bool>
#define vecp vector< ipair >
#define vecs vector<string>
#define vecc vector<char>
#define vecd vector< vector<int> >
#define us unordered_set
#define um unordered_map
#define mnh priority_queue<ll int,vector<ll int>,greater<ll int> >
#define mxh priority_queue<ll int>
#define ms(c,val) memset(c,val,sizeof(c))
#define ret return
#define mxe *max_element
#define mne *min_element
#define fi first
#define se second
#define br break
#define len length()
#define sz size()
#define em empty()
#define con continue
#define all(c) c.begin(),c.end()
using namespace std;
ll int M=1e9+7;
void swap(ll int *x,ll int *y){
    ll int t=*x;
    *x=*y;
    *y=t;
}

void init(vector<ll int> &v,ll int n){
    for(ll int i=0;i<n;i++){
        cin>>v[i];
    }
}
void print(vector<ll int> &v){
    for(ll int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void initg(vector< vector<ll int> > &v,ll int m){
    ll int i,x,y;
    for(i=0;i<m;i++){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void solve(veci &v,ll int n)
{
    // Note that this loop runs till square root
    for (ll int i=1; i*i<=n; i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if ((n/i) == i)
                {
                    if(i!=1)
                    v.pb(i);
                }

            else // Otherwise print both
                {
                    if((n/i)!=1)
                    v.pb(n/i);
                    if(i!=1)
                    v.pb(i);
                }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll int t1,n,m,x1,x2,x3,x4,x5,x6,k,i,j,x,y,gcd;
    string s1,s2,s,s3;
    bool t5;
    t1=1;
   // cin>>t1;

        cin>>n;
        if(n==1){
            cout<<1<<endl;
            ret 0;
        }
        veci v;
        solve(v,n);
        gcd=v[0];
        for(i=1;i<v.sz;i++){
            gcd=__gcd(gcd,v[i]);
        }
        cout<<gcd<<endl;



























}