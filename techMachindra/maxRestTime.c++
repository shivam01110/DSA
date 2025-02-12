#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int currentDist = top.first;
        int currentNode = top.second;
        if (currentDist > dist[currentNode]) continue;
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int nextNode = graph[currentNode][i].first;
            int weight = graph[currentNode][i].second;
            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int cityA, cityB, timeC;
        cin >> cityA >> cityB >> timeC;
        graph[cityA].push_back(make_pair(cityB, timeC));
        graph[cityB].push_back(make_pair(cityA, timeC));
    }
    int Q;
    cin >> Q;
    vector<pair<int, int>> deliveries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> deliveries[i].first >> deliveries[i].second;
    }
    // Compute shortest distances from city 1
    vector<int> shortestDist = dijkstra(1, N, graph);
    for (int i = 0; i < deliveries.size(); i++) {
        int cityX = deliveries[i].first;
        int timeK = deliveries[i].second;
        if (shortestDist[cityX] == INF) {
            // City is unreachable
            cout << 0 <<" ";
            continue;
        }
        int roundTripTime = 2 * shortestDist[cityX];
        if (roundTripTime <= timeK) {
            cout << timeK - roundTripTime <<" ";
        } else {
            cout << 0 <<" ";
        }
    }
    cout<<endl;
    return 0;
}

// 4
// 0 1 5 -1 -1
// 1 0 15 8 -1
// 5 15 0 -1 4
// -1 8 -1 0 6
// -1 -1 4 6 0
// 2
// 5 4 3
// 6 5 1