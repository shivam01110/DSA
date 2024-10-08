#include <bits/stdc++.h>
using namespace std;

int solve(string s,int x,int y,char t,char b){
    stack<char> st;
    int len=s.length(),c1=0,c2=0;//c1->"ba",c2->"ab"
    for(int i=0;i<len;i++){
        if(!st.empty() && st.top()==b && s[i]==t){
            c1++;
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    //string after performing first type of operation i.e after removing "ba"
    int l=st.size();
    string op(l,'a');
    while(!st.empty()){
        l--;
        op[l]=st.top();
        st.pop();
    }
    for(int i=0;i<op.length();i++){
        if(!st.empty() && st.top()==t && op[i]==b){
            c2++;
            st.pop();
        }
        else{
            st.push(op[i]);
        }
    }
    cout<<c1<<" "<<c2<<endl;
    return c1*y+c2*x;
}

int main(){
    string s="aabbaaxybbaabb";
    int x=5,y=4;
    int gain1=solve(s,x,y,'a','b');
    int gain2=solve(s,y,x,'b','a');
    cout<<gain1<< " "<<gain2<<endl;
    cout<<max(gain1,gain2)<<endl;
    return 0;
}