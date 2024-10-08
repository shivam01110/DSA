#include <bits/stdc++.h>
using namespace std;

//Bezout Theorem
//if gcd(a,b)=g then there exist x and y such that x.a+y.b=g

void solve2(){
    int n,a,b;
    cin>>n>>a>>b;
    int g=__gcd(a,b);      
    set<int> s;
    int ele;
    for(int i=1;i<=n;i++){
        cin>>ele;
        ele%=g;
        s.insert(ele);
    }
    vector<int> v;
    for(auto it=s.begin();it!=s.end();it++){
        v.push_back(*it);
    }
    int m=v.size();
    int res=v[m-1]-v[0];
    for(int i=1;i<m;i++){
        //if v[i] is minimum then v[i-1] will be the maximum, since v is sorted and all element of v are in [0,g-1) therefore,abs(v[i-1]-v[i])>abs(v[i-1]+g-v[i])
        res=min(res,v[i-1]+g-v[i]);     
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve2();
    }
    return 0;
}
 
