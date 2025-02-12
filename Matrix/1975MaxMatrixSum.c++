#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int mini = INT_MAX, cnt = 0; // mini-->to store smallest absolute number ,cnt-->count negative numbers
        long long tot = 0;
        for (auto row : matrix)
        {
            for (auto element : row)
            {
                tot += abs(element);
                mini = min(mini, abs(element));
                if (element < 0)
                {
                    cnt++;
                }
            }
        }
        // IDEA: if there are even number of negative number or there is a ZERO (i.e mini=0) then every number can become non-negative simply return tot
        if (mini == 0 || cnt % 2 == 0)
            return tot;
        // if there are odd negative number then operations can be perform in such a way that in last there is only one negative number left
        // so make mini negative and rest positive
        tot = tot - 2 * mini;
        return tot;
    }
};