#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

// Function to calculate the Nval using Prim's Algorithm
int calculateNval(int stands, int aisles, vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(stands + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1}); // Start from the first stand
    int nval = 0;

    while (!pq.empty()) {
        pair<int, int> top= pq.top();
        pq.pop();
        int weight = top.first; // The weight of the edge
        int node = top.second;
        if (visited[node]) continue;

        visited[node] = true;
        nval += weight;

        for (auto& neighbor : graph[node]) {
            if (!visited[neighbor.first]) {
                pq.push({neighbor.second, neighbor.first});
            }
        }
    }

    return nval;
}

int main() {
    int N, threshold;
    cin >> N >> threshold;  // Number of zones and the threshold
    
    int zoneWithFault = -1;
    int faultNval = INT_MIN;
    vector<vector<int>> stands(N,vector<int>(2,0));
    for (int i = 0; i < N; i++) {
        cin>>stands[i][0];  //stands
        cin>>stands[i][1];  //aisles
    }
    for (int i = 0; i <N; i++) {
        vector<vector<pair<int, int>>> graph(stands[i][0] + 1);
        for(int j=0;j<stands[i][1];j++){
            int first, second, len;
            cin >> first >> second >> len;
            graph[first].push_back({second, len});
            graph[second].push_back({first, len});
        }
        int nval = calculateNval(stands[i][0], stands[i][1], graph);
    }
    // Sort zones based on Nval in descending order
    sort(stands.rbegin(), stands.rend());

    // Output the zone index and its Nval
    cout << stands[threshold - 1][1]<< " " << stands[threshold - 1][0] << endl;

    return 0;
}
