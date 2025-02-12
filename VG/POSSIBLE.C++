#include <bits/stdc++.h>
using namespace std;

string canMakeAllGold(string s) {
    int countZeros = count(s.begin(), s.end(), '0');
    return (countZeros % 2 == 0) ? "YES" : "NO";
}

int main() {
    string s;
    cin >> s;
    cout << canMakeAllGold(s) << endl;
    return 0;
}
