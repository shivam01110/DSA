#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n,1);
    for (int i = x; i < n; ++i) {
        a[i] = -1;
    }
    for (int i = 0; i < y - 1; ++i) {
        a[i] = -1;
    }
    if (x > y) {
        a[y - 1] = 1; 
    }
    for (int ele : a) {
        cout << ele << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}