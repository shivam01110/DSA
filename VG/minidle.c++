#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveLength(string &shader, int switchCount, char target) {
    int n = shader.size();
    int maxLength = 0;
    int left = 0;
    int switches = 0;

    for (int right = 0; right < n; ++right) {
        if (shader[right] != target) {
            ++switches;
        }

        while (switches > switchCount) {
            if (shader[left] != target) {
                --switches;
            }
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int findMinimumIdleness(string shader, int switchCount) {
    int maxLenA = maxConsecutiveLength(shader, switchCount, 'a');
    int maxLenB = maxConsecutiveLength(shader, switchCount, 'b');

    return shader.size() - max(maxLenA, maxLenB);
}

int main() {
    string shader = "aabbbaaaa";  // Example input
    int switchCount = 2;          // Example input
    cout << findMinimumIdleness(shader, switchCount) << endl;  // Expected output: 2
    return 0;
}
