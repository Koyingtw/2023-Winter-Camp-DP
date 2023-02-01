// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
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

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;

const int P = 1e9 + 7;
int dp[MAXN];
 
int top_down(int i) {
    if (dp[i])
        return dp[i] % P;
    if (i <= 5) {
        for (int j = 0; j < i; j++) {
            dp[i] += top_down(j);
        	dp[i] %= P;
        }
    }
    else {
        for (int j = i - 6; j < i; j++) {
            dp[i] += top_down(j);
        	dp[i] %= P;
        }
    }
    return dp[i];
}

int bottom_up() {
	for (int i = 1; i <= n; i++) {
		if (i <= 5) {
	        for (int j = 0; j < i; j++) {
	            dp[i] += dp[j];
	        	dp[i] %= P;
	        }
	    }
	    else {
	        for (int j = i - 6; j < i; j++) {
	            dp[i] += dp[j];
	        	dp[i] %= P;
	        }
	    }	
	}
	return dp[n];
}

void sol() {
	cin >> n;
	dp[0] = 1;
	cout << bottom_up() % P << endl;
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