/*

প্রশ্ন জাগে আমার অদৃশ্য দেয়ালে
জানা অজানার গুণিন দেখে পরিশেষে
স্মৃতির প্রতিচ্ছবি তুমি সকল
অচেনার রুপকার আলেয়া অলংকারের
অদেখা স্বর্নকার স্বপ্নদেব
শোনো এই হাহাকার

-স্বপ্নদেব, VIBE

*/



#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long
#define fr(I,M,N) for(I=M;I<=N;I++)
#define fr_(I,M,N) for(I=M;I>=N;I--)
#define re return
#define sfn cin>>n
#define bal pf("bal\n")
#define pb push_back
#define ins insert
#define sz(X) X.size()
#define xx first
#define yy second
#define skip continue
#define memo(X,N) memset(X,N,sizeof(X))
#define all(X) X.begin(),X.end()
#define mp make_pair
#define pi acos(-1)


/*
#define nMX 5000000
#define pMX 500000
int pr[pMX+1],prnum[nMX+1];

int sieve()
{
    int i,j;
    for(i=1;i<=nMX;i++)
        prnum[i]=i+1;
    for(i=1;i<=nMX;i++)
        if(prnum[i]!=-1)
            for(j=2*prnum[i]-1;j<=nMX;j+=prnum[i])
                    prnum[j]=-1;
    j=0;
    for(i=1;i<=nMX;i++)
        if(prnum[i]!=-1)
            pr[++j]=prnum[i];
    re j;
}*/

/*ll m_ncr[10001][10001];
ll ncr(ll i,ll j)
{
    if(j==1) re i;
    if(i==j) re 1;
    if(m_ncr[i][j]!=-1) re m_ncr[i][j];
    re m_ncr[i][j]=ncr(i-1,j) + ncr(i-1,j-1);
}*/

/*ll m_fact[21];
ll fact(ll i)
{
    if(i==1 || i==0) re 1;
    if(m_fact[i]!=-1) re m_fact[i];
    re m_fact[i]=i*fact(i-1);
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll int i,j,x,y,n,m,cnt=0,k,g,flg,t;
    cin>>n;
    ll in[n+1];
    fr(i,1,n)
    {
        cin>>in[i];
        cnt+=in[i];
    }
    if(n==1)
    {
        cout<<in[1]*in[1];
        re 0;
    }
    sort(in+1,in+1+n);
    x=0;
    fr(i,1,n/2)
    {
        x+=in[i];
    }
    cnt-=x;
    cout<<cnt*cnt+x*x;
}
