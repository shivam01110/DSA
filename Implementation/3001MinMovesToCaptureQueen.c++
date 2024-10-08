#include <bits/stdc++.h>
using namespace std;

bool bishopKillIn1moves(int a, int b, int c, int d, int e, int f){
    int row=e,col=f;
    while(row<=8 && col<=8){
        if(row==a && col==b) break;
        if(row==c && col==d) return true;
        row++;col++;
    }
    row=e,col=f;
    while(row>=1 && col>=1){
        if(row==a && col==b) break;
        if(row==c && col==d) return true;
        row--;col--;
    }
    row=e,col=f;
    while(row>=1 && col<=8){
        if(row==a && col==b) break;
        if(row==c && col==d) return true;
        row--;col++;
    }
    row=e,col=f;
    while(row<=8 && col>=1){
        if(row==a && col==b) break;
        if(row==c && col==d) return true;
        row++;col--;
    }
    return false;
}

bool rookKillIn1move(int a, int b, int c, int d, int e, int f){
    if(a==e){
        int bishop=0;
        for(int i=min(b,f);i<max(b,f);i++){
            if(a==c && i==d){
                bishop=1;
                break;
            }
        }
        if(!bishop) return true;
    }
    if(b==f){
        int bishop=0;
        for(int i=min(a,e);i<max(a,e);i++){
            if(d==b && i==c){
                bishop=1;
                break;
            }
        }
        if(!bishop) return true;
    }
    return false;
}
int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {  
    if((c+d)%2==(e+f)%2 && (e+f)%2==(a+b)%2){
       if (bishopKillIn1moves(a,b,c,d,e,f)) return 1;
    }
    if(rookKillIn1move(a, b, c, d, e, f)) return 1;
    return 2;
}