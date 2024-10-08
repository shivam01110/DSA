#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            build(data, leftChild, start, mid);
            build(data, rightChild, mid + 1, end);
            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INT_MIN;  // Return a very small value for out-of-bounds
        }

        if (L <= start && end <= R) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        int leftResult = query(leftChild, start, mid, L, R);
        int rightResult = query(rightChild, mid + 1, end, L, R);
        return max(leftResult, rightResult);
    }
};

vector<int> maxXORQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> prefixXOR(n + 1, 0);

    // Compute the prefix XOR array
    for (int i = 1; i <= n; ++i) {
        prefixXOR[i] = prefixXOR[i - 1] ^ nums[i - 1];
    }

    // Build the Segment Tree on the prefixXOR array
    SegmentTree segTree(prefixXOR);

    vector<int> results;

    for (const auto& query : queries) {
        int l = query[0];
        int r = query[1];

        int maxXOR = INT_MIN;
        for (int i = l; i <= r; ++i) {
            for (int j = i; j <= r; ++j) {
                // XOR of subarray nums[i...j]
                int currentXOR = prefixXOR[j + 1] ^ prefixXOR[i];
                maxXOR = max(maxXOR, currentXOR);
            }
        }

        results.push_back(maxXOR);
    }

    return results;
}




int main() {
    vector<int> nums = {2,8,4,32,16,1};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {0,5}};
    
    vector<int> result = maxXORQueries(nums, queries);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
