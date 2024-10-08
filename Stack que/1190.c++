#include <bits/stdc++.h>
using namespace std;

string solve(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            string rev="";
            while(st.top()!='('){
                rev+=st.top();
                st.pop();
            }
            st.pop();
            for(int i=0;i<rev.length();i++){
                st.push(rev[i]);
            }
        }
        else{
            st.push(s[i]);
        }
    }
    int len=st.size();
    string ans(len,'_');
    while(!st.empty()){
        len--;
        ans[len]=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s="()";
    cout<<solve(s)<<endl;
    return 0;
}