#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    int n = s.size();
    if(n%2) return "impossible";
    unordered_map<char,int> freq;
    for(auto c:s){
        freq[c]+=1;
    }
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second>n/2) return "impossible";
    }
    priority_queue<pair<char,int>,vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for(auto it=freq.begin();it!=freq.end();it++){
        pq.push({it->first,it->second});
    }
    string result(n,'#');
    int i=0;
    while (!pq.empty()) {
        auto t=pq.top();
        char tc=t.first;
        int tf=t.second;
        pq.pop();
        if(i>=n/2 && result[n-i-1]==tc){
            if(!pq.empty()){
                auto othertop=pq.top();
                char secondch=othertop.first;
                int secondfreq=othertop.second;
                pq.pop();
                result[i]=secondch;
                if(secondfreq!=1){
                    secondfreq-=1;
                    pq.push({secondch,secondfreq});
                }
                pq.push({tc,tf});
            }
        }
        else{
            result[i]=tc;
            if(tf!=1){
                tf-=1;
                pq.push({tc,tf});
            }
        }
        i++;
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}


