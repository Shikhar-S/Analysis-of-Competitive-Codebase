#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    return a == 0 ? b : gcd(b%a,a);
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%s\n",gcd(a,b)==1?"Finite":"Infinite");
    }
}
