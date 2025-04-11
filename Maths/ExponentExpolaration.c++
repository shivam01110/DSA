#include <bits/stdc++.h>
using namespace std;

#define ll long long

int logab(int a,int b){
    if(a==1) return (b==1)?1:-1;
    if (b==1) return 0;
    int res=0;
    while(b!=1 && b%a==0){
        b=b/a;
        res++;
    }
    return (b==1)?res:-1;
}

std::vector<std::pair<int, int>> x_power_y_pairs(int n) {
    // Write your logic here.
    // Return a vector of pairs [X, Y] where X^Y equals n
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int res=logab(i,n);
        if(res!=-1) v.push_back(make_pair(i,res));
    }
    return v;
}

int main() {
    int n;
    std::cin >> n;
    
    // Call the user logic function
    std::vector<std::pair<int, int>> pairs = x_power_y_pairs(n);
    
    // Output the count of valid pairs
    std::cout << pairs.size() << std::endl;
    
    // Output each pair
    for (const auto& pair : pairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    
    return 0;
}