//time=O(m+n) m->string.length(),n->pattern.length()
//space=O(m)
#include <bits/stdc++.h>
using namespace std;

vector<int> piTable(string pattern){
    int l=pattern.length();
    vector<int> pi(l,0);
    for(int i=1;i<l;i++){
        if(pi[i-1]==0){
            pi[i]=(pattern[i]==pattern[0]);
        }
        else{
            pi[i]=(pattern[i]==pattern[pi[i-1]])?pi[i-1]+1:0;
        }
    }
    return pi;
}

int kmp(string str ,string pattern){
    vector<int> pi=piTable(pattern);
    int i=0,j=-1,n=pattern.length(),m=str.length();
    for(;i<m && j<n-1;){
        if(pattern[j+1]==str[i]){
            i++;
            j++;
        }
        else if(j==-1) i++;
        else j=pi[j]-1;
    }
    if(j==n-1) return i-n;  //index of str from where pattern will be found
    return -1;
}
int main(){
    string str="ababcabcabababd",pattern="ababd";
    vector<int> pi=piTable(pattern);
    for(int i=0;i<pi.size();i++){
        cout<<pi[i]<<" ";
    }
    cout<<endl;
    cout<<kmp(str,pattern)<<endl;
    return 0;
}