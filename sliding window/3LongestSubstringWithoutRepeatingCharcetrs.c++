#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    unordered_map<char,int> m;
    int len=s.length();
    int l=0,r=0,ans=0;
    while(r<len){
        if(m[s[r]]==1){
            while (l<=r && s[r]!=s[l])
            {
                m[s[l]]--;
                l++;
            }
            m[s[l]]--;
            l++;
        }
        m[s[r]]++;
        ans=max(ans,r-l+1);
        r++;
    }
    return ans;
}

int main(){
    cout<<solve("pwwkew")<<endl;
    return 0;
}