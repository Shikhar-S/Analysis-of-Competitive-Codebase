#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void mian()
{
    int a,b;scanf("%d%d",&a,&b);
    if(gcd(a,b)==1)printf("Finite\n");
    else printf("Infinite\n");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)mian();
}
