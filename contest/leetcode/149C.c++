#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        map<int, int> freeslot; // Stores different free time durations and their frequency
        
        // Adding the first available free slot before the first event starts
        freeslot[startTime[0]] = 1;

        // Adding the last available free slot after the last event ends
        int lastSlot = eventTime - endTime[n - 1];
        freeslot[lastSlot] = 1;

        // Initialize `ans` to the maximum of the first and last free slots
        int ans = max(startTime[0], lastSlot);

        // Calculate free time gaps between consecutive events
        for (int i = 0; i < n - 1; i++) {
            int diff = startTime[i + 1] - endTime[i];
            freeslot[diff] += 1;
        }

        // Store the size of distinct free slots
        int freeslotSize = freeslot.size();

        // Arrays to store free time durations and their prefix sums
        vector<int> freeTime(freeslotSize, 0);
        vector<int> prefix(freeslotSize, 0);

        int p = freeslotSize - 1; // Pointer to fill arrays from back
        int tot = 0;

        // Iterate over the free slots in decreasing order and compute prefix sums
        for (auto it = freeslot.rbegin(); it != freeslot.rend(); it++) {
            tot += it->second;  // Cumulative frequency of free slots
            freeTime[p] = it->first;  // Store free time duration
            prefix[p] = tot;  // Store cumulative frequency
            p -= 1;
        }

        // Iterate over all events to determine maximum possible free time
        for (int i = 0; i < n; i++) {
            int curr = endTime[i] - startTime[i];  // Current event duration
            int left = 0, right = 0;

            // Compute free time before and after the current event
            if (i == 0) { // First event
                left = startTime[i];
                right = startTime[i + 1] - endTime[i];
            } 
            else if (i == n - 1) { // Last event
                left = startTime[i] - endTime[i - 1];
                right = eventTime - endTime[i];
            } 
            else { // Middle events
                left = startTime[i] - endTime[i - 1];
                right = startTime[i + 1] - endTime[i];
            }

            // Update the maximum free time without including `curr`
            ans = max(ans, left + right);

            // Find the first free time >= `curr`
            int ind = lower_bound(freeTime.begin(), freeTime.end(), curr) - freeTime.begin();
            
            // If no valid free time is found, continue to the next event
            if (ind >= freeslotSize) continue;

            int slot = prefix[ind];  // Get the total number of free slots available

            // If left or right free time is greater than or equal to `curr`, decrement slot count
            if (left >= curr) slot--;
            if (right >= curr) slot--;

            // If there is still a valid slot available, update `ans`
            if (slot > 0) ans = max(ans, left + right + curr);
        }
        
        return ans;
    }
};
