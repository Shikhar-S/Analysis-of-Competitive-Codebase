#include<bits/stdc++.h>
using namespace std;

#define fi(i,a,b)    for(long long i=a;i<=b;i++)
#define fr(i,a)      for(long long i=0;i<a;i++)
#define fd(i,a,b)    for(long long i=b;i>=a;i--)
#define clr(x)       memset(x,0,sizeof(x))
#define cln(x)       memset(x,-1,sizeof(x))
#define __           printf(" ")
#define _            printf("\n")
#define _o           printf("1\n")
#define stree        long long lft=node<<1,rht=(node<<1)|1,mid=(s+e)>>1
#define snode        long long s,long long e,long long node
#define slft         s,mid,lft
#define srht         mid+1,e,rht
#define sin()        if(S<=s&&e<=E)
#define sout()       if(S>e||s>E)
#define mod          1000000007
#define read()       freopen("in.txt","r",stdin)
#define write()      freopen("out.txt","w",stdout)
#define sfl(x)       scanf("%I64d",&x)
#define sfll(x,y)    scanf("%I64d %I64d",&x,&y)
#define sflll(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)
#define pfl(x)       printf("%I64d",x)
#define pfll(x,y)    printf("%I64d %I64d",x,y)
#define pflll(x,y,z) printf("%I64d %I64d %I64d",x,y,z)
#define xx           100000

typedef long long ll;
typedef pair<long long,long long> pll;

char s[10000];

main(){
    long long q;
    cin>>q;
    while(q--){
        long long n,ans;
        cin>>n;
        ans=n;
        scanf("%s",s);
        fr(i,n) if(s[i]=='1'){
           long long cur=max(i+1,n-i);
           cur*=2;
           ans=max(cur,ans);
        }
        cout<<ans<<endl;
    }



    return 0;
}
