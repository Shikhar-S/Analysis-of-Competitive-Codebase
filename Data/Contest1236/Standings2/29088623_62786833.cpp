#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MOD (ll)(1e9 + 7)
#define MAX 1000000  // 階乗をいくつまで計算するか

class modlong;
void computeAll(long n);
modlong modComb(long n, long k);
modlong modFact(long n);

class modlong {
    ll val;
    const ll mod = MOD;

public:
    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(ll init = 0) {
        while (init < 0) init += mod;  // 0以上であることを保証
        val = init % mod;
    }

    // longへのキャスト operator long()で定義すると modlong +
    // longとかができなくなる
    ll tol() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const ll &r) {
        ll rr = r;
        while (rr < 0) rr += mod;  // 0以上であることを保証
        this->val = rr % mod;
    }

    //比較
    bool operator<(const modlong &r) { return this->val < r.val; }
    bool operator>(const modlong &r) { return this->val > r.val; }
    bool operator==(const modlong &r) { return this->val == r.val; }
    bool operator!=(const modlong &r) { return !(*this == r); }
    bool operator<=(const modlong &r) { return !(*this > r); }
    bool operator>=(const modlong &r) { return !(*this < r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        ll aval = (this->val + r.val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong operator-() {
        ll aval = (mod - this->val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        ll aval = (this->val * r.val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong inv() {
        if (*this == 1) return modlong(1);
        if (*this == 0) cerr << "modlong warning: dividebyzero!!!" << '\n';

        modlong p, q = *this, m(0), n(1), r, c;
        p.val = mod;  // p=modとかくとp.val=mod%mod=0となってしまう
        while (q > 1) {
            r = p.val %
                q.val;  // r.val=p.val / q.val
                        // とかくよりもこのほうが代入時に%modされるので安全
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n;
    }
    modlong operator/(const modlong &r) {
        modlong rr = r;
        return *this * rr.inv();
    }

    // ++ -- 前付きと後ろ付き
    void operator++() { ++this->val; }
    void operator++(int a) {
        a = 0;
        this->val++;
    }  // a使ってなくねっていうwarningをsilenceするためにaをいじってる
    void operator--() { --this->val; }
    void operator--(int a) {
        a = 0;
        this->val--;
    }

    // 四則演算&代入
    void operator+=(const modlong &r) { *this = *this + r; }
    void operator-=(const modlong &r) { *this = *this - r; }
    void operator*=(const modlong &r) { *this = *this * r; }
    void operator/=(const modlong &r) { *this = *this / r; }

    // べき乗
    modlong pow(ll n) {
        if (n < 0)
            return inv().pow(-n);  // 逆元の-n乗
        else if (n == 0)
            return modlong(1);

        modlong half = pow(n / 2);
        if (n % 2)
            return *this * half * half;
        else
            return half * half;
    }

    // コンビネーション modCombは少し下に書いてある
    modlong C(modlong k) { return modComb(this->val, k.val); }
    modlong fact() { return modFact(this->val); }

    friend ostream &operator<<(ostream &os, const modlong &out);
    friend istream &operator>>(istream &is, modlong &out);
};

// cout、cerr、cin用の演算子たち
ostream &operator<<(ostream &os, const modlong &out) {
    os << out.val;
    return os;
}
istream &operator>>(istream &is, modlong &in) {
    ll inl;
    is >> inl;
    in.val = inl % MOD;
    return is;
}

//////      階乗を全て求める -> 二項係数を求める

ll invs[MAX], facts[MAX], finvs[MAX];
ll listlen = 0;  // invs, facts, finvsの配列長
void computeAll(ll n) {
    if (n >= MAX)
        cerr << "modlong error: index out of range in computeAll" << '\n';
    ll i;
    if (listlen == 0) {
        invs[1] = 1;
        facts[0] = 1;
        facts[1] = 1;
        finvs[0] = 1;
        finvs[1] = 1;
        i = 2;
    } else {
        i = listlen;
    }
    if (n < 2) return;
    for (; i <= n; i++) {
        invs[i] = -invs[MOD % i] * (MOD / i) % MOD;
        facts[i] = facts[i - 1] * i % MOD;
        finvs[i] = finvs[i - 1] * invs[i] % MOD;
    }
    listlen = n + 1;  // 次呼び出すときはn+1以降から再開すれば良い
}
// コンビネーション
modlong modComb(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (listlen <= n) computeAll(n);  // 毎回足りない分だけ補う
    return modlong(facts[n]) * finvs[k] * finvs[n - k];
}
// 階乗
modlong modFact(ll n) {
    if (listlen <= n) computeAll(n);  // 毎回足りない分だけ補う
    return modlong(facts[n]);
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << (modlong(2).pow(m) - 1).pow(n) << '\n';
    return 0;
}