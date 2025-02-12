#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0, n = arr.size(), res = INT_MAX; // Initialize pointers and result variable
        int s = 0, maxi = INT_MIN;               // `s` to find the left sorted portion, `maxi` to track max value
        // Find the length of the left sorted subarray
        while (s < n && arr[s] >= maxi) {
            maxi = arr[s]; // Update `maxi` to current element
            s++;
        }
        // If the entire array is already sorted, no removal is needed
        if (s == n) return 0;
        // Update result with the number of elements to be removed from the end
        res = min(res, n - s);
        int e = n - 1, mini = INT_MAX; // `e` to find the right sorted portion, `mini` to track min value
        // Find the length of the right sorted subarray
        while (e >= 0 && arr[e] <= mini) {
            mini = arr[e]; // Update `mini` to current element
            e--;
        }
        // Update result with the number of elements to be removed from the beginning
        res = min(res, e + 1);
        e++; // Move `e` to the starting index of the right sorted subarray
        // Check if the left and right sorted parts can be merged
        for (int i = 0; i < s; i++) {
            // Find the first index in the right part where the value is >= arr[i]
            int ind = lower_bound(arr.begin() + e, arr.end(), arr[i]) - arr.begin();
            // Update the result with the minimum number of elements to be removed
            res = min(res, ind - i - 1);
        }
        return res; // Return the minimum number of elements to remove
    }
};


int main(){
    vector<int> arr={1,2,3,10,0,7,8,9};
    cout<<*(arr.begin()+5)<<endl;
    return 0;
}