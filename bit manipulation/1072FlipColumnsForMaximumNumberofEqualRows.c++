#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ConvertRowToStr(vector<int> row){
        int len=row.size();
        string str(len,'S');    //S->same ,C->change for eg: 1010001 will be equivalent to "SCSCCCS"
        for(int i=0;i<len;i++){
            if(row[i]!=row[0]){
                str[i]='C';
            }
        }
        return str;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //IDEA: if 2 rows are same then we can flip all columns contains 1 or 0 so that all cell in that row are same
        //also if 2 rows are exactly inverted like 1010 and 0101 then we can flip either  2 and 4 column (1010-->1111 && 0101-->0000) or 
        // 1 and 3 column (1010-->0000 && 0101-->1111) to make all cell in that row same
        //OBSERVATION: 1010 and 0101 follow the same nature when it come to bit change
        //1010 -->"SAME"(as first bit)-->"CHANGE"(change from first bit)-->"SAME"(as first bit)-->"CHANGE"(change from first bit)===> 1010 ==="SCSC"
        //similarly, 0101 -->"SAME"(as first bit)-->"CHANGE"(change from first bit)-->"SAME"(as first bit)-->"CHANGE"(change from first bit)===>0101==="SCSC"
        unordered_map<string,int> m;
        int maxi=INT_MIN;
        for(auto r:matrix){
            string str=ConvertRowToStr(r);
            m[str]++;
            maxi=max(maxi,m[str]);
        }
        return maxi;
    }
};