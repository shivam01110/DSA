#include <bits/stdc++.h>
using namespace std;

// Mapping 3x3 digit representations to their corresponding numbers
unordered_map<string, int> mapDigits(vector<string>& digitPatterns) {
    unordered_map<string, int> digitMap;
    for (int i = 0; i < 30; i += 3) {
        string digitRep = digitPatterns[0].substr(i, 3) + 
                          digitPatterns[1].substr(i, 3) + 
                          digitPatterns[2].substr(i, 3);
        digitMap[digitRep] = i / 3;
    }
    return digitMap;
}

// Parsing the 3x3 matrices of input digits into individual digit strings
vector<string> parseInputDigits(vector<string>& rows) {
    vector<string> digits;
    for (int i = 0; i < rows[0].size(); i += 3) {
        string digitRep = rows[0].substr(i, 3) + 
                          rows[1].substr(i, 3) + 
                          rows[2].substr(i, 3);
        digits.push_back(digitRep);
    }
    return digits;
}

// Validating if the input digits can be toggled to form valid numbers
bool isValid(vector<string>& inputDigits, unordered_map<string, int>& digitMap) {
    for (string& digit : inputDigits) {
        if (digitMap.find(digit) != digitMap.end()) continue;

        bool validToggle = false;
        for (int i = 0; i < 9; i++) {
            string toggled = digit;
            toggled[i] = (toggled[i] == '0') ? '1' : '0';
            if (digitMap.find(toggled) != digitMap.end()) {
                validToggle = true;
                break;
            }
        }
        if (!validToggle) return false;
    }
    return true;
}

// Calculate the sum of all numbers formed by toggling LEDs
long long calculateSum(vector<string>& inputDigits, unordered_map<string, int>& digitMap) {
    string originalNum = "";
    for (string& digit : inputDigits) {
        originalNum += to_string(digitMap[digit]);
    }

    long long totalSum = 0;
    for (int i = 0; i < inputDigits.size(); i++) {
        string originalDigit = inputDigits[i];
        for (int j = 0; j < 9; j++) {
            string toggled = originalDigit;
            toggled[j] = (toggled[j] == '0') ? '1' : '0';

            if (digitMap.find(toggled) == digitMap.end()) continue;

            string newNum = originalNum;
            newNum[i] = '0' + digitMap[toggled];
            totalSum += stoll(newNum);
        }
    }
    return totalSum;
}

int main() {
    vector<string> digitPatterns(3);
    for (int i = 0; i < 3; i++) cin >> digitPatterns[i];

    unordered_map<string, int> digitMap = mapDigits(digitPatterns);

    vector<string> inputRows(3);
    for (int i = 0; i < 3; i++) cin >> inputRows[i];

    vector<string> inputDigits = parseInputDigits(inputRows);

    if (!isValid(inputDigits, digitMap)) {
        cout << "Invalid" << endl;
        return 0;
    }

    long long result = calculateSum(inputDigits, digitMap);
    cout << result << endl;

    return 0;
}
