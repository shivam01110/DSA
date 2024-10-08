#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string pw;
    cin>>pw;
    int i=0;
    for(;i<pw.length()-1;i++){
        if(pw[i]==pw[i+1]) break;
    }
    pw.insert(pw.begin()+i+1,(pw[i]+1-'a')%26+'a');
    cout<<pw<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}