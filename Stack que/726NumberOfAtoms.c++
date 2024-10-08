#include <bits/stdc++.h>
using namespace std;

string countOfAtoms(string formula) {
    stack<pair<string,int>> st1,st2;
    map<string,int> m;
    int i=0,len=formula.length();
    while(i<len){
        if(('A'<=formula[i] && formula[i]<='Z')||(formula[i]=='(')){
            string ele="";ele+=formula[i];
            i++;
            while(i<len && 'a'<=formula[i] && formula[i]<='z'){
                ele+=formula[i];
                i++;
            }
            int cnt=0;
            while(i<len && '0'<=formula[i] && formula[i]<='9'){
                int d=formula[i]-'0';
                cnt=cnt*10+d;
                i++;
            }
            st1.push({ele,max(1,cnt)});
        }
        else{
            i++;
            int mul=0;
            while(i<len && '0'<=formula[i] && formula[i]<='9'){
                int d=formula[i]-'0';
                mul=mul*10+d;
                i++;
            }
            while(!st1.empty() && st1.top().first!="("){
                st1.top().second=st1.top().second*max(1,mul);
                st2.push(st1.top());
                st1.pop();
            }
            st1.pop();
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    string res="";
    while(!st1.empty()){
        m[st1.top().first]+=st1.top().second;
        st1.pop();
    }
    for(auto it=m.begin();it!=m.end();it++){
        res+=it->first;
        if(it->second!=1) res+=to_string(it->second);
    }
    return res;
}

int main(){
    string formula = "K4(ON(SO3)2)2";
    cout<<countOfAtoms(formula)<<endl;
    return 0;
}