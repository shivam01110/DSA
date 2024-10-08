// [1023,2310,2130,213]
#include <bits/stdc++.h>
using namespace std;


unordered_set<string> GenerateAllCombo(int n){
    unordered_set<string> combo;
    string num=to_string(n);
    while(num.size()!=7){
        num='0'+num;
    }
    combo.insert(num);
    for(int i=0;i<num.length();i++){
        for(int j=i+1;j<num.length();j++){
            swap(num[i],num[j]);       //1st swap
            combo.insert(num);
            for(int a=0;a<num.length();a++){
                for(int b=a+1;b<num.length();b++){
                    if(num[a]!=num[b]){
                        swap(num[a],num[b]);        //2nd swap
                        combo.insert(num);
                        swap(num[a],num[b]);
                    }
                }
            }
            swap(num[i],num[j]);
        }
    }
    return combo;
}

int countPairs(vector<int>& nums) {
    int n=nums.size(),cnt=0;
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        for(const auto s:GenerateAllCombo(nums[i])){
            if(m.count(s)){
                cnt+=m[s];
            }
        }
        string num=to_string(nums[i]);
        while(num.size()!=7){
            num='0'+num;
        }
        m[num]++;
    }
    return cnt;
}

int main(){
    vector<int> nums={1023,2310,2130,213};
    cout<<countPairs(nums)<<endl;
    return 0;
}