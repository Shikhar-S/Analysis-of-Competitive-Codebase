//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,p,d,w;
    cin>>n>>p>>w>>d;
   	ll x=p/w;
   	ll left=p-(p/w)*w;
   	// ll lcm=(w*d)/__gcd(w,d);
   	ll y=n+1;
   	// cout<<left<<'\n';
   	for (ll i = 0; i <=1000000; ++i)
   	{
   		if((left+i*w)%d==0)
   		{
   			x-=i;
   			y=(left+i*w)/d;
   			break;
   		}
   	}
   	// cout<<x<<" "<<y<<'\n';
   	ll z=n-x-y;
   	if(x>=0 && y>=0 && z>=0 && x*w+y*d-p==0)
   	{
   		cout<<x<<" "<<y<<" "<<z<<'\n'; 
   	}
   	else
   	{
   		cout<<"-1\n";
   	}
}
