#include <bits/stdc++.h>
using namespace std;

string solve(string s){
    int vowel=0;
    for(auto c:s){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            vowel++;
        }
    }
    if(vowel<2) return "Disqualify";
    int constant=s.length()-vowel;
    if(sqrt(constant)*sqrt(constant)!=constant) return "Disqualify";
    int sqroot=sqrt(constant);
    if(sqroot==1) return "Disqualify";
    if(sqroot==2) return "Qualify";
    for(int i=3;i<sqroot;i++){
        if(sqroot%i==0) return "Disqualify";
    }
    return "Qualify";
}


int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}