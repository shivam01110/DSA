#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Function to calculate basic operations
ll Cal(char op, ll a, ll b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;  // Multiplication
}

// Function to correctly evaluate expression with correct precedence
ll correct(vector<ll> nums,vector<char> op){
    vector<ll> cal;
    vector<char> ops;
    int l=op.size();
    int i=0;
    cal.push_back(nums[i]);
    i++;
    for(int j=0;j<l;j++){
        if(op[j]=='*'){
            ll a=cal.back();
            cal.pop_back();
            cal.push_back(a*nums[i]);
        }
        else{
            cal.push_back(nums[i]);
            ops.push_back(op[j]);
        }
        i++;
    }
    ll res=cal[0];
    for(int j=0;j<ops.size();j++){
        res=Cal(ops[j],res,cal[j+1]);
    }    
    return res;
}



// Function to solve the expression by computing all possible results
void solve(string& exp) {
    vector<ll> nums;
    vector<char> ops;
    
    int l = 0, len = exp.length();
    for (int i = 0; i < len; i++) {
        if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-') {
            nums.push_back(stoll(exp.substr(l, i - l)));  // Extract number
            ops.push_back(exp[i]);  // Store operator
            l = i + 1;
        }
    }
    nums.push_back(stoll(exp.substr(l)));  // Last number

    int n = nums.size();
    vector<vector<set<ll>>> dp(n, vector<set<ll>>(n));

    // Initialize base cases (single numbers)
    for (int i = 0; i < n; i++) {
        dp[i][i].insert(nums[i]);
    }

    // Fill DP table
    for (int len = 2; len <= n; len++) {  // Segment length
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {  // Partitioning point
                for (ll left : dp[i][k]) {
                    for (ll right : dp[k + 1][j]) {
                        dp[i][j].insert(Cal(ops[k], left, right));
                    }
                }
            }
        }
    }

    // Output all possible results in sorted order
    for (ll res : dp[0][n - 1]) {
        cout << res << " ";
    }
    cout << endl;
    cout<<"correct---->"<<correct(nums,ops)<<endl;
}

int main() {
    string exp;
    getline(cin, exp);
    solve(exp);
    return 0;
}
