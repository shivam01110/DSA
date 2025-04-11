#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0 || (n & (n + 1)) == 0) {
        cout << -1 << endl;
        return;
    }

    int num = 0;
    while (n > 0) {
        num = (num << 1) | 1;
        n >>= 1;
    }

    cout << (num >> 1) << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}