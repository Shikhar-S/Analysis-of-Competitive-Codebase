/*
    TOP GUN: MAVERICK!!
                                */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
//#include <boost/functional/hash.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
lli mod=1e9+7ll;
lli INF=1e17;
#define sqr(x) (x) * (x)
#define bip(n) __builtin_popcountll(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctzll(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clzll(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffsll(n)//index of first one bit!!
typedef pair<lli,lli> ll;
#define mem1(a,x) fill(&a[0], &a[0] + sizeof(a) / sizeof(a[0]), x)
#define mem2(a,x) fill(&a[0][0], &a[0][0] +sizeof(a)/sizeof(a[0][0]),x)
#define mem3(a,x) fill(&a[0][0][0], &a[0][0][0] +sizeof(a)/sizeof(a[0][0][0]),x)
#define fi1 ifstream fin("input.txt")
#define of1 ofstream fout("output.txt")
int fmx(int x, int y) { return (((y-x)>>(31))&(x^y))^y; }
int fmi(int x, int y) { return (((y-x)>>(31))&(x^y))^x; }
typedef tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update> ost;
lli n,q,z,y,k,m;
const double pi1=3.14159265358979323846;
//unordered_map<pair<ll,lli>,lli> mp;
lli me(lli a,lli b,lli M)
{
    if(b==0)
    return 1;
    else if(b%2==0)
    return me((a*a)%M,b/2,M);
    else
    return (a%M*me((a*a)%M,(b-1)/2,M)%M)%M;
}
lli mI(lli a,lli m)
{
    return me(a,m-2,m);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        lli ans=0;
        while(c>1&&b>0)
        {
            ans+=3;
            b-=1;
            c-=2;
        }
        while(b>1&&a>0)
        {
            ans+=3;
            b-=2;
            a-=1;
        }
        cout<<ans<<"\n";
    }
}