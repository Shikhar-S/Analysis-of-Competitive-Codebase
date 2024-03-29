#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e8;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 1e5+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

int v[N];

template <typename E>
std::vector<E> computeSlidingWindowMinOrMax(const std::vector<E> &array, std::size_t window, bool maximize) {
	if (window == 0)
		throw std::domain_error("Window size must be positive");
	
	std::vector<E> result;
	std::deque<E> deque;
	std::size_t countdown = window - 1;
	typename std::vector<E>::const_iterator tail = array.cbegin();
	for (const E &val : array) {
		while (!deque.empty() && ((!maximize && val < deque.back()) || (maximize && val > deque.back())))
			deque.pop_back();
		deque.push_back(val);
		
		if (countdown > 0)
			countdown--;
		else {
			result.push_back(deque.front());
			if (*tail == deque.front())
				deque.pop_front();
			++tail;
		}
	}
	return result;
}

int calc_ans(int n) {
    int i, ans = 0;
    vector<int> sum(n+n);
    sum[0] = v[0];
    for (i=1;i<n+n;i++) sum[i] = sum[i-1] + v[i];
    vector<int> res = computeSlidingWindowMinOrMax<int>(sum, n, 0);
    for (i=0;i<n;i++) {
        int chk = 0;
        if (i > 0) chk = sum[i-1];
        if (res[i] == chk && sum[i+n-1] == chk) ans++;
    }
    return ans;
}

void solve() {
    int n, i, j;
    cin >> n;
    string s;
    cin >> s;
    for (i=0;i<n;i++) {
        if (s[i] == '(') v[i] = 1;
        else v[i] = -1;
    }
    for (;i<n+n;i++) v[i] = v[i-n];
    // swap(v[0], v[1]);
    // swap(v[0+n], v[1+n]);
    int ans = calc_ans(n);
    int swapl = 0, swapr = 0;
    for (i=0;i<n;i++) for (j=i+1;j<n;j++) {
        swap(v[i], v[j]);
        swap(v[i+n], v[j+n]);
        int test = calc_ans(n);
        if (ans < test) {
            ans = test;
            swapl = i;
            swapr = j;
        }
        swap(v[i], v[j]);
        swap(v[i+n], v[j+n]);
    }
    cout << ans << "\n" << swapl+1 << " " << swapr+1 << '\n';
}

int main() {
    FASTIO; int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}