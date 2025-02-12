#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDivByThree(string s) {
        int count = 0, prefixSum = 0;
        unordered_map<int, int> modCount;
        modCount[0] = 1; // Base case: an empty prefix with mod 0

        for (char ch : s) {
            prefixSum = (prefixSum + (ch - '0')) % 3;
            count += modCount[prefixSum]; // Count how many times this mod has appeared
            modCount[prefixSum]++; // Update frequency
        }
        return count;
    }
    int countDivBySeven(string s) {
        int count = 0, prefixMod = 0, power10 = 1;
        unordered_map<int, int> modCount;
        modCount[0] = 1; // Base case
    
        for (int i = 0; i < s.size(); i++) {
            prefixMod = (prefixMod * 10 + (s[i] - '0')) % 7;
            count += modCount[prefixMod]; // Count valid substrings
            modCount[prefixMod]++; // Update count
        }
        return count;
    }
    
    int countDivisibleSubstrings(string s) {
        int result = 0;
        for (int r = 0; r < s.size(); r++) {
            int lastDigit = s[r] - '0';
            if (lastDigit == 3 || lastDigit == 6 || lastDigit == 9) {
                result += countDivByThree(s.substr(0, r + 1));
            } else if (lastDigit == 7) {
                result += countDivBySeven(s.substr(0, r + 1));
            }
            else if( lastDigit==1 || lastDigit==2 || lastDigit ==5){
                result+=((r+1)*(r+2))/2;
            }
            else if(lastDigit==4){
                result++;
                if(r>0  && stoi(s.substr(r-1,2))%4==0){
                    result++;
                    result+=((r-1)*r)/2;
                }
            }
            else if(lastDigit==8){
                result++;
                if(r>0 && stoi(s.substr(r-1,2))%8==0) result++;
                if(r>1 && stoi(s.substr(r-2,3))%8==0) {
                    result++;
                    result+=((r-2)*(r-1))/2;
                }
            }
        }
        return result;
    }
    
};

// Example usage
int main() {
    Solution sol;
    cout << sol.countDivisibleSubstrings("666") << endl; // Output: 11
    cout << sol.countDivisibleSubstrings("5701283") << endl; // Output: 18
    cout << sol.countDivisibleSubstrings("1010101010") << endl; // Output: 25
    return 0;
}
