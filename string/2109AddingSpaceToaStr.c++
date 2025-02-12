#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        int len=spaces.size(),l=s.length()-1,r=l+len;
        //add the total number of spaces required (i.e len) at the end of the s
        for(int i=0;i<len;i++){
            s+=' ';
        }
        for(int i=len-1;i>=0;i--){
            //swap all the character at l and r pointer and move the pointer to the left side while(l>=space[i])
            while(l>=spaces[i]){
                swap(s[l],s[r]);
                l--;
                r--;
            }
            r--;    //to put a space(' ') at spaces[i]
        }
        return s;
    }
};

int main(){
    string str="JeeshanLovesShivam";
    vector<int> spaces={7,12};
    Solution sol;
    sol.addSpaces(str,spaces);
    cout<<str<<endl;
    return 0;
}