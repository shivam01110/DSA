#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  int e;
  int odd=0;
  for(int i=0;i<n;i++){
    cin>>e;
    if(e%2) odd++;
  }
  if(odd%2) cout<<"NO";
  else cout<<"YES";
  cout<<'\n';
}

int main(){
  solve();
  return 0;
}