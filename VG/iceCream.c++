#include <bits/stdc++.h>
using namespace std;

// C++ program to minimize the maximum difference
// between heights using Sorting

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
  
    int res = arr[n - 1] - arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - k < 0)
            continue;
        int minH = min(arr[0] + k, arr[i] - k);
        int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
        res = min(res, maxH - minH);
    }
    return res;
}

int main() {

    int k = 20;
    vector<int> arr = {3,4,5};

    int ans = getMinDiff(arr, k);
    cout << ans;

    return 0;
}
