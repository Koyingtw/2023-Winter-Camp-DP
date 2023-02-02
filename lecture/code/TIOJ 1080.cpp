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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[MAXN], BIT[MAXN];

void update(int i, int val) {
	while (i < MAXN) {
		BIT[i] += val;
		i += lowbit(i);
	}
	return;
}

int query(int i) {
	int sum = 0;
	while (i) {
		sum += BIT[i];
		i -= lowbit(i);
	}
	return sum;
}

int Case = 0;

void sol() {
	MEM(BIT, 0);
	vector<int> v;
	Case++;
	cout << "Case #" << Case << ": ";
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		v.pb(x[i]);
	}
	
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(all(v), x[i]) - v.begin() + 1;
		ans += query(MAXN) - query(x[i]);
		update(x[i], 1);
	}
	cout << ans << endl;
}

signed main() {
    Weakoying;
    // int t = INF;
    while (cin >> n && n)
	{
    	// while (t--) {
            sol();
        // }
    }
        
    return 0;
}