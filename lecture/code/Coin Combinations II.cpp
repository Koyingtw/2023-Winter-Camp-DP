// Problem: Coin Combinations II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1636
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int dp[MAXN];
int x[105];
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x + n);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = x[i]; j <= m; j++)
		{
			dp[j] += dp[j - x[i]];
			dp[j] %= P;
		}
	}
	put(dp[m]);
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}