#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MOD = 1000000007;

// Precompute all possible powers of two up to the maximum XOR value
unordered_set<int> getPowersOfTwo() {
    unordered_set<int> powers;
    for (int i = 0; i < 21; ++i) {
        powers.insert(1 << i);
    }
    return powers;
}

// DFS function to compute number of ways to terminal nodes
void dfs(int node, const vector<vector<int>>& tree, const vector<int>& A, vector<int>& dp, const unordered_set<int>& powers) {
    // Initialize DP value for current node
    dp[node] = 1;

    for (int child : tree[node]) {
        dfs(child, tree, A, dp, powers);
        dp[node] = (dp[node] + dp[child]) % MOD;
    }
}

// Function to count ways to terminal nodes
int countWaysToTerminalNode(int n, vector<int> parent, vector<int> A) {
    // Adjust for 1-based indexing
    A.insert(A.begin(), 0);
    parent.insert(parent.begin(), 0);

    // Create the tree adjacency list
    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; ++i) {
        tree[parent[i]].push_back(i);
    }

    // Prepare DP array and set of powers of two
    vector<int> dp(n + 1, 0);
    unordered_set<int> powers = getPowersOfTwo();

    // Compute DP values using DFS
    dfs(1, tree, A, dp, powers);

    // Count the number of ways to terminal nodes
    int result = 0;
    for (int node = 1; node <= n; ++node) {
        if (tree[node].empty()) { // Terminal node
            result = (result + dp[node]) % MOD;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1), A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
    }

    int result = countWaysToTerminalNode(n, parent, A);
    cout << result << endl;

    return 0;
}
