#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int freq=INT_MIN;
    int i=0,j=0,n=s.length();
    while(i<n && j<n){
        while(j<n && s[j]==s[i]){
            j++;
        }
        freq=max(freq,j-i);
        i=j;
    }
    cout<<freq<<endl;
    return 0;
}