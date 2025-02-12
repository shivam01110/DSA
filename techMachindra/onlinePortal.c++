#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum path traversal
int findMinPath(vector<vector<int>> &matrix, int n) {
    vector<bool> visited(n + 1, false);
    int pathSum = 0, currentNode = 0;
    visited[currentNode] = true;

    for (int step = 1; step < n + 1; step++) {
        int minCost = INT_MAX, nextNode = -1;

        // Find the minimum cost edge from the current node
        for (int j = 0; j <= n; j++) {
            if (!visited[j] && matrix[currentNode][j] != -1 && matrix[currentNode][j] < minCost) {
                minCost = matrix[currentNode][j];
                nextNode = j;
            }
        }

        if (nextNode == -1) break; // If no valid node is found
        pathSum += minCost;
        visited[nextNode] = true;
        currentNode = nextNode;
    }

    return pathSum;
}

// Function to calculate the minimum cost to new nodes
int findNewNodeCost(vector<vector<int>> &matrix, int n, int newNode, int connectedNode, int weight) {
    matrix.resize(n + 2, vector<int>(n + 2, -1)); // Resize for the new node
    for (int i = 0; i <= n; i++) {
        matrix[i].push_back(-1); // Add a column
    }
    matrix[newNode][connectedNode] = weight;
    matrix[connectedNode][newNode] = weight;
    return weight; 
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    int initialPathSum = findMinPath(matrix, n);
    int m;
    cin >> m;

    int totalNewNodeSum = 0;
    for (int i = 0; i < m; i++) {
        int newNode, connectedNode, weight;
        cin >> newNode >> connectedNode >> weight;
        totalNewNodeSum += findNewNodeCost(matrix, n, newNode - 1, connectedNode - 1, weight);
        n++;
    }
    cout << initialPathSum << " " << initialPathSum + totalNewNodeSum << endl;
    return 0;
}