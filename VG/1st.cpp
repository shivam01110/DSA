#include <bits/stdc++.h>
using namespace std;


string MyDesign;
string GivenDesign;
string patch;
string CurrentDesign;
int patchLen=0,MyDesignLen=0;
int lastInd=0;
vector<int> CurrentSequence;
bool found=false;


bool match(){
    for(int i=0;i<GivenDesign.length();i++){
        if(MyDesign[i]!=GivenDesign[i]) return false;
    }
    return true;
}

//attach patch to MyDesign at index i
void attach(int i){
    int j=0;
    while(j<patchLen && i<MyDesignLen){
        MyDesign[i]=patch[j];
        j++;
        i++;
    }
}

void sequence(vector<int>& visited){
    if(found) return;
    for(int j=0;j<=lastInd;j++){
        if(visited[j]) continue;
        visited[j]=1;
        CurrentSequence.push_back(j);
        string temp=MyDesign;
        attach(j);
        if (match()) {
            // Print and exit immediately
            for (int i=0;i<CurrentSequence.size();i++) {
                cout << CurrentSequence[i] << " ";
            }
            found = true;  // Set flag to true
            return;
        } else {
            sequence(visited);  // Recursive call to explore further
        }
        if (found) return;  // Exit if found
        //backtrack--->undo all the changes
        visited[j]=0;
        CurrentSequence.pop_back(); 
        MyDesign=temp;     //remove the patch
    }
}

int main() {
    getline(cin,patch);
    getline(cin,GivenDesign);
    MyDesignLen=GivenDesign.length();
    patchLen=patch.length();
    lastInd=MyDesignLen-patchLen;
    MyDesign=string(MyDesignLen,'*');
    vector<int> visited(lastInd+1,0);
    sequence(visited);
    if(!found)cout<<-1;
    cout<<endl;
    return 0;
}
