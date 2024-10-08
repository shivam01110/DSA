#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxFantasticFours(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> positions;

    // Store indices of each element in the array
    for (int i = 0; i < n; ++i) {
        positions[arr[i]].push_back(i);
    }

    vector<pair<int, int>> pairs;  // pairs of (start, end)
    
    // Generate all possible pairs (i, k) where i < k for each element
    for (unordered_map<int, vector<int>>::iterator it = positions.begin(); it != positions.end(); ++it) {
        int value = it->first;
        vector<int>& indices = it->second;
        
        int size = indices.size();
        if (size < 2) continue; // Need at least two occurrences

        for (int i = 0; i < size - 1; ++i) {
            for (int k = i + 1; k < size; ++k) {
                pairs.emplace_back(indices[i], indices[k]);
            }
        }
    }

    // Sort pairs by the end index to use in DP
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // DP array where dp[i] is the max number of non-overlapping fantastic fours ending at index i
    vector<int> dp(n, 0);
    int maxFours = 0;
    
    for (const pair<int, int>& p : pairs) {
        int start1 = p.first;
        int end1 = p.second;
        
        int bestBefore = 0;
        
        // Find the best dp value for pairs ending before the current start1
        for (int i = 0; i < start1; ++i) {
            bestBefore = max(bestBefore, dp[i]);
        }
        
        // Update dp for the current end1
        dp[end1] = max(dp[end1], bestBefore + 1);
        maxFours = max(maxFours, dp[end1]);
    }

    return maxFours;
}

int main() {
    vector<int> arr = {5, 1, 5, 1, 5, 2, 2, 2, 2, 2, 4, 4, 9, 4, 9}; // Provided input
    cout << "Maximum number of fantastic fours: " << maxFantasticFours(arr) << endl;
    return 0;
}
