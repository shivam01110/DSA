//46B. T-shirts from Sponsor 
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void solve(){
    vector<string> tsize={"S","M","L","XL","XXL"};
    vector<int> s(5,0);
    for(int i=0;i<5;i++) cin>>s[i];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;cin>>t;
        if(t==tsize[0]){
            if(s[0]) {s[0]--;cout<<tsize[0]<<endl;}
            else if(s[1]) {s[1]--;cout<<tsize[1]<<endl;}
            else if(s[2]) {s[2]--;cout<<tsize[2]<<endl;}
            else if(s[3]) {s[3]--;cout<<tsize[3]<<endl;}
            else {s[4]--;cout<<tsize[4]<<endl;}
        }
        else if(t==tsize[1]){
            if(s[1]) {s[1]--;cout<<tsize[1]<<endl;}
            else if(s[2]) {s[2]--;cout<<tsize[2]<<endl;}
            else if(s[0]) {s[0]--;cout<<tsize[0]<<endl;}
            else if(s[3]) {s[3]--;cout<<tsize[3]<<endl;}
            else {s[4]--;cout<<tsize[4]<<endl;}
        }
        else if(t==tsize[2]){
            if(s[2]) {s[2]--;cout<<tsize[2]<<endl;}
            else if(s[3]) {s[3]--;cout<<tsize[3]<<endl;}
            else if(s[1]) {s[1]--;cout<<tsize[1]<<endl;}
            else if(s[4]) {s[4]--;cout<<tsize[4]<<endl;}
            else {s[0]--;cout<<tsize[0]<<endl;}
        }
        else if(t==tsize[3]){
            if(s[3]) {s[3]--;cout<<tsize[3]<<endl;}
            else if(s[4]) {s[4]--;cout<<tsize[4]<<endl;}
            else if(s[2]) {s[2]--;cout<<tsize[2]<<endl;}
            else if(s[1]) {s[1]--;cout<<tsize[1]<<endl;}
            else {s[0]--;cout<<tsize[0]<<endl;}
        }
        else{
            if(s[4]) {s[4]--;cout<<tsize[4]<<endl;}
            else if(s[3]) {s[3]--;cout<<tsize[3]<<endl;}
            else if(s[2]) {s[2]--;cout<<tsize[2]<<endl;}
            else if(s[1]) {s[1]--;cout<<tsize[1]<<endl;}
            else {s[0]--;cout<<tsize[0]<<endl;}
        }
    }
}
int main(){
    solve();
    return 0;
}