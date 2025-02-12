#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

int findLongestDP3(const std::string& vowels) {
    // Initialize maxlen array with 0 for the first position and negative infinity for the rest
    std::vector<int> maxlen(6, INT_MIN);
    maxlen[0] = 0;

    for (char v : vowels) {
        // Find the index of the vowel in ".aeiou"
        int i = std::string(".aeiou").find(v);
        if (i != std::string::npos) {
            // Update maxlen[i] based on the previous value or the current one
            maxlen[i] = std::max(maxlen[i], maxlen[i - 1]) + 1;
        }
    }

    // Return the maximum length of a valid subsequence ending in 'u', or 0 if not found
    return std::max(maxlen[5], 0);
}

int main() {
    std::string input = "aeiaaioooaauuaeiou";
    std::cout << "Longest subsequence length: " << findLongestDP3(input) << std::endl;
    return 0;
}
