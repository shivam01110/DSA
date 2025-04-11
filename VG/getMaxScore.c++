#include <bits/stdc++.h>
using namespace std;

int getMaxScore(vector<int>& A) {
    int n = A.size();
    sort(A.rbegin(), A.rend()); // Sort in descending order

    priority_queue<int> pq;
    pq.push(A[0]); // Initialize B with the first element
    int score = 0;

    for (int i = 1; i < n; i++) {
        int bestGCD = 0;
        vector<int> temp; // Store used elements

        // Find the best GCD using elements in priority queue
        for (int j = 0; j < min(30, (int)pq.size()); j++) { // Limit to 30 for efficiency
            int top = pq.top();
            pq.pop();
            temp.push_back(top);
            bestGCD = max(bestGCD, __gcd(A[i], top));
        }

        // Restore priority queue
        for (int num : temp) pq.push(num);
        
        // Add the best GCD to score
        score += bestGCD;
        pq.push(A[i]); // Add to B
    }

    return score;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << getMaxScore(A) << endl;
    return 0;
}
