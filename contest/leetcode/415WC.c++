#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

// TrieNode structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

// Trie class for inserting and searching prefixes
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        clear(root);
    }
    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    // Search for all valid prefixes in the target starting from index 'start'
    vector<int> searchPrefixes(const string& target, int start) {
        TrieNode* node = root;
        vector<int> validLengths;
        // Traverse the target string from the start index
        for (int i = start; i < target.size(); ++i) {
            char c = target[i];
            if (!node->children.count(c)) break;  // Stop if no match is found
            node = node->children[c];
            // If we found a valid prefix, store its length
            if (node->isEndOfWord) {
                validLengths.push_back(i - start + 1);
            }
        }
        return validLengths;
    }
private:
    // Recursive function to delete nodes
    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }
};

// Function to find the minimum number of valid strings to form the target
int minNumberOfValidStrings(const vector<string>& words, const string& target) {
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);  // Insert each word into the Trie
    }
    int n = target.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;  // Base case: 0 valid strings needed to form an empty target
    // Iterate through each position in the target
    for (int i = 0; i < n; ++i) {
        if (dp[i] == INT_MAX) continue;  // Skip unreachable positions
        vector<int> validLengths = trie.searchPrefixes(target, i);  // Find valid prefixes starting at i
        // Update dp array based on valid prefixes
        for (int length : validLengths) {
            if (i + length <= n) {
                dp[i + length] = min(dp[i + length], dp[i] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];  // Return the result
}

int main() {
    vector<string> words = {"abc", "aaaaa", "bcdef"};
    string target = "aabcdabc";
    cout << minNumberOfValidStrings(words, target) << endl; // Output: 3
    return 0;
}
