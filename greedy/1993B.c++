#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll odd=-1;
    int op=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2) odd=max(odd,(ll)a[i]);
        if(a[i]%2==0) op++;
    }
    if(odd==-1 || op==0){
        cout<<0<<endl;  //if there is same parity in array then no operation need to perform
        return;
    }
    //in worst case we need to perform even+1 i.e op+1 operations to make all parity same i.e odd
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]%2) continue;
        else {
            if(a[i]>odd){   //  before we do this operation, we need to do another on odd and the largest even element to make odd the largest in the array. Note that this case only happens at most once after
                op++;       //this operation all even elements will less than odd
                break;
            }
            odd+=a[i];
        }
    }
    cout<<op<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
