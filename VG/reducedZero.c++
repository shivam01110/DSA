#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to be implemented by the user
vector<int> p;
void prime(){
    vector<int> a(1717172,1);
    a[0]=1,a[1]=0;
    for(int i=2;i<=sqrt(1000);i++){
        if(a[i]==1){
            for(int j=i*i;j<=1000;j=j+i){
                a[j]=0;
            }
        }
        if(a[i-1]==1){
            p.push_back(i-1);
        }
    }
}
int user_logic(int n) {
    // Write your logic here
    int steps=0;
    int l=p.size();
    while(n!=0){
        bool divisible=0;
        for(int i=0;i<l;i++){
            if(n%p[i]==0){
                divisible=1;
                n-=p[i];
                steps++;
                break;
            }
        }
        if(divisible==0){
            return steps+1;
        }
    }

    return steps; // Placeholder return
}

int main() {
    prime();
    // int n;
    // cin >> n;

    // Call user logic function and print the output
    // int result = user_logic(n);
    // cout << result << endl;
    for(int i=0;i<(int)p.size();i++){
        cout<<p[i]<<'\t';
    }

    return 0;
}