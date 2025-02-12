#include <bits/stdc++.h>
using namespace std;

long minOp(long n){
    string bin = bitset<64>(n).to_string();
    bin = bin.substr(bin.find('1'));
    int digCnt = bin.length();
    long operation = 0;
    int sign = 1;
    for (int i = 0; i < digCnt; ++i) {
        int digit = bin[i] - '0';
        long power = digit > 0 ? std::pow(2, digCnt - (i + 1)) : 0;
        long steps = digit * (power * 2 - 1);

        operation += steps * sign;
        sign = sign * (digit == 0 ? 1 : -1);
    }
    return operation;
}

int main(){
    cout<<minOp(13)<<endl;
    return 0;
}