#include<bits/stdc++.h>
using namespace std;

# define C continue;
# define R return

# define D double
# define I insert
# define ll long long
# define ld long double

# define ull unsigned long long
# define ui unsigned int

# define pb push_back
# define pf push_front

# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >

# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";

string vow = "aeiou";

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 0 , 1 } ;
const int dy[] = { 0 , -1 , 1 , 0 } ;

const ld pie = 3.14159265358979 ;
const ll mod = 1e9 + 7 ;

void solve ( int test_case )
{
    int n ; cin >> n ;
    string s , t ;
    cin >> s >> t ;

    string temp1 = "" , temp2 = "" ;

    for ( int i=0 ; i < n ; i++ )
    {
        if ( s[i] == t[i] ) C ;

        temp1 += s[i] ;
        temp2 += t[i] ;
    }

    if ( temp1.size() != 2 || temp2.size() != 2 ) { cout << "No" ; line ; R ; }

    if ( temp1[0] == temp1[1] && temp2[0] == temp2[1] )
        cout << "Yes" ;
    else
        cout << "No" ;

    line
}

int main()
{
    int t = 1;
    cin >> t;

    for ( int i=0 ; i < t ; i++ ) solve(i);
    return 0;
}
