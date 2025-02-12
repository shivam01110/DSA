#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int num=n;
        int i=0;
        while(n!=0){
            int t=(1<<i);
            num=num|t;
            n=n>>1;
            i+=1;
        }
        return num;
    }
};