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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1005
#define MAXM 85 
int n, m, root;
int dp[MAXN][MAXM][5];
vector<int> G[MAXN];
string s[MAXN];

map<char, int> mp = {
    {'A', 0}, 
    {'U', 1},
    {'C', 2},
    {'G', 3},
    {'@', 4}
};

void dfs(int i) {
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
            if (mp[s[i][j]] == 4 || mp[s[i][j]] == k)
                dp[i][j][k] = 0;
            else
                dp[i][j][k] = INF;
        }
    }
    for (int e: G[i]) {
        dfs(e);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int mn = INF;
                for (int l = 0; l < 4; l++) {
                    cmin(mn, dp[e][j][l] + (k != l));
                }
                dp[i][j][k] += mn;
            }
        }
    }
}

void sol() {
    cin >> n >> m;
    MEM(dp, 0x3f);

    for (int i = 1, a, p; i <= n; i++) {
        cin >> a >> p;
        cin >> s[a];
        if (a == p) {
            root = a;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++)
                    dp[a][j][k] = 0;
            }
        }
        else {
            G[p].pb(a);
        }
    }

    dfs(root);

    int ans = 0;


    for (int i = 0; i < m; i++) {
        int mn = INF;
        for (int j = 0; j < 4; j++)
            cmin(mn, dp[root][i][j]);
        ans += mn;
    }
    cout << ans << endl;
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