#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<double, double> possible(double y, vector<vector<int>>& squares) {
        double up = 0, down = 0;
        for (auto& square : squares) {
            double yi = square[1], l = square[2];
            double top = yi + l;
            if (y >= top) {
                down += l * l;
            } else if (y <= yi) {
                up += l * l;
            } else {
                double upHeight = top - y;
                double downHeight = y - yi;
                up += upHeight * l;
                down += downHeight * l;
            }
        }
        return {up, down};
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 2e9, ans = -1;
        while (high - low > 1e-6) { 
            double mid = (low + high) / 2.0;
            pair<double,double> p = possible(mid, squares);
            double up=p.first;
            double down=p.second;
            if (up - down < 1e-6) {
                ans = mid;
                high = mid; 
            } else if (up > down) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return ans;
    }
};
