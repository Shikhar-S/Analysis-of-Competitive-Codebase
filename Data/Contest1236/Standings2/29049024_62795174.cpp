#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define ld long double
#define y1 asdfghjkl
#define ufo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r){
    return (mt_rnd_64() % (r-l+1)) + l;
}

const int N = 3 * 1e2 + 5;

int n;
int a[N][N];

main()
{
    cin>>n;
    for(int i = 1;i <= n;i++){
        if(i % 2)
            for(int j = 1;j <= n;j++)
                a[j][i] = n*(i-1)+j;
        else
            for(int j = 1;j <= n;j++)
                a[j][i] = n*i-j+1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
