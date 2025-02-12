#include <bits/stdc++.h>
using namespace std;

// Function to calculate subinterval overlaps

class Solution {
public:
    vector<int> countOverlaps(vector<vector<int>>& queries,int n) {
        // Map to store the count of overlaps for each distinct interval
        map<pair<int, int>, int> intervalCount;
        // Process each query and its subintervals
        for (auto& query : queries) {
            int start = query[0], end = query[1];
            if (start == end) {
                intervalCount[{start, end}] += 2;
            } else {
                // Otherwise, count subintervals
                for (int i = start; i < end; i++) {
                    intervalCount[{i, i+1}]++;
                }
            }
        }
        // Print the count of overlaps for each distinct subinterval
        vector<int> freq(n,0);
        for (auto& entry : intervalCount) {
            cout << "[" << entry.first.first << ", " << entry.first.second << "] : " << entry.second << " overlaps" << endl;
            for(int i=entry.first.first;i<=entry.first.second;i++){
                freq[i]=max(freq[i],entry.second);
            }
        }
        // return freq;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> freq=countOverlaps(queries,n);
        for(int i=0;i<n;i++){
            if(nums[i]-freq[i]>0) return false;
        }
        return true;
    }
};


int main() {
    // Input: list of querie
    Solution sol;
    vector<vector<int>> queries = {{0,0},{0,0}};
    
    // Get the subinterval overlaps
    // vector<pair<pair<int, int>, int>> result = sol.countSubintervalOverlaps(queries,0);
    sol.countOverlaps(queries,9);
    // Print the results
    // cout << "Subinterval Overlaps:\n";
    // for (auto& res : result) {
    //     cout << "[" << res.first.first << ", " << res.first.second << "]: " << res.second << " overlaps\n";
    // }

    return 0;
}

