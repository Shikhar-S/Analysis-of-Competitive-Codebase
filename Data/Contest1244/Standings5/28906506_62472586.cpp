#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 2e3+5;

ll dp[L][2];

ll n;
string s;

ll solve(ll room, ll floor)
{
    if(room < 1 || room > n)
    {
        return 0;
    }

    if(dp[room][floor] != -1)
    {
        return dp[room][floor];
    }

    dp[room][floor] = 1 + dp[room][floor+1];

    if(s[room-1] == '1')
    {
        dp[room][floor] = max(dp[room][floor], 1 + dp[room][floor^1]);
    }

    return dp[room][floor];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        // ll n;
        cin >> n;

        // string s;
        cin >> s;

        ll last = -1;

        for(ll i=0; i<n; i++)
        {
            if(s[i] == '1')
            {
                last = max(last, i);
            }
        }

        for(ll i=n-1; i>=0; i--)
        {
            if(s[i] == '1')
            {
                last = max(last, n-i-1);
            }
        }

        if(last != -1)
        {
            cout << 2*(1 + last) << endl;
        }

        else
        {
            cout << n << endl;
        }
    }

    return 0;
}