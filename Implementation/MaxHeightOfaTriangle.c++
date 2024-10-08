#include <bits/stdc++.h>
using namespace std;

int solve(int a,int b){
    int h=0,n=1;
    while(true){
        if(n%2 && a-n>=0){
            h++;
            a-=n;
            n++;
        }
        else if(n%2==0 && b-n>=0){
            h++;
            b-=n;
            n++;
        }
        else break;
    }
    return h;
}
int main(){
    cout<<solve(1,10)<<endl;
    return 0;
}