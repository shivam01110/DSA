#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int n, vector<vector<int>> roads, vector<int> thieves, int k, int start, int end) {
    // Build adjacency list for the graph
    vector<vector<int>> graph(n);
    for (auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    // Mark unsafe cities
    vector<bool> unsafe(n, false);
    
    queue<pair<int, int>> q; // {city, distance}
    for (int thief : thieves) {
        q.push(make_pair(thief, 0));
        unsafe[thief] = true;
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int city = p.first, dist = p.second;
        if (dist >= k) continue;

        for (int neighbor : graph[city]) {
            if (!unsafe[neighbor]) {
                unsafe[neighbor] = true;
                q.push(make_pair(neighbor, dist + 1));
            }
        }
    }

    // Find the shortest safe path
    vector<bool> visited(n, false);
    queue<pair<int, int>> bfsQueue; // {city, distance}
    bfsQueue.push(make_pair(start, 0));
    visited[start] = true;

    while (!bfsQueue.empty()) {
        pair<int, int> p = bfsQueue.front();
        bfsQueue.pop();
        int city = p.first, dist = p.second;

        if (city == end) return dist;

        for (int neighbor : graph[city]) {
            if (!visited[neighbor] && !unsafe[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(make_pair(neighbor, dist + 1));
            }
        }
    }

    return -1; // If no safe path exists
}

int main() {
    int n = 9; // Number of cities
    vector<vector<int>> roads = {{0, 1}, {0,2}, {1, 3}, {1, 4}, {2, 5}, {2, 6},{4,7},{5,7},{5,8},{6,8}};
    vector<int> thieves = {1,2};
    int k = 1, start = 0, end = 8;

    cout << solution(n, roads, thieves, k, start, end) << endl;

    return 0;
}
