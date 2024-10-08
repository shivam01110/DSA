#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int solution(vector<int> &a, vector<int> &b) {
    // Implement your solution here
    int len1=a.size(),len2=b.size();
    vector<vll> dp(2,vll(len1,0));
    dp[0][0]=a[0];
    dp[1][0]=max(a[0],b[0]);
    for(int i=1;i<len1;i++){
        dp[0][i]=max((int)dp[0][i-1],a[i]);
        dp[1][i]=min(max((int)dp[0][i],b[i]),max((int)dp[1][i-1],b[i]));
    }
    return dp[1][len1-1];
}

int main(){
    vector<int> a={-5,-1,-3};
    vector<int> b={-5,5,-2};
    cout<<solution(a,b)<<endl;
    return 0;
}
