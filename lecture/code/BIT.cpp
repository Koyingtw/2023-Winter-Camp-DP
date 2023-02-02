#define MAXN 2000005
#define lowbit (x & (-x))

struct Fenwick_Tree {
    int arr[MAXN];

    void init() {
        memset(arr, 0, sizeof(arr));
    }

    void update(int i, int val) {
        for (; i < MAXN; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += arr[i];
        return res;
    }
} BIT;