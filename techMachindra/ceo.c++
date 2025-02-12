// #include <bits/stdc++.h>
// using namespace std;

// int findMaxPapers(int numEmp, int empldCEO, vector<int>& researchPapers, vector<pair<int, int>>& relations) {
//     vector<vector<int>> hierarchy(numEmp + 1);
//     vector<bool> isManager(numEmp + 1, false);
//     for (auto& relation : relations) {
//         int manager = relation.first;
//         int subordinate = relation.second;
//         hierarchy[manager].push_back(subordinate);
//         isManager[manager] = true;
//     }
//     vector<int> cumulativePapers(numEmp + 1, 0);
//     queue<int> q;
//     q.push(empldCEO);
//     cumulativePapers[empldCEO] = researchPapers[empldCEO - 1];
//     int maxPapers = INT_MIN;

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();
//         for (int subordinate : hierarchy[current]) {
//             cumulativePapers[subordinate] = cumulativePapers[current] + researchPapers[subordinate - 1];
//             q.push(subordinate);
//             if (!isManager[subordinate]) {
//                 maxPapers = max(maxPapers, cumulativePapers[subordinate]);
//             }
//         }
//     }
//     return maxPapers;
// }

// int main() {
//     int numEmp, empldCEO;
//     cin >> numEmp >> empldCEO;
//     vector<int> researchPapers(numEmp);
//     for (int i = 0; i < numEmp; ++i) {
//         cin >> researchPapers[i];
//     }
//     vector<pair<int, int>> relations(numEmp - 1);
//     for (int i = 0; i < numEmp - 1; ++i) {
//         cin >> relations[i].first >> relations[i].second;
//     }
//     cout << findMaxPapers(numEmp, empldCEO, researchPapers, relations) << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int findMaxPapers(int numEmp, int empldCEO, vector<int>& researchPapers, vector<pair<int, int>>& relations) {
    // Build the hierarchy adjacency list
    vector<vector<int>> hierarchy(numEmp + 1);
    vector<bool> isManager(numEmp + 1, false);
    for (size_t i = 0; i < relations.size(); i++) {
        int manager = relations[i].first;
        int subordinate = relations[i].second;
        hierarchy[manager].push_back(subordinate);
        isManager[manager] = true;
    }

    // Use BFS to calculate cumulative papers for all employees
    vector<int> cumulativePapers(numEmp + 1, 0);
    queue<int> q;
    q.push(empldCEO);
    cumulativePapers[empldCEO] = researchPapers[empldCEO - 1];

    int maxPapers = INT_MIN;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (size_t i = 0; i < hierarchy[current].size(); i++) {
            int subordinate = hierarchy[current][i];
            // Calculate cumulative papers for the subordinate
            cumulativePapers[subordinate] = cumulativePapers[current] + researchPapers[subordinate - 1];
            q.push(subordinate);

            // Check if the subordinate is not a manager (leaf node)
            if (!isManager[subordinate]) {
                maxPapers = max(maxPapers, cumulativePapers[subordinate]);
            }
        }
    }

    return maxPapers;
}

int main() {
    int numEmp, empldCEO;
    cin >> numEmp >> empldCEO;

    // Input the number of research papers for each employee
    vector<int> researchPapers(numEmp);
    for (int i = 0; i < numEmp; i++) {
        cin >> researchPapers[i];
    }

    // Input relations (manager-subordinate pairs)
    vector<pair<int, int>> relations(numEmp - 1);
    for (int i = 0; i < numEmp - 1; i++) {
        cin >> relations[i].first >> relations[i].second;
    }

    // Output the maximum number of research papers
    cout << findMaxPapers(numEmp, empldCEO, researchPapers, relations) << endl;
 
    return 0;
}


// 3 1
// -5 2 3
// 1 2
// 1 3
