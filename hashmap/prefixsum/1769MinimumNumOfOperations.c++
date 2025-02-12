#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> prefix(n, 0); // To store the final result: minimum operations for each box
        int balls = 0;           // Count of balls encountered so far
        int front = 0, back = 0; // Cumulative operations from left (front) and right (back)

        // Calculate operations moving from left to right
        for (int i = 0; i < n; i++) {
            prefix[i] = front;   // Store the cumulative operations to move all balls to box `i`
            balls += (boxes[i] == '1') ? 1 : 0; // Increment ball count if current box has a ball
            front += balls;     // Add current ball count to cumulative operations
        }

        balls = 0; // Reset the ball count for the reverse pass

        // Calculate operations moving from right to left
        for (int i = n - 1; i >= 0; i--) {
            prefix[i] += back;  // Add cumulative operations from the right to the result
            balls += (boxes[i] == '1') ? 1 : 0; // Increment ball count if current box has a ball
            back += balls;     // Add current ball count to cumulative operations
        }

        return prefix; // Return the final result containing minimum operations for each box
    }
};
