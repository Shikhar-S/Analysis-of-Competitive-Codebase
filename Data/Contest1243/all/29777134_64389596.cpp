#include<bits/stdc++.h>
#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
#define mod Mod
#define LL ll
typedef vector<long long> VI;
typedef pair<long long,long long> PII;

typedef long long ll;
const int maxn = 2e5 + 5;
const ll Mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=Mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%Mod;a=a*a%Mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head

    ll n,chunum;
    int chu;

int main()
{
    #ifdef LOCAL
        freopen("D:\\123.txt","r",stdin);
    #endif // LOCAL
    cin >> n;
    if(n == 1){
        printf("1\n");
        return 0;
    }
    chu = 0;
    for(ll i = 2;i <= sqrt(n);i ++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            chunum = i;
            chu ++;
        }
    }
    if(n != 1){
        chu ++;
        chunum = n;
    }
    if(chu == 1) printf("%lld\n",chunum);
    else printf("1\n");
    return 0;
}

