#include <bits/stdc++.h>
using namespace std;

int recurr(string& s,int i,int m,int k){
    if(i>=s.length()){ 
        cout<<(i >= s.length())<<endl;
        cout << "i = " << i << " k = " <<  k << " maxi = " << 1 << endl;
        return 1;
    }
    cout<<"END"<<endl;
    if(i>=0 && (s[i]=='C' || (s[i]=='W' && k==0))){
        cout << "i = " << i << " k = " <<  k << " maxi = " << 0 << endl;
         return 0;
    }
    int maxi=0;
    if(i==-1 || s[i]=='L'){
        for(int j=i+1;j<=i+m;j++){
            maxi|=recurr(s,j,m,k);
        }
    }
    else if(s[i]=='W'){
        maxi|=recurr(s,i+1,m,k-1);
    }
    cout << "i = " << i << " k = " <<  k << " maxi = " << maxi << endl;
    return maxi;
}

string solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    cout<<s<<endl;
    cout<<s.length()<<endl;
    if(recurr(s,-1,m,k)) return "YES";
    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}