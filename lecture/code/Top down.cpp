int dp[MAXN];
bool caled[MAXN];

int f(int i) {
    if (i <= 1)
        return 1;
    else if (caled[i])
        return dp[i];
    else {
        caled[i] = true;
        return dp[i] = f(i - 1) + f(i - 2);
    }
}