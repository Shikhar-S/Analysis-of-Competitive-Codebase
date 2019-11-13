#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair
#define big_prime 15486277
#define bigger_prime 179424697
#define biggest_prime 32416188691
//#define random_shuffle(indices.begin(), indices.end());
//std::random_device rd;
//std::mt19937 g(rd());
//std::shuffle(v.begin(), v.end(), g);
using namespace __gnu_pbds; 
using namespace std;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
// template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE


typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

#define Mod 1000000007
#define MAX 5002

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll T;cin>>T;
	while(T--){
		ll n;cin>>n;
		string s,t;cin>>s>>t;
		ll occ[26];
		memset(occ,0,sizeof(occ));
		for(char c:s) occ[c-'a']++;
		for(char c:t) occ[c-'a']++;
		bool ok = 1;
		For(i,0,26) if(occ[i]%2!=0) ok=0;
		if(!ok){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;

		vector<pii> ans;

		For(i,0,n){
			if(s[i]==t[i]) continue;
			else{
				assert(i!=n-1);

				ll index = -1;
				For(j,i+1,n) if(t[j]==t[i]){
					index = j;
					break;
				}

				if(index!=-1){
					swap(s[i],t[index]);
					ans.pb({i,index});
					continue;
				}else{
					For(j,i+1,n) if(t[i]==s[j]){
						index = j;
						break;
					}

					assert(index!=-1);

					ans.pb({index,i+1});
					swap(s[index],t[i+1]);
					ans.pb({i,i+1});
					swap(s[i],t[i+1]);
				}	

			}
		}

		cout<<ans.size()<<endl;
		for(pii x:ans){
			cout<<x.fi+1<<" "<<x.se+1<<endl;
		}

	}































	
}