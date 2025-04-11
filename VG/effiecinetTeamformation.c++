#include<bits/stdc++.h>
using namespace std;

int countStrongTeams(string team, vector<int>& efficiencyArray, int k) {
    int n = team.size();
    unordered_set<string> uniqueTeams; // To store unique substrings
    // Loop for all starting points
    for (int i = 0; i < n; i++) {
        int weakCount = 0; // Count weak players
        string current = ""; // Current substring
        // Expanding window
        for (int j = i; j < n; j++) {
            current += team[j];
            if (efficiencyArray[team[j] - 'a'] == 0) weakCount++; // Check weak player
            if (weakCount > k) break; // If weak players exceed k, break
            uniqueTeams.insert(current); // Store substring
        }
    }
    return uniqueTeams.size();
}

int main() {
    string team = "stream";
    vector<int> efficiencyArray = {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 2;
    int result = countStrongTeams(team, efficiencyArray, k);
    cout << result << endl; // Output should be 5
    return 0;
}