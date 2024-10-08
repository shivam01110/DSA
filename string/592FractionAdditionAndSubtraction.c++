#include <bits/stdc++.h>
using namespace std;

string fractionAddition(string expression) {
    int i=0,len=expression.size(),numerator=0,denominator=1;
    while(i<len){
        string numo="",deno="";
        while(expression[i]!='/'){
            numo+=expression[i];
            i++;
        }
        i++;
        int nextnume=stoi(numo);
        while(i<len && expression[i]!='+' && expression[i]!='-'){
            deno+=expression[i];
            i++;
        }
        int nextdeno=stoi(deno);
        int lcm=((denominator*nextdeno)/__gcd(denominator,nextdeno));
        numerator=((lcm/denominator)*numerator)+(lcm/nextdeno)*nextnume;
        int comFactor=__gcd(abs(numerator),lcm);
        numerator=numerator/comFactor;
        denominator=lcm/comFactor;
    }
    string res=to_string(numerator)+"/"+to_string(denominator);
    return res;
}

int main(){
    string num="+121235555";
    cout<<stoi(num)<<endl;
    return 0;
}