#include <bits/stdc++.h>
using namespace std;
#define sc(x)            scanf("%d",&x)
#define scc(x)           scanf("%c",&x)
#define scl(x)           scanf("%lld",&x)
#define sz(v)	     	(v.size())
#define mem(v, d)		memset(v, d, sizeof(v))
#define oo				2000000100
#define OO				2000000000000000100
#define PI 3.14159265
#define s second
#define f first
#define Ceil(x,y) ((x+y-1)/y)
#define EPS 1e-8
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const double pi=3.14159265358979323846264338327950288419716939937510582097494459;
typedef unsigned int uint;
typedef long long ll;
int dX[] = {0,0,1,-1,0};
int dY[] = {1,-1,0,0,0};
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int N = 8080;
const int MOD = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
#else
    //freopen("journey.in","r",stdin);
    //freopen("journey.out","w",stdout);
#endif
    int t;
    sc(t);
    while(t--)
    {
        int a,b,c,d,k; sc(a); sc(b); sc(c); sc(d); sc(k);
        int x = Ceil(a,c);
        int y = Ceil(b,d);
        if(x+y<=k) printf("%d %d\n",x,y);
        else puts("-1");
    }

    return 0;
}
