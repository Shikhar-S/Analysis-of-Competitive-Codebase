#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=12e4;

vector<int>t[N];
int c[3][N],d[N],cx[N];
bool u[N];

ll dfs(int x,int i,int pls=1,bool st=0){
	u[x]=1;
	if(st)cx[x]=i+1;
	for(int y:t[x])if(!u[y])
		return c[i][x]+dfs(y,(i+pls)%3,pls,st);
	return c[i][x];
}
int main(){
	ios::sync_with_stdio(0);
	int n,dx=0,x=0,y=0;
	cin>>n;
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		d[u]++;d[v]++;
		dx=max(dx,max(d[u],d[v]));
		t[u].push_back(v);
		t[v].push_back(u);
	}
	if(dx>2){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1)x=i;
	ll a[6];
	for(int i=0;i<6;i++){
		a[i]=dfs(x,i%3,i/3+1);
		//cout<<i/3+1<<' ';
		if(a[i]<a[y])y=i;
		memset(u,0,sizeof u);
	}
	cout<<a[y]<<'\n';
	dfs(x,y%3,y/3+1,1);
	for(int i=1;i<=n;i++)
		cout<<cx[i]<<' ';
	return 0;
}