#include <iostream>
#include <algorithm>
using namespace std;

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

int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string sum = addStrings(num1, num2);
    cout << "Sum: " << sum << endl;

    return 0;
}