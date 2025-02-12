#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int north=0,south=0,east=0,west=0,ans=0;
        for(char c:s){
            if(c=='N') north++;
            if(c=='E') east++;
            if(c=='W') west++;
            if(c=='S') south++;
            int curr=abs(north-south)+abs(east-west);
            int change=k;
            curr=curr+(2*min(change,min(north,south)));
            change=change-min(north,south);
            if(change>0) curr=curr+(2*min(change,min(east,west)));
            ans=max(curr,ans);
        } 
        return ans;
    }
};