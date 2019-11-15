// g++ -std=c++14

#include <bits/stdc++.h>

typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const bool DEBUG = 1;

#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define LET(x, a) __typeof(a) x(a)
#define foreach(it, v) for (LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a, b) memset(a, b, sizeof(a))
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define __                                                                     \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6

#define RUN_T                                                                  \
  int _t;                                                                      \
  cin >> _t;                                                                   \
  while (_t--)

#define tr(...)                                                                \
  if (DEBUG) {                                                                 \
    cout << __FUNCTION__ << ' ' << __LINE__ << " = ";                          \
    trace(#__VA_ARGS__, __VA_ARGS__);                                          \
  }

template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
  out << '(' << p.fi << ", " << p.se << ')';
  return out;
}

template <typename T> ostream &operator<<(ostream &out, set<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, unordered_map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T> ostream &operator<<(ostream &out, multiset<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> const &v) {
  ll l = v.size();
  for (ll i = 0; i < l - 1; i++)
    out << v[i] << ' ';
  if (l > 0)
    out << v[l - 1];
  return out;
}

template <typename T> void trace(const char *name, T &&arg1) {
  cout << name << " : " << arg1 << endl;
}

template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

#define int ll

// __builtin_popcount -> count number of bits

int32_t main() {
    _
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        char ar[n+1];
        for(int i=0;i<=n;i++){
            ar[i]='o';
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(s[i]=='R' and b>0){
                ar[i]='P';
                cnt++;
                b--;
            }else if(s[i]=='P' and c>0){
                ar[i]='S';
                cnt++;
                c--;
            }else if(s[i]=='S' and a>0){
                ar[i]='R';
                a--;
                cnt++;
            }
        }
        int pr=n/2;
        if(n%2==1){
            pr+=1;
        }
        if(cnt>=pr){
            for(int i=0;i<n;i++){
                if(ar[i]=='o'){
                    if(a>0){
                        ar[i]='R';
                        a--;
                    }else if(b>0){
                        ar[i]='P';
                        b--;
                    }else if(c>0){
                        ar[i]='S';
                        c--;
                    }
                }
            }
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ar[i];
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
