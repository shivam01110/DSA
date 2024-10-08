#include <bits/stdc++.h>
using namespace std;

static bool compare(string a,string b){
    return a+b>b+a;
}

string largestNumber(vector<int>& nums) {
    vector<string> strnum;
    for(auto n:nums){
        strnum.push_back(to_string(n));
    }
    sort(strnum.begin(),strnum.end(),compare);
    string res="";
    for(auto str:strnum) res+=str;
    return (res[0]=='0')?"0":res;
}