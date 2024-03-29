#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

VPII cx;
multimap<LL,PII> mm;
VI ps;

int findp(int i){
    if (ps[i]!=i) ps[i]=findp(ps[i]);
    return ps[i];
}

void merge(int i,int j){
    if (findp(j)<findp(i)) merge(j,i);
    else{
        ps[findp(j)]=ps[findp(i)];
    }
}


int main(){
    DRI(n);
    ps = VI(n+1);
    REP(i,n+1){ps[i]=i;}

    REP(i,n){
        DRII(x,y);
        cx.PB({x,y});
    }
    VI c(n+1);
    REP(i,n){
        RI(c[i+1]);
        mm.insert({c[i+1],{0,i+1}});
    }
    VI k(n+1);
    REP(i,n){
        RI(k[i+1]);
    }
    REPP(i,1,n+1){
        REPP(j,i+1,n+1){
            LL cost= ((LL)abs(cx[i-1].F-cx[j-1].F) + abs(cx[i-1].S-cx[j-1].S)) *((LL)k[i]+k[j]);
           // cout<<i<<" "<<j<<" cost: "<<cost<<" "<<max(c[i],c[j])<<endl;
            if (cost<max(c[i],c[j])) mm.insert({cost,{i,j}});
        }
    }
    LL tc=0;
    int v=0;
    VI vv;
    int e=0;
    VPII ev;
    for (auto p: mm){
        LL c=p.F;
        LL x=p.S.F;
        LL y=p.S.S;
       // cout<<"cost : "<<c<<" "<<x<<" "<<y<<endl;
        if (findp(x)!=findp(y)){
            merge(x,y);
            tc+=c;
            if (min(x,y)){
                e++;
                ev.PB({x,y});
            }
            else{
                v++;
                vv.PB(x+y);
            }
        }
    }
    printf("%I64d\n",tc);
    printf("%d\n",v);
    REP(i,v){ printf("%d%c",vv[i],i==v-1?'\n':' ');}
    printf("%d\n",e);
    REP(i,e){ printf("%d %d\n",ev[i].F,ev[i].S);}
}
