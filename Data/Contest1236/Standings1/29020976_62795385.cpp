#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
#define For(i,a,b) for (register int i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define MP make_pair
using namespace std;
typedef long long ll;
int t,a,b,c,ans;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline int solve()
{
	int x,y,z,ret=0,tmp,sum;
	
	sum=0;
	x=a,y=b,z=c;
	tmp=min(x,y/2);
	sum+=3*tmp;
	x-=tmp,y-=2*tmp;
	tmp=min(y,z/2);
	sum+=3*tmp;
	ret=max(ret,sum);
	
	sum=0;
	x=a,y=b,z=c;
	tmp=min(y,z/2);
	sum+=3*tmp;
	y-=tmp,z-=2*tmp;
	tmp=min(x,y/2);
	sum+=3*tmp;
	ret=max(ret,sum);
	
	return ret;
}
int main()
{
	t=read();
	while (t--)
	{
		a=read(),b=read(),c=read();	
		ans=solve();
		write(ans),putchar('\n');
	}
	return 0;
}
