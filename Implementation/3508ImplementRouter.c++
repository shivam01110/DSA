#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Router {
private:
    int limit=0;
    queue<vector<int>> q;
    set<vector<int>> s;
    map<int,vector<int>> m;
    void remove(){
        vector<int> f=q.front();
        q.pop();
        s.erase(f);
        sort(m[f[2]].begin(), m[f[2]].end());
        auto it = lower_bound(m[f[2]].begin(), m[f[2]].end(), f[3]);
        if (it != m[f[2]].end() && *it == f[3]) {
            m[f[2]].erase(it);
        }
    }
public:

    Router(int memoryLimit) {
        limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({source,destination,timestamp})==s.end()) return 0;
        if(limit==q.size()) remove();
        q.push({source,destination,timestamp});
        s.insert({source,destination,timestamp});
        m[destination].push_back(destination);
        return 1;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0) return {};
        vector<int> res=q.front();
        remove();
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto right = upper_bound(m[destination].begin(), m[destination].end(),endTime);
        auto left =lower_bound(m[destination].begin(), m[destination].end(),startTime);
        return (right-left);
    }
};

void solve(){
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}