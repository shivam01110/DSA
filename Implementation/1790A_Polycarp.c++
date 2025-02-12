#include <bits/stdc++.h>
using namespace std;

int solve(){
    int i=0;
    string str="314159265358979323846264338327";
    string carp;
    cin>>carp;
    while(i<carp.size() && carp[i]==str[i]) {i++;}
    return i;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
    
}