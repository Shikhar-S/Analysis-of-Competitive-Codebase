#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
 
#define edl '\n'
#define ll long long int
 
#define forn(i,n) for ( int i=0 ; i<n ; i++ )
#define forni(i,j,n) for ( int i=j ; i<n ; i++ )
#define forr (i,n) for ( int i=n; i>=0; i-- )
#define numb(arr,i) (int)(arr[i]-'0')
 
#define filecode ifstream cin("input.txt");ofstream cout("output.txt");
#define IOFAST ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
 
#define MOD 1000000007
#define PI 3.14159265
 
int main() {
 
    IOFAST;
    int t;
    cin >> t;
    int a,b,c;
    while ( t-- ){
        cin >> a >> b >> c;
        ll ans = 0;
        int tmp = min(b,c/2);
        ans += tmp*3;
        b -= tmp;
        tmp = min(a,b/2);
        ans += tmp*3;
        cout << ans << edl;
    }
 
}