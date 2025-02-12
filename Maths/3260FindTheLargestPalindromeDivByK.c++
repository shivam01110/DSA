#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisibleBy7(string num){
        while(num.length()%3!=0){
            num='0'+num;
        }
        int len=num.length();
        int sign=1,tot=0;
        for(int i=len-3;i>=0;i-=3){
            tot=tot+sign*stoi(num.substr(i,3));
            sign=(-1)*sign;
        }
        return (tot%7==0);
    }
    string largestPalindrome(int n, int k) {
        string res="";
        if(k==1 || k==3 ||k==9) res=string(n,'9');
        else if(k==2){
            res=string(n,'9');
            res[0]='8',res[n-1]='8';
        }
        else if(k==4){
            res=string(n,'9');
            res[0]='8',res[n-1]='8';
            if(n>1)res[1]='8',res[n-2]='8';
        }
        else if(k==5){
            res=string(n,'9');
            res[0]='5',res[n-1]='5';
        }
        else if(k==6){
            if(n<=2) res=string(n,'6');
            else{
                res=string(n,'9');
                res[0]='8',res[n-1]='8';
                if(n%2){res[n/2]='8';}
                else{
                    res[n/2]='7';
                    res[(n/2)-1]='7';
                }
            }
        }
        else if(k==7){
            res=string(n,'9');
            while(divisibleBy7(res)==0){
                if(n%2){
                    res[n/2]-=1;
                }
                else{
                    res[n/2]-=1;
                    res[(n/2)-1]-=1;
                }
                cout<<res<<endl;
            }
        }
        else{
            res=string(n,'9');
            res[0]='8',res[n-1]='8';
            if(n>1)res[1]='8',res[n-2]='8';
            if(n>2)res[2]='8',res[n-3]='8';
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.largestPalindrome(2,7)<<endl;
    // cout<<sol.divisibleBy7("95977")<<endl;
    // string num="34";
    // num[1]-=5;
    // cout<<num<<endl;
    return 0;
}