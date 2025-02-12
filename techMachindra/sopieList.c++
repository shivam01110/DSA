#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTree {
    int size;
    vector<long long> sums;  // Segment tree to store sums
    vector<long long> lazyAdd; // Lazy array for range addition
    vector<long long> lazySet; // Lazy array for range set operations
    vector<bool> isSet;       // Marks if a range is pending for set operation

    void init(int n) {
        size = n;
        sums.assign(4 * n, 0);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        isSet.assign(4 * n, false);
    }

    void applySet(int x, int lx, int rx, long long val) {
        sums[x] = (val * (rx - lx + 1)) % MOD;
        lazySet[x] = val;
        lazyAdd[x] = 0;
        isSet[x] = true;
    }

    void applyAdd(int x, int lx, int rx, long long val) {
        if (isSet[x]) applySet(x, lx, rx, lazySet[x]);
        sums[x] = (sums[x] + val * (rx - lx + 1)) % MOD;
        lazyAdd[x] = (lazyAdd[x] + val) % MOD;
    }

    void propagate(int x, int lx, int rx) {
        if (rx == lx) return; // No need to propagate for a leaf node
        int mid = (lx + rx) / 2;
        if (isSet[x]) {
            applySet(2 * x + 1, lx, mid, lazySet[x]);
            applySet(2 * x + 2, mid + 1, rx, lazySet[x]);
            isSet[x] = false;
        }
        if (lazyAdd[x] != 0) {
            applyAdd(2 * x + 1, lx, mid, lazyAdd[x]);
            applyAdd(2 * x + 2, mid + 1, rx, lazyAdd[x]);
            lazyAdd[x] = 0;
        }
    }

    void rangeUpdate(int x, int lx, int rx, int l, int r, long long val, bool isSetOp) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {
            if (isSetOp)
                applySet(x, lx, rx, val);
            else
                applyAdd(x, lx, rx, val);
            return;
        }
        propagate(x, lx, rx);
        int mid = (lx + rx) / 2;
        rangeUpdate(2 * x + 1, lx, mid, l, r, val, isSetOp);
        rangeUpdate(2 * x + 2, mid + 1, rx, l, r, val, isSetOp);
        sums[x] = (sums[2 * x + 1] + sums[2 * x + 2]) % MOD;
    }

    long long rangeQuery(int x, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) return 0;
        if (lx >= l && rx <= r) return sums[x];
        propagate(x, lx, rx);
        int mid = (lx + rx) / 2;
        long long leftSum = rangeQuery(2 * x + 1, lx, mid, l, r);
        long long rightSum = rangeQuery(2 * x + 2, mid + 1, rx, l, r);
        return (leftSum + rightSum) % MOD;
    }

    void build(vector<int>& nums, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < nums.size())
                sums[x] = nums[lx] % MOD;
            return;
        }
        int mid = (lx + rx) / 2;
        build(nums, 2 * x + 1, lx, mid);
        build(nums, 2 * x + 2, mid + 1, rx);
        sums[x] = (sums[2 * x + 1] + sums[2 * x + 2]) % MOD;
    }

    void build(vector<int>& nums) {
        build(nums, 0, 0, size - 1);
    }

    void update(int l, int r, long long val, bool isSetOp) {
        rangeUpdate(0, 0, size - 1, l, r, val, isSetOp);
    }

    long long query(int l, int r) {
        return rangeQuery(0, 0, size - 1, l, r);
    }
};

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    SegmentTree segTree;
    segTree.init(N);
    segTree.build(nums);

    for (int i = 0; i < P; i++) {
        int op, X, Y, V;
        cin >> op >> X >> Y >> V;
        X--; Y--; // Convert to 0-based indexing
        if (op == 1) {
            segTree.update(X, Y, V, false);
        } else if (op == 2) {
            segTree.update(X, Y, -V, false);
        } else if (op == 3) {
            segTree.update(X, Y, V, true);
        } else if (op == 4) {
            long long rangeSum = segTree.query(X, Y);
            segTree.update(0, N - 1, rangeSum, false);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl;

    return 0;
}
