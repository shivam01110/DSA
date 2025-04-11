#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        ll res = 0;
        sort(pizzas.begin(), pizzas.end());
        int days = pizzas.size() / 4;
        int odd = (days + 1) / 2;
        int even = days / 2;
        int i = pizzas.size() - 1;
        
        while (odd > 0) {
            res += pizzas[i];
            i--;
            odd--;
        }
        
        while (even > 0) { // Ensure i is in bounds
            res += pizzas[i-1];
            i -= 2; // Decrease by 2 safely
            even--;
        }
        
        return res;
    }
};