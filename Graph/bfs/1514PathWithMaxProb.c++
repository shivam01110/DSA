// The time complexity of the code is:

// 1. **Graph Construction**:  
//    - Building the adjacency list takes O(m), where m is the number of edges.

// 2. **Main Loop (Dijkstra-like)**:  
//    - The `while` loop runs until the set is empty. Each operation (insertion, deletion) in the set takes O(log n), where n is the number of nodes.
//    - For each node, its neighbors are processed, resulting in a total time of O(m log n) for all edge relaxations.

// ### Total Time Complexity:
// - **Graph construction**: O(m)
// - **Dijkstra loop**: O(m log n)

// Thus, the overall complexity is O(m log n).


#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<pair<int,double>> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    vector<double> prob(n,0);
    set<pair<double,int>,greater<>> st;     //store the set {prob[node],node} in descending order
    prob[start_node]=1;     //since we are starting from start_node so prob[start_node]=1
    for(auto neighbour:adj[start_node]){
        st.insert({neighbour.second,neighbour.first});
        prob[neighbour.first]=neighbour.second;
    }
    while(!st.empty()){
        auto t=*(st.begin());
        st.erase(t);
        double p=t.first;
        for(auto neighbour:adj[t.second]){
            int node=neighbour.first;
            double newprob=p*neighbour.second;
            if(newprob>prob[node]){
                st.erase({prob[node],node});
                prob[node]=newprob;
                st.insert({newprob,node});
            }
        }
    }
    return prob[end_node];
}