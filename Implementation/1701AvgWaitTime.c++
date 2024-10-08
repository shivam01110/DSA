#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime(vector<vector<int>>& customers) {
    int t=0,wait=0,n=customers.size();
    for(auto ord:customers){
        t=max(t,ord[0])+ord[1];
        wait+=(t-ord[0]);
    }
    cout<<wait<<" "<<n<<endl;
    return (double)wait/n;
}

int main(){
    vector<vector<int>> customer={{2,10},{5,3},{8,7},{8,5},{10,4},{12,3},{12,5},{12,1},{14,6}};
    cout<<averageWaitingTime(customer)<<endl;
    return 0;
}