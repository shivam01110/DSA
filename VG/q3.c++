#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

// Function to calculate the minimum cost of swapping students to match heights
int minSwapCost(vector<int>& arrA, vector<int>& arrB) {
    // Check if total sum of heights in both lines are equal
    int sumA = accumulate(arrA.begin(), arrA.end(), 0);
    int sumB = accumulate(arrB.begin(), arrB.end(), 0);

    // If sums of heights in both lines are not equal, it's not possible to match
    if (sumA != sumB) return -1;

    int n = arrA.size();
    unordered_map<int, int> countMap;

    // Count the occurrences of each height in both arrays
    for (int i = 0; i < n; i++) {
        countMap[arrA[i]]++;
        countMap[arrB[i]]--;
    }

    // Check if both lines have the same set of heights
    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        if (it->second != 0) return -1;
    }

    // Create a sorted list of all unique heights in both lines
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());

    // Calculate the minimum cost to swap the students
    int i = 0, j = 0, cost = 0;
    while (i < n && j < n) {
        if (arrA[i] == arrB[j]) {
            i++;
            j++;
        } else if (arrA[i] < arrB[j]) {
            cost += arrA[i];
            i++;
        } else {
            cost += arrB[j];
            j++;
        }
    }

    return cost;
}