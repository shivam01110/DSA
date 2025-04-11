#include <bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
    if (index == nums.size()) {
        if (!subset.empty()) 
            result.push_back(subset);
        return;
    }
    // Include the current element
    subset.push_back(nums[index]);
    generateSubsets(nums, index + 1, subset, result);
    // Backtrack (remove last element)
    subset.pop_back();
    generateSubsets(nums, index + 1, subset, result);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> result;
    vector<int> subset;
    generateSubsets(nums, 0, subset, result);
    reverse(result.begin(),result.end());
    for (auto& s : result) {
        for (int num : s)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
