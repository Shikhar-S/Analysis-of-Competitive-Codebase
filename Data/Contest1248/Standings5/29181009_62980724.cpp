#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define PB push_back
#define endl "\n"
typedef long long ll;
typedef long double ld;
const int mod = 1000000007;
const int N = 1005000;

int power(int x,int y,int m=mod){int res=1;x=x%m;while(y>0){if(y&1)res=(res*x)%m;y=y>>1;x=(x*x)%m;}return res;}
int ncr(int n,int r){if(n<r)return 0;int p=1,k=1;if(n-r<r)r=n-r;if(r!=0){while(r){p*=n;k*=r;int g=__gcd(p, k);p/=g;k/=g;n--;r--;}}else p=1;return p;}
//cout<<fixed<<setprecision(8)<<x<<endl;

signed main()
{
    fast;
    int t=1; cin>>t; while(t--)
    {
        int n,m;
        cin>>n;
        int cn0=0,cn1=0,cm0=0,cm1=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x%2)
                cn1++;
            else
                cn0++;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            if(x%2)
                cm1++;
            else
                cm0++;
        }
        //cout<< cn0 << cn1 << cm0 << cm1 << endl;
        cout<< (cn0*cm0 + cn1*cm1)<< endl;
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}


