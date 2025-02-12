#include <bits/stdc++.h>
using namespace std;

const int range=400001; 
int l[range],r[range],prefix[range],m[range];
void solve(){
    int n;cin>>n;
    for (int i = 1; i <= 2 * n; ++i) prefix[i] = m[i] = 0;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        if(l[i]==r[i]) {
            m[l[i]]+=1;
            prefix[l[i]]=1;
        }
    }
    for(int i=2;i<=2*n;i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=1;i<=n;i++){
        std::cout << ((l[i] == r[i] ? m[l[i]] <= 1 : prefix[r[i]] - prefix[l[i] - 1] < r[i] - l[i] + 1) ? "1" : "0");
    }
	std::cout << '\n';
}

int main(){
    int t;
    cin>>t;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    while(t--){
        solve();
    }
    return 0;
}