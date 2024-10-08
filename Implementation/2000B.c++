#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    bool seat=true;
    for(int i=0;i<n;i++){
        int seatno;
        cin>>seatno;
        if(i!=0 && a[max(seatno-1,1)]!=1 && a[min(seatno+1,n)]!=1 ){
            seat=false;
        }
        a[seatno]=1;
    }
    if(seat) return "YES";
    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}