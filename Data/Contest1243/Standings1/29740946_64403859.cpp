#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define nl '\n'

#define boost ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const ll INF=1e18;
const int inf=1e9;
const ld eps=1e-7;
const ld pi=acos(-1);
const int dx[8]={0,0 ,1,-1,1,1,-1,-1};
const int dy[8]={1,-1,0,0,1,-1,1,-1};
const int mod1=998244353;
const int mod=1e9+7;
const int N=1e5+11;

pii p[N];
set<int>g[N];
int num[N];

int main(){
  boost;
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    g[u].insert(v);
    g[v].insert(u);
  }
  set<int>s;
  for(int i=1;i<=n;i++){
    p[i]=mp(sz(g[i]),i);
    s.insert(i);
  }
  sort(p+1,p+n+1);
  vector<int>q;
  set<pii>x;
  for(int i=1;i<=n;i++){
    num[p[i].y]=i;
    x.insert(mp(num[p[i].y],p[i].y));
  }
  int ans=0;
  while(!x.empty()){
    pii pr=*x.begin();
    x.erase(pr);
    int v=pr.y;
    s.erase(v);
    while(!s.empty()){
      int u=*s.begin();
      s.erase(u);
      if(g[v].find(u)==g[v].end()&&u!=v){
        ans++;
        x.erase(mp(num[u],u));
        num[u]=1;
        x.insert(mp(num[u],u));
      }
      else q.pb(u);
    }
    while(!q.empty()){
      s.insert(q.back());
      q.pop_back();
    }
  }
  cout<<n-1-ans;
  return 0;
}
