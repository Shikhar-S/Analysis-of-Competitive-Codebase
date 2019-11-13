#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
#define MOD 1000000007
ll sol[100005];
int main()
{
    sstring(s);
	sol[0]=1;
	sol[1]=1;
	for(int i=2;i<=s.size();i++){
		sol[i]=sol[i-1]+sol[i-2];
		sol[i]%=MOD;
	}
	// u n
	// w m
	ll ans=1;
	char last='x';
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='w' || s[i]=='m')
		{
			printf("0\n");
			return 0;
		}
		if(s[i]=='n')
		{
			if(last == 'n')
			{
				cnt++;
				last = 'n';
			}
			else
			{
				cnt=1;
				last='n';
			}
		}
		else
		{
			ans *= sol[cnt];
			ans%=MOD;
			last = 'x';
			cnt=0;
		}
		// debug(ans);
	}
	ans*=sol[cnt];
	ans%=MOD;
	last='x';
	cnt=0;
	// endl;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='u')
		{
			if(last == 'u')
			{
				cnt++;
				last = 'u';
			}
			else
			{
				cnt=1;
				last='u';
			}
		}
		else
		{
			ans *= sol[cnt];
			ans%=MOD;
			last = 'u';
			cnt=0;
		}
		// debug(ans);
	}
	ans*=sol[cnt];
	ans%=MOD;
	Wl(ans);
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
