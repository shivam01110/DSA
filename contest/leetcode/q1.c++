#include <bits/stdc++.h>
using namespace std;

string solution1(string &forth){
    int xmin = 0 , xmax = 0;
    int x = 0 , y = 0;
    for(char d : forth){
        if(d == 'E') xmax = max(xmax , ++x);
        else if(d == 'W') xmin = min(xmin , --x);
        else y++;
    }
    string L = string(x + 1 - xmin , 'W') + string(y , 'S') + string(1 - xmin , 'E');
    string R = string(xmax + 1 - x , 'E') + string(y , 'S') + string(xmax + 1, 'W');
    return L.size() < R.size()?L:R;
}
string solution(string &forth){
    int len=forth.length(),left = 0 , right = 0,l = 0 , r = 0;
    for(int i=0;i<len;i++){
        char ch=forth[i];
        if(ch == 'E') right = max(right , ++l);
        else if(ch == 'W') left = min(left , --l);
        else r++;
    }
    string path1 = string(l + 1 - left , 'W') + string(r , 'S') + string(1 - left , 'E');
    string path2 = string(right + 1 - l , 'E') + string(r , 'S') + string(right + 1, 'W');
    if(path1.length()<path2.size()) return path1;
    return path2;
}

int main(){
    string forth="NENENWWWWN";
    cout<<solution(forth)<<endl;
    return 0;
}