#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
	string vowel = "aeiou";
	string res;
    int div=n/5;
	for (int i = 0; i < 5; ++i){ 
        int rem=(i<n%5)?1:0;
        for (int j = 0; j < div+ rem; ++j) {
            res += vowel[i];
        }
    }
	cout << res << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
