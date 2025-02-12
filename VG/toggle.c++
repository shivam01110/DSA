#include <bits/stdc++.h>
using namespace std;

//mapping string to digits
unordered_map<string,int> strToDig(vector<string>& dig){
    unordered_map<string,int> m;
    for(int i=0;i<30;i+=3){
        string str=dig[0].substr(i,3);
        str+=dig[1].substr(i,3);
        str+=dig[2].substr(i,3);
        m[str]=i/3;
    }
    return m;
}

//string for each digit of the input
vector<string> makeDigits(vector<string>& Row){
    int len=Row[0].size();
    vector<string> n(len/3);
    for(int i=0;i<Row[0].size();i+=3){
        string str=Row[0].substr(i,3);
        str+=Row[1].substr(i,3);
        str+=Row[2].substr(i,3);
        n[i/3]=str;
    }
    return n;
}

string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    reverse(result.begin(), result.end());
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }
    if (start == result.size()) {
        return "0";
    }
    return result.substr(start); 
}

void recurr(int i, int n, string& num, vector<string>& digits, unordered_map<string, int>& m, set<string>& newnumber) {
    // Base case: If we've reached the end of digits, store the constructed number
    if (i == n) {
        newnumber.insert(num);
        return;
    }
    for (int j = 0; j < 9; j++) {
        // Toggle the current digit
        char original = digits[i][j];
        digits[i][j] = (original == '0') ? '1' : '0'; // Toggle between '0' and '1'
        if (m.find(digits[i]) != m.end()) { // If valid after toggling
            num.push_back(char(m[digits[i]]) + '0');
            recurr(i + 1, n, num, digits, m, newnumber);
            num.pop_back();
        }
        digits[i][j] = original; // Restore the original value
        // Without toggling
        if (m.find(digits[i]) != m.end()) { // If valid without toggling
            num.push_back(char(m[digits[i]]) + '0');
            recurr(i + 1, n, num, digits, m, newnumber);
            num.pop_back();
        }
    }
}

string PossibleDigit(string digit,unordered_map<string,int>& m){
    string possible="";
    for(int i=0;i<9;i++){
        char original=digit[i];
        digit[i] = (original == '0') ? '1' : '0'; // Toggle between '0' and '1'
        if (m.find(digit) != m.end()) { // If valid after toggling
            num.push_back(char(m[digit]) + '0');
            num.pop_back();
        }
    }
}

int main(){
    vector<string> dig(3);
    for(int i=0;i<3;i++){
        cin>>dig[i];
    }
    unordered_map<string,int> m=strToDig(dig);
    vector<string> numRow(3);
    for(int i=0;i<3;i++){
        cin>>numRow[i];
    }
    vector<string> n=makeDigits(numRow);
    set<string> newnum;
    string temp="";
    int len=n.size();
    recurr(0,len,temp,n,m,newnum);
    if(newnum.size()==0) cout<<"Invalid"<<endl;
    else{
        string sum="0";
        for(string s:newnum){
            sum=addStrings(sum,s);
        }
        cout<<sum<<endl;
    }
    return 0;
}
