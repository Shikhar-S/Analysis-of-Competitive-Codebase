// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int main(){
	int te;scanf("%d",&te);
	while(te--){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		int c2 = 3*min(b,c/2);
		int g2 = min(b,c/2);
		b -= g2;
		
		int c1 = 3*min(a,b/2);
		printf("%d\n",c1+c2);
	}

	return 0;
}
