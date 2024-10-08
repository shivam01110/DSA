#include <bits/stdc++.h>
using namespace std;

string numberToBinaryString(const string& number) {
    stringstream ss(number);
    unsigned long long num;
    ss >> num;
    // Convert the number to binary using bitset
    bitset<64> binary(num); // Assuming 64-bit unsigned integer
    // Convert bitset to string and remove leading zeros
    string binaryString = binary.to_string();
    binaryString = binaryString.substr(binaryString.find('1'));
    return binaryString.empty() ? "0" : binaryString; // Handle case for number 0
}

string convertDateToBinary(string date) {
    string year=numberToBinaryString(date.substr(0,4));
    string mon=numberToBinaryString(date.substr(5,2));
    string day=numberToBinaryString(date.substr(8,2));
    string res=year+"-"+mon+"-"+day;
    return res;
}
int main() {
    string number = "1900-01-01";
    string binaryString = convertDateToBinary(number);
    cout << "Binary of " << number << " is: " << binaryString << endl;
    return 0;
}
