#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool turn=1;
        int remove=10;
        while(n>=0){
            n=n-remove;
            remove--;
            turn=1-turn;
        }
        return turn;
    }
};