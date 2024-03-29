#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define FI(i,n) for(int i=0;i<=n;i++)
#define TR(x) cout << #x << " = " << x << endl
#define FE(k) get<0>(k)
#define SE(k) get<1>(k)
#define TH(k) get<2>(k)
#define TRAV(a, x) for(auto &a: x)
#define _ << " " <<
#define INF 1E9
#define INF64 1E18

using namespace std;

template<class T1, class T2> void pr(const pair<T1,T2>& x);
template<class T, size_t SZ> void pr(const array<T,SZ>& x);
template<class T> void pr(const vector<T>& x);
template<class T> void pr(const set<T>& x);
template<class T1, class T2> void pr(const map<T1,T2>& x);
template<class T> void pr(const T& x) { cout << x; }
template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
  pr(first); pr(rest...);
}
template<class T1, class T2> void pr(const pair<T1,T2>& x) {
  pr("{",x.first,", ",x.second,"}");
}
template<class T> void prContain(const T& x) {
  pr("{");bool fst = 1; TRAV(a,x) pr(!fst?", ":"",a), fst = 0;pr("}");
}
template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
template<class T> void pr(const vector<T>& x) { prContain(x); }
template<class T> void pr(const set<T>& x) { prContain(x); }
template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

void ps() { pr("\n"); }
template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
  pr(first," "); ps(rest...); // print w/ spaces
}

template<typename T> int remin(T& a,const T& b){if(b<a){a=b;return true;}return false;}
template<typename T> int remax(T& a,const T& b){if(b>a){a=b;return true;}return false;}

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define MAX 1000000
int id[MAX], sz[MAX];

int N;
ii coo[2005];
int k[2005], c[2005];

int root(int i) {
  while (i != id[i]) {
    id[i] = id[id[i]];
    i = id[i];
  }
  return i;
}

bool find(int p, int q) {
  return root(p) == root(q);
}

bool unite(int p, int q) {
  int i = root(p);
  int j = root(q);
  if (j == i) return false;
  if (sz[i] < sz[j]) {
    id[j] = i;
    sz[i] += sz[j];
  } else {
    id[i] = j;
    sz[j] += sz[i];
  }
  return true;
}
/**
 * To get the size of a node: sz[root(i)] !
 */

inline ll cost(int i, int j) {
  ll km = abs(coo[i].first - coo[j].first) + abs(coo[i].second - coo[j].second);
  return 1LL * (k[i] + k[j]) * km;
}

int main(int argc, const char **argv) {
  scanf("%d", &N);
  // Root is 0
  for (int i = 1; i <= N; ++i) {
    id[i] = i;
    sz[i] = 1;
    int x, y;
    scanf("%d%d", &x, &y);
    coo[i] = ii(x, y);
  }
  ll total = 0, stations = 0;
  vector<pair<ll, ii>> w;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &c[i]);
    w.push_back(make_pair(c[i], ii(0, i)));
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &k[i]);
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) continue;
      w.push_back(make_pair(cost(i, j), ii(i, j)));
    }
  }
  vi cities;
  vii connections;
  sort(w.begin(), w.end());
  for (int i = 0; i < (int)w.size(); ++i) {
    if (sz[root(0)] == N + 1) break;
    auto [u, v] = w[i].second;
    if (root(u) != root(v)) {
      total += w[i].first;
      unite(u, v);
      if (u == 0) {
        stations++;
        cities.push_back(v);
      } else {
        connections.push_back(ii(u, v));
      }
    }
  }
  ps(total);
  ps(stations);

  for (int c: cities) {
    printf("%d ", c);
  }
  printf("\n%d\n", (int) connections.size());
  for (auto [u, v]: connections) {
    ps(u, v);
  }
  return 0;
}
