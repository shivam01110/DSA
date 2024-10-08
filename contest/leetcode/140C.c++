#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void conversion(int i, int j, string& w1, string& w2, int change, vector<int>& temp, vector<int>& best) {
        if (i >= w1.length()) {
            // We've matched all characters in word1, update the best sequence if temp is smaller
            if (best.empty() || temp < best) {
                best = temp;
            }
            return;
        }
        if (j >= w2.length()) return; // No more characters in word2 to match
        
        // Matching characters case
        if (w1[i] == w2[j]) {
            temp.push_back(j);
            conversion(i + 1, j + 1, w1, w2, change, temp, best);
            temp.pop_back(); // Backtrack
        } else {
            // Case 1: Change the character, decrement the change count
            if (change > 0) {
                temp.push_back(j);
                conversion(i + 1, j + 1, w1, w2, change - 1, temp, best);
                temp.pop_back(); // Backtrack
            }
            // Case 2: Skip the current position in word2
            conversion(i, j + 1, w1, w2, change, temp, best);
        }
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        vector<int> temp, best;
        
        // Calculate frequency of each character in both words
        for (char c : word1) f1[c - 'a']++;
        for (char c : word2) f2[c - 'a']++;
        
        // Check if the difference in characters is more than 1
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += (f2[i] - min(f2[i], f1[i]));
            if (cnt > 1) return {}; // If more than 1 difference, no valid sequence
        }
        
        // Start the conversion process
        conversion(0, 0, word2, word1, 1, temp, best);
        
        return best;
    }

};