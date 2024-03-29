#include <bits/stdc++.h>
using namespace std;
const int N=(int)(2e5+12);
int n,m,k,cnt[N],x,y,i;
unordered_map<int, bool>u[N];
bitset<N> bit;
set<int> s;
void dfs(int v){
	s.erase(v),	cnt[k]++;
	vector<int>a;
	for(auto it: s) if(!u[v][it])a.push_back(it);
	for(auto it : a) s.erase(it);
	for(auto it : a) dfs(it);
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin>>n>>m;
	for(i=1;i<=n;++i)s.insert(i);
	for(i=1;i<=m;++i)cin>>x>>y,u[x][y]=u[y][x] =1;
	while((int)s.size())dfs(*s.begin()),k++;
	cout<<k-1<<'\n';
}
