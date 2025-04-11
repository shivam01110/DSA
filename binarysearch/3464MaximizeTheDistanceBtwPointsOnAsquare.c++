#include <bits/stdc++.h>
using namespace std;


#define ll long long

class Solution {
public:

    ll PointOnline(ll x,ll y,ll side){
        if(y==0) return x;  //points on side--->(0,0)---->(0,side);
        if(x==side) return side+y; //points on side--->(side,0)---->(side,side);
        if(y==side) return 3LL*side-x;  //points on side--->(0,side)---->(side,side);
        return 4LL*side-y;    //points on side--->(0,0)---->(side,0);
    }

    bool check(vector<ll>& extended,ll d,ll perimeter,int k){
        int n=extended.size()/2;
        for(int i=0;i<n;i++){
            int cnt=1;  //consider this as 1st point
            ll curr=extended[i];
            for(;cnt<k;){
                ll req=curr+d;
                auto next=lower_bound(extended.begin()+i+1,extended.begin()+i+n,req);
                if(next==extended.end()) break; //req is greater than extended.back()
                curr=*(next);
                cnt++;
            }
            if(cnt==k && (extended[i]+perimeter-curr)>=d) return true;      //distance between the first and last selected point will be =start+end-perimeter(due to closed nature of square)
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<ll> dist(n,0);
        vector<ll> extended(2*n,0);
        ll perimeter=4LL*side;
        for(int i=0;i<points.size();i++){
            dist[i]=PointOnline(points[i][0],points[i][1],(ll)side);
        }
        sort(dist.begin(),dist.end());
        for(int i=0;i<points.size();i++){
            extended[i]=dist[i];
            extended[i+n]=dist[i]+perimeter;
        }
        ll low=0,high=2*1LL*side,ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(extended,mid,perimeter,k)){
                ans=max(mid,ans);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};