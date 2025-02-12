#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxVal = 100000; // Given constraint
        vector<int> minIndex(maxVal + 1, -1);
        
        // Store the smallest index for each element
        for (int j = 0; j < elements.size(); j++) {
            if (minIndex[elements[j]] == -1) { // Store only the first occurrence
                minIndex[elements[j]] = j;
            }
        }

        vector<int> assigned(groups.size(), -1);

        // Assign elements to groups
        for (int i = 0; i < groups.size(); i++) {
            int bestIndex = -1;
            // Check all divisors of groups[i]
            for (int d = 1; d * d <= groups[i]; d++) {
                if (groups[i] % d == 0) {
                    // Check divisor d
                    if (minIndex[d] != -1) {
                        if (bestIndex == -1 || minIndex[d] < bestIndex)
                            bestIndex = minIndex[d];
                    }
                    // Check paired divisor groups[i] / d
                    int paired = groups[i] / d;
                    if (minIndex[paired] != -1) {
                        if (bestIndex == -1 || minIndex[paired] < bestIndex)
                            bestIndex = minIndex[paired];
                    }
                }
            }
            assigned[i] = bestIndex;
        }

        return assigned;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> groups = {8, 4, 3, 2, 4};
    vector<int> elements = {4, 2};
    vector<int> result = sol.assignElements(groups, elements);

    for (int r : result) cout << r << " ";
    cout << endl;
    return 0;
}
