#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e7))
#define MAX_X ((int)(1e6 + 2))
#define pi (2.0*acos(0))
#define M ((ll)(1e9 + 7))
#define NN ((ll)(305))
#define N ((int)(1e6 + 5))
#define eps (0)
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;


typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;

vector < int > row[305];

bool vis[90005];

int main()
{
    int n;
    cin>>n;
    bool flag = 1;
    int r = 1;
    for(int i = 1; i<=n; i++){
        if(flag){
            int cnt = n;
            for(int j = n*n; j>0 && cnt>0; j--){
                if(vis[j]) continue;
                cnt--;

                vis[j] = 1;
                row[r].push_back(j);
                r++;
                if(r>n) r = 1;
            }
        }
        else{
            int cnt = n;
            for(int j = 1; j<=n*n && cnt>0; j++){
                if(vis[j]) continue;
                cnt--;
                vis[j] = 1;
                row[r].push_back(j);
                r++;
                if(r>n) r = 1;
            }
        }

        flag = !flag;
    }
    for(int i = 1; i<=n; i++){
        for(int a:row[i]) printf("%d ",a);
        printf("\n");
    }
    return 0;
}
