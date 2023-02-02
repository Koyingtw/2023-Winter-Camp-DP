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
const int INF = 0x3f3f3f3f3f3f3f;
const int P = 1e9+7;
 
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 200005 
int n, m;
int dis[MAXN], pre[MAXN], in[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;
 
void sol() {
	cin >> n >> m;
	int a, b;
	while(m--) {
		cin >> a >> b;
		G[a].pb(b);
		in[b]++;
	}	
	pre[1] = 1;
	queue<int> q;
	for(int i = 1; i <= n; i++) if(!in[i]) q.push(i);
	for(int i = 2; i <= n; i++) dis[i] = -INF;
	while(q.size()) {
		int now = q.front();
		q.pop();
		for(int e: G[now])
		{
			if(dis[e] < dis[now] + 1)
			{
				dis[e] = dis[now] + 1;
				pre[e] = now;
			}
			in[e]--;
			if(!in[e]) q.push(e);
		}
	}
	if(dis[n] < 0) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << dis[n] + 1 << endl;
	stack<int> ans;
	int tmp = n;
	while(tmp != 1) {
		ans.push(tmp);
		tmp = pre[tmp];
	}
	cout << 1 << " ";
	while(ans.size()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << endl;
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