#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
template<int MOD> struct Fp {
	long long val;
	constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) v += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	constexpr Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr Fp& operator /= (const Fp& r) noexcept {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
		return is >> x.val;
	}
	friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};
// 二項係数ライブラリ
template<class T> struct BiCoef {
	vector<T> fact_, inv_, finv_;
	constexpr BiCoef() {}
	constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
		init(n);
	}
	constexpr void init(int n) noexcept {
		fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
		int MOD = fact_[0].getmod();
		for(int i = 2; i < n; i++){
			fact_[i] = fact_[i-1] * i;
			inv_[i] = -inv_[MOD%i] * (MOD/i);
			finv_[i] = finv_[i-1] * inv_[i];
		}
	}
	constexpr T com(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[k] * finv_[n-k];
	}
	constexpr T fact(int n) const noexcept {
		if (n < 0) return 0;
		return fact_[n];
	}
	constexpr T inv(int n) const noexcept {
		if (n < 0) return 0;
		return inv_[n];
	}
	constexpr T finv(int n) const noexcept {
		if (n < 0) return 0;
		return finv_[n];
	}
};
using mint = Fp<MOD>;
BiCoef<mint> bc;//bc.init(500050)

signed main(){
	IOS();
	bc.init(500050);
	int N,M;
	cin>>N>>M;
	mint ans = 1;
	FOR(i,1,N/2+1){ //縦置き
		int two=i,one=N-i*2;
		ans+=bc.com(two+one,two);
	}
	FOR(i,1,M/2+1){
		int two=i,one=M-i*2;
		ans+=bc.com(two+one,two);
	}
	cout<<ans*2<<endl;
}