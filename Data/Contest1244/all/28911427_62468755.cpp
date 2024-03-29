#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
    {
        int n;
        char c;
        cin >> n;
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            if(c == '0')
                continue;
            ans = max(ans, 2 * max(n - i, i + 1));
        }
        cout << ans << endl;
    }

	return 0;
}
