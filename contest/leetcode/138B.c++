#include <bits/stdc++.h>
using namespace std;

string stringHash(string s, int k) {
    int l=s.length();
    int sl=l/k;
    string res="";
    int i=0;
    while(i<l){
        int sum=0;
        for(int j=0;j<sl;j++){
            sum+=(s[j+i]-'a');
        }
        sum%=26;
        res+=char('a'+sum);
        i+=sl;
    }
    return res;
}

int main(){
    cout<<char('a'+1)<<endl;
}