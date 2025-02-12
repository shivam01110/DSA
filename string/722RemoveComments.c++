//learned how to use flag (here block) to traverse the string
#include <bits/stdc++.h>
using namespace std;

vector<string> removeComments(vector<string>& source) {
    int n=source.size(),block=0;
    vector<string> res;
    string code="";
    for(string line:source){
        int len=line.length();   
        for(int j=0;j<len;j++){
            /*If we encounter // and are not in a code block, break the loop to ignore the rest of the line.*/
            if(!block && j<len-1 && line.substr(j,2)=="//"){
                break;
            }
            // If we encounter /* and are not in a code block, set block to true and continue to the next character.
            else if(!block && j<len-1 && line.substr(j,2)=="/*"){
                j++;
                block=!block;
            }
            // If we encounter */ and are in a code block, set block to false and continue to the next character.
            else if(block && j<len-1 && line.substr(j,2)=="*/"){
                j++;
                block=!block;
            }
            // If we are not in a code block, append the character to code.
            else if(!block){
                code+=line[j];
            }
        }
        // After processing each line, if code is not empty and we are not in a code block, add code to the answer and reset code.
        if(!block && code.length()){
            res.push_back(code);
            code="";
        }
    }
    return res;
}