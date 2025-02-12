#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool end=false;
    bool contains(char c){
        return links[c-'a']!=nullptr;
    }
    Node *getlink(char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a']=node;
    }
    void setEnd(){
        end=true;
    }
    bool isEnd() {return end;}
};

class Trie{
private:
    Node *root=nullptr;
public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(auto c:s){
            if(!node->contains(c)){
                node->put(c,new Node());
            }
            node=node->getlink(c);
        }
        node->setEnd();
    }
    bool containsWord(string word,int start,int end){
        Node *node=root;
        for(int i=start;i<end;i++){
            if(!node->contains(word[i])) return false;
            node=node->getlink(word[i]);
        }
        return node->isEnd();
    }
};

class Solution {
public:
    bool solve(string& st,int i,Trie& t,set<int>& s){
        if(i==st.length()) return true;
        for(auto it=s.begin();it!=s.end();it++){
            int end=i+(*it);
            if(end>st.length()) break;
            if (t.containsWord(st, i, end) && solve(st, end, t, s)) { 
                return true; // Return immediately if a valid path is found
            }
        }
        return false;
    }
    bool solve(string& st,int i,Trie& t,set<int>& s,vector<int>& dp){
        if(i==st.length()) return true;
        if(dp[i]!=-1) return dp[i];
        for(auto it=s.begin();it!=s.end();it++){
            int end=i+(*it);
            if(end>st.length()) break;
            if (t.containsWord(st, i, end) && solve(st, end, t, s,dp)) { 
                return dp[i]=true; // Return immediately if a valid path is found
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        int l=s.length();
        vector<int> dp(l,-1);
        set<int> wordlen;
        for(string word:wordDict){
            t.insert(word);
            wordlen.insert(word.length());
        } 
        return solve(s,0,t,wordlen,dp);
    }
};