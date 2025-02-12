#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        unordered_map<string,int> m;
        long long res=0;
        for(int r=4;r<n-2;r++){
            int q=r-2;
            for(int p=0;p<q-1;p++){
                int gcd=__gcd(nums[p],nums[q]);
                string key=to_string((nums[p]/gcd))+"/"+to_string((nums[q]/gcd));
                cout<<key<<endl;
                m[key]++;
            }
            for(int s=r+2;s<n;s++){
                int gcd=__gcd(nums[r],nums[s]);
                string key=to_string((nums[s]/gcd))+"/"+to_string((nums[r]/gcd));
                res+=m[key];
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>> nums[i];
    cout<<sol.numberOfSubsequences(nums)<<endl;
    return 0;
}