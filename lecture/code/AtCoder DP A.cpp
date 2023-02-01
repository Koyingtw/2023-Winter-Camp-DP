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
/******************************************************************************/

#define MAXN 100005

int x[MAXN], dp[MAXN];

void sol()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    dp[0] = 0;
    dp[1] = abs(x[1] - x[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 2] + abs(x[i - 2] - x[i]), dp[i - 1] + abs(x[i] - x[i - 1]));
    }
    cout << dp[n - 1] << endl;
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