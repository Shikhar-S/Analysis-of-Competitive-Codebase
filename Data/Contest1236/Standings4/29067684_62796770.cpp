#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <bitset>
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int M = 1e9 + 7;
//__int128

int d[333][333];
signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, x = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    if(i & 1) {
      for(int j = 1; j <= n; ++j) {
        d[i][j] = ++x;
      }
    }
    else {
      for(int j = n; j >= 1; --j) {
        d[i][j] = ++x;
      }
    }
  }
  for(int j = 1; j <= n; ++j) {
    for(int i = 1; i <= n; ++i) {
      cout << d[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}