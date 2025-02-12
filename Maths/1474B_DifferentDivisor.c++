#include <bits/stdc++.h>
using namespace std;

vector<int> Seive(int n) {
    vector<int> vis(n+1,1);
    vis[0]=0;vis[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(vis[i]){
            for(int j=i*i;j<=n;j+=i){
                vis[j]=0;
            }
        }
    }
    vector<int> prime;
    for(int i=0;i<=n;i++){
        if(vis[i]) prime.push_back(i);
    }
    return prime;
}

void solve(vector<int>& prime){
    int d;
    cin>>d;
    int ind1=lower_bound(prime.begin(),prime.end(),d+1)-prime.begin();
    int p1=prime[ind1];
    int ind2=lower_bound(prime.begin(),prime.end(),p1+d)-prime.begin();
    int p2=prime[ind2];
    cout<<(p1*p2)<<endl;
}

int main(){
    int t;
    cin>>t;
    vector<int> prime=Seive(100000);
    while(t--){
        solve(prime);
    }
    return 0;
}