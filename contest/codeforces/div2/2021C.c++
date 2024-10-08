#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n,m,q;
    cin>> n>>m>>q;
    vector<int> a(n),b;
    unordered_set<int> s;
    for (int i=0; i<n;i++) cin>>a[i];
    int bi,currsize=0;
    for (int i=0;i<m;i++){
        cin>>bi;
        if (currsize==0||b[currsize-1]!=bi){
            b.push_back(bi);
            currsize++;
        }
    }
    int res = 1,j=0;
    for (int i = 0; i < currsize; i++){
        if (b[i] == a[j]){
            s.insert(a[j]);
            j++;
        }else{
            auto it = s.find(b[i]);
            if(it == s.end()){
                cout<<"TIDAK"<<endl;
                return;
            }
        }
    }
    cout<<"YA"<<endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}