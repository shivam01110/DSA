#include <bits/stdc++.h>
using namespace std;

string shiftString(string s, int leftShifts, int rightShifts) {
    int n = s.length();
    int netShifts = (rightShifts - leftShifts) % n;

    if (netShifts < 0) {
        // Equivalent to left shift
        netShifts = (netShifts + n) % n;
        return s.substr(netShifts) + s.substr(0, netShifts);
    } else {
        // Right shift
        return s.substr(n - netShifts) + s.substr(0, n - netShifts);
    }
}

int main(){
    cout<<shiftString("shivam",2,3);
}