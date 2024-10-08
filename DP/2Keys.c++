#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    vector<int> steps(n+1,0);
    steps[1]=0;
    for(int i=2;i<n+1;i++){
        steps[i]=i;
        for(int j=n/2;j>=2;j--){
            if(i%j==0){
                steps[i]=min(steps[i],steps[j]+i/j);
            }
        }
    }
    return steps[n];
}

int main(){
    cout<<minSteps(1)<<endl;
    return 0;
}