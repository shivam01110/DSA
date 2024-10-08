#include <bits/stdc++.h>
using namespace std;


string add(string s1,string s2){
    int l1=s1.length(),l2=s2.length(),diff=abs(l1-l2);
    string extra(diff,'0');
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    if(l1<l2) s1+=extra;
    else s2+=extra;
    int c=0;
    string sum="";
    for(int i=0;i<max(l1,l2);i++){
        int digsum=(s1[i]-'0')+(s2[i]-'0')+c;
        sum+=to_string(digsum%10);
        c=digsum/10;
    }
    if(c) sum+=to_string(c);
    reverse(sum.begin(),sum.end());
    return sum;
}

string product(string s,char d,int p,int l){
    string prod(p,'0');
    int carry=0,multiplier=d-'0';
    for(int i=l-1;i>=0;i--){
        int m=(s[i]-'0')*multiplier;
        m=m+carry;
        prod+=to_string(m%10);
        carry=m/10;
    }
    if(carry)prod+=to_string(carry);
    reverse(prod.begin(),prod.end());
    return prod;
}

string multiply(string s1,string s2){
    int l1=s1.length(),l2=s2.length();
    string res="0";
    for(int i=l2-1;i>=0;i--){
        string mul=product(s1,s2[i],l2-i-1,l1);
        res=add(mul,res);
    }
    while (res.size() > 1 && res[0] == '0') {
        res.erase(res.begin());
    }
    return res;
}

int main(){
    string s1="17854269523526935531552342523",s2="49865814320256874103569864123056";
    string ans=multiply(s1,s2);
    // cout<<multiply(s1,s2)<<endl;
    cout<<ans<<endl;
    return 0;
}