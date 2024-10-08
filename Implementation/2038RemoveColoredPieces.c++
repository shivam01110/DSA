#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors) {
    int a=0,b=0;
    for(int i=0;i<colors.length();i++){
        if(colors[i]=='A'){
            int cnt=0;
            while (i<colors.length() && colors[i]=='A')
            {
                i++;
                cnt++;
            }
            a=a+max(cnt-2,0);
        }
        else{
            int cnt=0;
            while (i<colors.length() && colors[i]=='B')
            {
                i++;
                cnt++;
            }
            b=b+max(cnt-2,0);
        }
    }
    return a>b;
}