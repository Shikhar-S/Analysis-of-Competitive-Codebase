#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream>
#include<iterator>
#include<math.h>
#include<cmath>
#include<sstream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>
#include<algorithm>
#include<map>
#include<thread>
#include<stack>
#include<numeric>
#include<functional>
#include<queue>
#include<set>
#include<list>
#include<bitset>
#include<unordered_map>
#include<cassert>


typedef long long ll;

using namespace std;

const ll inf = 1e15;
const ll MOD = 1e9 + 7;
// 9223372036854775807 2^63 - 1

struct th
{
  ll x, y, ind;
  ll c, k;
};


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << setprecision(30);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // _DEBUG
#ifndef _DEBUG
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif // !_DEBUG

  int k;
  cin >> k;

  while (k--)
  {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &i : a)
    {
      cin >> i;
    }

    sort(a.rbegin(), a.rend());
    ll ans = 0;

    for (int i = 0; i < a.size(); ++i)
    {
      if (a[i] > ans) ++ans;
      else break;
    }

    cout << ans << endl;
  }


  return 0;

}