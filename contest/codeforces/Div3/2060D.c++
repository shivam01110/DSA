#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n ;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){
            a[i]-=a[i-1];
        }else{
            cnt++;
        }
    }
    if(cnt++) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}