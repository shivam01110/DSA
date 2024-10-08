#include <bits/stdc++.h>
using namespace std;


int maxDistToClosest(vector<int>& seats) {
    int n=seats.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    int lastleft=-1,lastright=-1;
    for(int i=0;i<n;i++){
        if(seats[i]) lastleft=i;
        else left[i]=(lastleft!=-1)?abs(i-lastleft):INT_MAX;
        if(seats[n-i-1]) lastright=n-i-1;
        else right[n-i-1]=(lastright!=-1)?abs(n-i-1-lastright):INT_MAX;
    }
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        res=max(res,min(left[i],right[i]));
    }
    return res;
}

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6, 8};

    int target = 9;

    // lower_bound
    auto lower = std::lower_bound(v.begin(), v.end(), target);
    std::cout << "Lower bound of " << target << " is at index: " 
              << (lower - v.begin()) << std::endl;

    // upper_bound
    auto upper = std::upper_bound(v.begin(), v.end(), target);
    std::cout << "Upper bound of " << target << " is at index: " 
              << (upper - v.begin()) << std::endl;

    return 0;
}