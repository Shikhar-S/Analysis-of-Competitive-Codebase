//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define all(a) a.begin(), a.end()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
#define enter putchar('\n')
#define space putchar(' ')
#define Mem(a, x) memset(a, x, sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void debug_out() { cerr << '\n'; }

template<typename T, typename ...R>
void debug_out(const T &f, const R &...r) {
    cerr << f << " ";
    debug_out(r...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__);

inline ll read() {
    ll x = 0;
    int f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x = f ? -x : x;
}

inline void write(ll x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[23];
    int l = 0;
    while (x != 0)s[l++] = x % 10 + 48, x /= 10;
    while (l)putchar(s[--l]);
}

int lowbit(int x) { return x & (-x); }

template<class T>
T big(const T &a1, const T &a2) { return a1 > a2 ? a1 : a2; }

template<typename T, typename ...R>
T big(const T &f, const R &...r) { return big(f, big(r...)); }

template<class T>
T sml(const T &a1, const T &a2) { return a1 < a2 ? a1 : a2; }

template<typename T, typename ...R>
T sml(const T &f, const R &...r) { return sml(f, sml(r...)); }

template<class T, class U>
inline void checkMin(T &x, U y) { if (y < x) x = y; }

template<class T, class U>
inline void checkMax(T &x, U y) { if (y > x) x = y; }

template<class T, class U>
inline bool ifMax(T &x, U y) {
    if (y > x) return x = y, true;
    return false;
}

template<class T, class U>
inline bool ifMin(T &x, U y) {
    if (y < x) return x = y, true;
    return false;
}

const int M = 212345;// 2e5+5
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;// 1e9+7

// HAVE FREE OPEN IN MAIN FUNCTION

int _, n;
char a[55], b[55];
vector<pii> ans;
int tmp[400];

void init() {
    _ = read();
    while (_--) {
        ans.clear();
        Mem(tmp, 0);
        n = read();
        scanf("%s%s", a, b);
        for (int i = 0; i < n; i++) {
            tmp[a[i]]++;
            tmp[b[i]]++;
        }
        int flag = 0;
        for (char x = 'a'; x <= 'z'; x++) {
            if (tmp[x] % 2 != 0) {
                flag = -1;
            }
        }
        if (flag == -1) {
            puts("No");
            continue;
        }
        puts("Yes");
        for (int i = 0; i < n; i++) {
            if(a[i]==b[i])continue;
            char t = a[i];
            int pos = -1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == t) {
                    pos = j;
                    break;
                }
            }
            if (pos != -1) {
                swap(a[pos], b[i]);
                ans.emplace_back(pii{pos, i});
            } else {
                for (int j = i + 1; j < n; j++) {
                    if(b[j]==t){
                        pos=j;
                        break;
                    }
                }
                if(pos!=-1){
//                    debug(i,pos);
                    swap(b[pos],a[pos]);
                    ans.emplace_back(pii{pos,pos});
                    swap(a[pos],b[i]);
                    ans.emplace_back(pii{pos, i});
                }
            }
        }
        printf("%d\n",ans.size());
        for(auto x:ans){
            printf("%d %d\n",x.first+1,x.second+1);
        }
    }

}

void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();

    solve();

    return 0;
}