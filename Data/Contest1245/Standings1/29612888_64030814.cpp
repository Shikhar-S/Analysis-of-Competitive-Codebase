#include <bits/stdc++.h>
using namespace std;
const int N = 105;

double ans, f[N][2];
int mp[N][N], id[N][N], to[N], cnt;

int main() {
	for (int i = 10; i >= 1; i--) {
		if (i%2 == 0) for (int j = 1; j <= 10; j++) id[i][j] = ++cnt;
		else  for (int j = 10; j >= 1; j--) id[i][j] = ++cnt;
	}
	for (int i = 1; i <= 10; i++)
	for (int j = 1; j <= 10; j++)
		scanf("%d", &mp[i][j]), to[id[i][j]] = id[i-mp[i][j]][j];
	f[100][0] = 0, f[100][1] = 1e9;
	f[99][0] = 6, f[99][1] = 1e9;
	f[98][0] = 6, f[98][1] = 1e9;
	f[97][0] = 6, f[97][1] = 1e9;
	f[96][0] = 6, f[96][1] = 1e9;
	f[95][0] = 6, f[95][1] = 1e9;
	for (int i = 94; i >= 1; i--) {
		for (int j = 1; j <= 6; j++)
			f[i][0] += 1./6*min(f[i+j][0], f[i+j][1]);
		++f[i][0];
		if (!to[i]) f[i][1] = 1e9;
		else f[i][1] = f[to[i]][0];
	}
	printf("%.9lf\n", min(f[1][0], f[1][1]));
	return 0;
}
