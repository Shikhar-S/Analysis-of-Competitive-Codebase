#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[500005];
ll brr[500005];

vector<ll>v;
vector<ll>v1;

map<ll,ll>mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,n,m,t;

    cin>>t;

    for(ll cz=1;cz<=t;cz++){
        cin>>n;

        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);

        for(i=n-1,j=1;i>=0;i--){
            if(arr[i]<j) break;
            j++;
        }
        cout<<j-1<<endl;
    }
}
