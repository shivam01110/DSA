#include <bits/stdc++.h>
using namespace std;

bool check(string a){
    bool cap=false,small=false;
    for(int i=0;i<a.length();i++){
        if(!isalnum(a[i])) return true;
        if(a[i]>='A' && a[i]<='Z') cap=true;
        if(a[i]>='a' && a[i]<='z') small=true;
        if(cap && small) return true;
    }
    return false;
}
void solve(string& a,string& b){
    if(check(a) || check(b)) {cout<<-1<<endl; return ;}
    unordered_map<char,int> m1,m2;
    for(auto c:a){
        m1[c]++;
    }
    for(auto c:b){
        m2[c]++;
    }
    int remove=0,updates=0;
    for(auto it=m2.begin();it!=m2.end();it++){
        if(m1.find(it->first)!=m1.end()){
            if(m1[it->first]>m2[it->first]){
                remove+=(m1[it->first]-m2[it->first]);
            }
            else{
                updates+=(m2[it->first]-m1[it->first]);
            }
        }
        else{
            updates+=m2[it->first];
        }
    }
    for(auto it=m1.begin();it!=m1.end();it++){
        if(m2.find(it->first)==m2.end()){
            remove+=m1[it->first];
        }
    }
    cout<<updates<<" "<<remove<<endl;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        string b;
        cin>>b;
        solve(a,b);
    }
    return 0;
}


