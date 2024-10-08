#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    deque<int> d;
    for(int i=1;i<=n;i++){
        d.push_back(i);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<k;j++){
            d.push_back(d.front());
            d.pop_front();
        }
        d.pop_front();
    }
    return d.front();
}

int main(){
    cout<<solve(6,5)<<endl;
    return 0;
}