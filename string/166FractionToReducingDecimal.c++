#include <bits/stdc++.h>
using namespace std;
#define ll long long
string fractionToDecimal(int numerator, int denominator) {
    if(numerator==0) return "0";
    string res="";
    if(numerator<0 ^ denominator<0) res+='-';
    int n=abs(numerator),d=abs(denominator);
    res+=to_string(n/d);
    ll r=n%d;
    if(r==0) return res;
    res+='.';
    unordered_map<int,int> m;
    for(;r;r%=d){
        if(m.count(r)){
            res.insert(m[r],1,'(');
            res+=')';
            break;
        }
        m[r]=res.length();
        r*=10;
        res+=to_string(r/d);
    }
    return res;
}

int main(){
    int numerator=4,denominator=2;
    // string str=to_string()
    cout<<(double)1/22398318<<endl;
    return 0;
}