//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N=1e6;


int main(){
	fastio;
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		//trace(a); trace(b);
		//trace(__gcd(a,b));
		if(__gcd(a,b)!=1) cout<<"in";
		cout<<"finite"<<endl;
	}
	return 0;
}