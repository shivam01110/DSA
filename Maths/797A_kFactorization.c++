#include <bits/stdc++.h>
using namespace std;

vector<int> storePrime(int n){
    vector<int> p(n+1,0);
    vector<int> res;
    for(int i=2;i<=n;i++){
        if(p[i]==0) res.push_back(i);
        for(int j=i*i;j<=n;j+=i){
            p[i]=1;
        }
    }
    return res;
}

void print(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(k==1) {cout<<n<<endl;return;} 
    vector<int> p=storePrime(n/2);
    vector<int> arr;
    int i=0;
    while(k>1 && n>=1 && i<p.size()){
        cout<<p[i]<<endl;
        if(n%p[i]==0){
            arr.push_back(p[i]);
            n=n/p[i];
            k--;
        }
        else{
            i++;
        }
    }
    if(k!=1 || n==1 ||i==p.size()) {cout<<-1<<endl;return;}
    arr.push_back(n);
    print(arr);
}

int main(){
    solve();
    return 0;
}
