#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to calculate the maximal score difference
int calculate_score_difference(const vector<string>& strings, int n, int m) {
    int count_n = 0, count_a = 0, count_r = 0, count_e = 0, count_k = 0;

    // Count occurrences of 'n', 'a', 'r', 'e', and 'k'
    for (const string& s : strings) {
        for (char c : s) {
            if (c == 'n') count_n++;
            else if (c == 'a') count_a++;
            else if (c == 'r') count_r++;
            else if (c == 'e') count_e++;
            else if (c == 'k') count_k++;
        }
    }

    // The number of complete "narek" sequences Narek can form
    int scoren = min({count_n, count_a, count_r, count_e, count_k}) * 5;

    // Remaining letters contribute to ChatGPT's score
    int scorec = (count_n + count_a + count_r + count_e + count_k) - scoren;

    // Return the difference scoren - scorec
    return scoren - scorec;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> strings(n);
        for (int i = 0; i < n; i++) {
            cin >> strings[i];
        }

        // Calculate the maximal possible value of scoren - scorec
        int result = calculate_score_difference(strings, n, m);

        // Output the result for this test case
        cout << result << endl;
    }

    return 0;
}
