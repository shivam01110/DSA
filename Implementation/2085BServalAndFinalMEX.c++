#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,part1=0,part2=0;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i<2 && a[i]==0) part1++;
        if(i>=2 && a[i]==0) part2++;
    }
    if(part1==0 && part2==0){
        cout<<1<<"\n";
        cout<<1<<" "<<n<<endl;
    }
    else if(part1!=0 && part2==0){
        cout<<2<<"\n";
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
    }
    else if(part1==0 && part2!=0){
        cout<<2<<"\n";
        cout<<3<<" "<<n<<endl;
        cout<<1<<" "<<3<<endl;  
    }
    else{
        cout<<3<<"\n";
        cout<<3<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;  
        cout<<1<<" "<<2<<endl;  
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
};