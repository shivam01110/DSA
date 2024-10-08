#include <bits/stdc++.h>
using namespace std;

int teamform(int n, std::vector<int>& score, int team, int m) {
    int teamnum = 0;
    int start = 0;
    int end = n - 1;

    // Priority queues for max-heaps (using min-heaps with negative values)
    std::priority_queue<int,vector<int>,greater<int>> fheap;  // For the front side
    std::priority_queue<int,vector<int>,greater<int>> lheap;  // For the last side

    // Initialize heaps with scores
    for (int i = 0; i < m; i++) {
        if (start == end) {
            fheap.push(-score[start]);
            start++;
            break;
        }A
        fheap.push(-score[start]);
        start++;
        lheap.push(-score[end]);
        end--;
        if (start > end) {
            break;
        }
    }

    // Process the team formation
    while (team != 0) {
        int popside = 0;
        if (!lheap.empty() && (fheap.empty() || lheap.top() < fheap.top())) {
            teamnum += lheap.top();
            lheap.pop();
            popside = 1;
        } else {
            teamnum += fheap.top();
            fheap.pop();
        }
        if (start <= end) {
            if (popside == 0) {
                fheap.push(-score[start]);
                start++;
            } else {
                lheap.push(-score[end]);
                end--;
            }
        }
        team--;
    }
    return -teamnum;
}

int main() {
    // Example usage
    std::vector<int> scores = {6,18,8,14,10,12,18,9};
    int n = scores.size();
    int team = 8;
    int m = 3;

    int result = teamform(n, scores, team, m);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

