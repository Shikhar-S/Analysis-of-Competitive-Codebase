#include<bits/stdc++.h>

using namespace std;
const int MAXN = 310;

vector<int> res[MAXN];

signed main(){
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i % 2 == 0) res[j].push_back(n*(i - 1) + j);
			if(i % 2 == 1) res[n - j + 1].push_back(n*(i - 1) + j);
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < res[i].size();j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
