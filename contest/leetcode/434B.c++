#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[1]) < stoi(b[1]); // Convert string to integer and compare
        });
        vector<int> online(numberOfUsers,1);
        vector<int> timeoffline(numberOfUsers);
        vector<int> freq(numberOfUsers,0);
        for(auto e:events){
            int curr=stoi(e[1]);
            for(int i=0;i<numberOfUsers;i++){
                if(online[i]==0 && timeoffline[i]+60<=curr){
                    online[i]=1;
                    timeoffline[i]=0;
                }
            }
            if(e[0]=="MESSAGE"){
                if(e[2]=="ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        freq[i]+=1;
                    }
                }
                else if(e[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(online[i]==1)freq[i]+=1;
                    }
                }
                else{
                    int len=e[2].length();
                    int l=0;
                    while(l<len){
                        l+=2;
                        string id="";
                        while(e[2][l]!=' '){
                            id+=e[2][l];
                            l++;
                        }
                        l++;
                        if(online[stoi(id)]==1){
                            freq[stoi(id)]+=1;
                        }
                    }
                }
            }
            else{
                int id=stoi(e[2]);
                online[id]=0;
                timeoffline[id]=curr;
            }
        }
        return freq;
    }
};


int main() {
    vector<vector<string>> events = {
        {"MESSAGE", "1", "id0 id1"},
        {"MESSAGE", "5", "id2"},
        {"MESSAGE", "6", "ALL"},
        {"OFFLINE", "5", "2"}
    };

    // Sort using a custom comparator
    sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        // First compare the time (second element)
        if (stoi(a[1]) != stoi(b[1])) 
            return stoi(a[1]) < stoi(b[1]);
        // If time is the same, prioritize "OFFLINE" over "MESSAGE"
        return a[0] > b[0];
    });

    // Print sorted events
    for (const auto& event : events) {
        for (const auto& e : event) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}

