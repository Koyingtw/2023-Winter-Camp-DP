// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 105
#define MAXM 1000005 
int n, x;
int c[MAXN], dp[MAXM];

int top_down(int i) {
    if (dp[i] < INF)
        return dp[i];
    for (int j = 0; j < n; j++) {
    	if (i - c[j] >= 0)
	        dp[i] = min(dp[i], top_down(i - c[j]) + 1);
    }
    return dp[i];
}

int bottom_up(int x) {
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - c[j] >= 0)
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	return dp[x];
}

void sol() {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> c[i];
		
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	if (bottom_up(x) < INF)
		cout << dp[x] << endl;
	else
		cout << -1 << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}