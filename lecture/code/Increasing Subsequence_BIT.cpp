// Problem: Increasing Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1145/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Fenwick_Tree {
	int arr[MAXN];
	
	void init() {
		for (int i = 0; i < MAXN; i++)
			arr[i] = 0;
	}
	
	void update(int i, int val) {
		for (; i < MAXN; i += lowbit(i))
			cmax(arr[i], val);
	}
	
	int query(int i) {
		int res = 0;
		for (; i; i -= lowbit(i))
			cmax(res, arr[i]);
		return res;
	}
} BIT;

void sol() {
	cin >> n;
	vector<int> v;
	BIT.init();
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		v.pb(x[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 0; i < n; i++)
		x[i] = upper_bound(all(v), x[i]) - v.begin();
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = BIT.query(x[i] - 1) + 1;
		cmax(ans, tmp);
		BIT.update(x[i], tmp);
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