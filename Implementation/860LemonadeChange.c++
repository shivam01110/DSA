#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int coins5=0,coins10=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5) coins5++;
        else if(bills[i]==10) {
            coins10++;
            if(coins10>coins5) return false;
            coins5-=coins10;
        }
        else {
            if((coins10 <1 && coins5<1) || coins5<3) return false;
            if(coins10>=1 && coins5>=1){
                coins10--;
                coins5--;
            }
            else{
                coins5-=3;
            }
        }
    }
    return true;
}