#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n;
ll a[100100];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    sort(a, a+n);
    ll sum =0 ;
    int lim = n/2;
    for (int j = n-1 ; j >= lim; --j)
        sum += a[j];
    ll sum2 = 0 ;
    for (int j = lim-1; j >= 0; --j)
        sum2 += a[j];
    sum *= sum;
    sum2 *= sum2;
    sum += sum2;
    printf("%lld\n", sum);

	return 0;
}
