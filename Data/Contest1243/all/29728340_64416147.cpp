#include<bits/stdc++.h>

using namespace std;

template<typename T> std::string toString(T val){std::ostringstream oss; oss << val; return oss.str();}
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second << '\n'; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front() << ' '; for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << *_it <<' '; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; }for (auto _it:_m) { _out << _it.first << ": " << _it.second << '\n'; } return _out; }

#define pb push_back
#define int long long
#define X first
#define Y second
#define pog long double
#define all(x) x.begin(),x.end()

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

//int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
//int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

struct cord{
    int x, y, z;
};

vector<int> zfun(string s){
    int n = s.size();
    vector<int> z(n,0);
    for(int i = 1, l = 0, r = 0;i < n;i++){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int mod = 1e9 + 7;
long long bin_pow(long long base, long long p) {
    int res = 1;
    while(p){
        if(p & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return res;
}

long long inverse_element(long long x) {
    return bin_pow(x, mod - 2);
}

long long divide(long long a, long long b) {
    return a * inverse_element(b) % mod;
}
void en(int num){
    cout <<  (num == 1 ? "YES" : "NO");
    exit(0);
}
struct trio{
    int x, y, z;
};
vector<int> v;
int find_set(int j){
    if(j == v[j]) return j;
    return v[j] = find_set(v[j]);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("black.out", "w", stdout);
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pair<int,int> > ans;
        int can = 1;
        for(int i = 0;i < n;i++){
            if(s[i] == t[i]){
                ans.push_back({i+ 1, i+ 1});
                continue;
            }
            int jt = i;
            for(;jt < n;jt++){
                if(t[jt] == s[i] && t[jt] != s[jt]) break;
            }
            int here = 0;
            for(int r = i + 1; r < n; r++)
                if(s[r] == s[i] && t[r] == t[i]){
                    swap(s[i], t[r]);
                    here = 1;
                    ans.push_back({i + 1, r + 1});
                    break;
                }
            if(here) continue;
            if(jt == n){
                jt = i + 1;
                for(;jt < n;jt++){
                    if(s[i] == s[jt] && s[jt] != t[jt]){
                        swap(s[jt], t[i]);
                        ans.push_back({jt + 1, i + 1});
                        break;
                    }
                }
                continue;
            }
            swap(t[jt], s[jt]);
            swap(s[jt], t[i]);
            ans.push_back({jt + 1, jt + 1});
            ans.push_back({jt + 1, i + 1});

        }
        if(s == t) {
            cout << "Yes\n";
            cout << ans.size() << '\n';
            for (auto x: ans) cout << x.X << ' ' << x.Y << '\n';
        }
        else{
            cout << "No\n";
        }
    }
    return 0;

}