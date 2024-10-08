#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool containAllVowels(vector<int>& freq) {
        return (freq['a' - 'a'] > 0 && freq['e' - 'a'] > 0 && freq['i' - 'a'] > 0 && 
                freq['o' - 'a'] > 0 && freq['u' - 'a'] > 0);
    }

    int countOfSubstrings(string word, int k) {
        int len = word.length();
        int l = 0, r = 0, cnt = 0, cons = 0,i=len-1;
        vector<int> freq(26, 0);
        vector<char> vowel={'a','e','i','o','u'};
        vector<int> rgtVowel(len,-1);
        while(i>-1){
            if(binary_search(vowel.begin(),vowel.end(),word[i])){
                int pos=i;
                rgtVowel[i]=pos;
                while(i>-1 && binary_search(vowel.begin(),vowel.end(),word[i])){
                    rgtVowel[i]=pos;
                    i--;
                }
                if(i>=0) rgtVowel[i]=pos;
            }
            else continue;
        }
        while (r < len) {
            freq[word[r] - 'a']++;
            if(!binary_search(vowel.begin(),vowel.end(),word[i])) {
                cons++;
            }
            while(cons == k && containAllVowels(freq)){
                if(rgtVowel[r]!=-1) {
                    cnt+=(rgtVowel[r]-r+1);
                }
                else cnt++;
                freq[word[l] - 'a']--;
                if(!binary_search(vowel.begin(),vowel.end(),word[i])) {
                    cons--;
                }
                if (cons == k && containAllVowels(freq)) cnt++;
                l++;
            }
            r++;
        }
        return cnt;
    }
};