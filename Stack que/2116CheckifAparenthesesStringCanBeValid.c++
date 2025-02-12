#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //STACK APPROACH
    bool canBeValid(string s, string locked) {
        int n = s.length();
        // If the string length is odd, it cannot be valid as every open bracket must have a matching close bracket.
        if (n % 2) return false;

        stack<int> open;       // Stack to store indices of locked open brackets '('.
        stack<int> openclose;  // Stack to store indices of unlocked brackets that can act as either '(' or ')'.

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {  // If the character is unlocked, it can be used as either '(' or ')'.
                openclose.push(i);
            } else {
                if (s[i] == '(') {
                    open.push(i);  // Push locked '(' onto the open stack.
                } else {
                    // For locked ')', check if there is a matching '(' or an unlocked character available.
                    if (!open.empty()) {
                        open.pop();  // Match this ')' with the top '(' in the open stack.
                    } else if (!openclose.empty()) {
                        openclose.pop();  // Use an unlocked character as '(' to match this ')'.
                    } else {
                        return false;  // No matching '(' or unlocked character available.
                    }
                }
            }
        }

        // After processing the string, try to match any remaining locked '(' with unlocked characters.
        while (!open.empty() && !openclose.empty() && open.top() < openclose.top()) {
            open.pop();         // Match the top locked '('.
            openclose.pop();    // Use the unlocked character as ')'.
        }

        // If the open stack is empty, all locked '(' have been successfully matched.
        return open.empty();
    }

    //GREEDY APPROACH
    bool canBeValid(string s, string locked) {
        int n=s.length(),open=0,close=0;
        if(n%2) return false;
        //iterate from left to right and consider locked[i]='0' as open bracket;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || locked[i]=='0'){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else return false;
            }
        }
        //iterate from right to left and consider locked[i]='0' as close bracket;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){
                close++;
            }
            else{
                if(close>0){
                    close--;
                }
                else return false;
            }
        }
        return true;
    }
};


