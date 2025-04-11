#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(unordered_map<string,int> m,string curr){
        int possible=0,len=0;
        if(m[curr]>0){
            m[curr]-=1;
            len++;
        }
        while (1){
            if(curr=="RG"){
                if(m["GG"]>0){
                    curr="GG";
                    len+=m[curr];
                    m[curr]=0;
                }else if(m["GR"]>0){
                    curr="GR";
                    len+=1;
                    m[curr]-=1;
                }else{
                    return len;
                }
            }
            else if(curr=="GR"){
                if(m["RR"]>0){
                    curr="RR";
                    len+=m[curr];
                    m[curr]=0;
                }else if(m["RG"]>0){
                    curr="RG";
                    len+=1;
                    m[curr]-=1;
                }else{
                    return len;
                }
            }
            else if(curr=="GG"){
                if(m["GG"]>0){
                    curr="GG";
                    len+=m[curr];
                    m[curr]=0;
                }else if(m["GR"]>0){
                    curr="GR";
                    len+=1;
                    m[curr]-=1;
                }else{
                    return len;
                }
            }
            else{
                if(m["RR"]>0){
                    curr="RR";
                    len+=m[curr];
                    m[curr]=0;
                }else if(m["RG"]>0){
                    curr="RG";
                    len+=1;
                    m[curr]-=1;
                }else{
                    return len;
                }
            }
        }
        return len;
    }

    int solution(vector<string>& v){
        unordered_map<string,int> m;
        for(auto s:v){
            m[s]++;
        }
        int len=0;
        len=max(len,solve(m,"RG"));
        len=max(len,solve(m,"GR"));
        len=max(len,solve(m,"GG"));
        len=max(len,solve(m,"RR"));
        return len;
    }
};


int main(){
    int n;
    cin>>n;
    Solution sol;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<sol.solution(v)<<endl;
    return 0;
}