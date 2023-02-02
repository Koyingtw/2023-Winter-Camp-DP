#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

#define MAXN 3005
int dp[MAXN][MAXN];
int state[MAXN][MAXN];

void sol()
{
    string a, b;
	cin >> a >> b;
    
    int n = a.size(), m = b.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                state[i + 1][j + 1] = 0;
            }
            else {
                int ouo = max(dp[i][j + 1], dp[i + 1][j]);
                dp[i + 1][j + 1] = ouo;
                if (dp[i + 1][j] == ouo)
                    state[i + 1][j + 1] = 2;
                else
                    state[i + 1][j + 1] = 1;
            }
        }
    }
    
    int cnt = dp[n][m];
    stack<char> ans;
    
    int x = n, y = m;
    while (dp[x][y]) {
        if (a[x - 1] == b[y - 1]) {
            ans.push(a[x - 1]);
            x--, y--;
        }
        else if (state[x][y] == 0) {
            x--, y--;
        }
        else if (state[x][y] == 1) {
            x--;
        }
        else
            y--;
    }
    while (ans.size()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}