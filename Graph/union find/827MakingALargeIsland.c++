#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression for quickly finding parent
    }
    void unionBySize(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if (parent_u == parent_v)
            return;
        if (size[parent_u] > size[parent_v])
        {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        }
        else
        {
            size[parent_v] += size[parent_u];
            parent[parent_u] = parent_v;
        }
    }
};

class Solution
{
public:
    int dr[5] = {1, 0, -1, 0, 1};
    int largestIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int cell = n * n;
        DSU dsu(cell);
        int res=INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int x = i + dr[d], y = j + dr[d + 1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y])
                        {
                            dsu.unionBySize(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    set<int> s;
                    for (int d = 0; d < 4; d++)
                    {
                        int x = i + dr[d], y = j + dr[d + 1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y])
                        {
                            s.insert(dsu.findParent(x*n+y));
                        }
                    }
                    int currsize=1; //convert 0 --> 1
                    for(auto it=s.begin();it!=s.end();it++){
                        currsize+=dsu.size[*(it)];
                    }
                    res=max(res,currsize);
                }
                else  res=max(res,dsu.size[dsu.findParent(i*n+j)]);
            }
        }
        return res;
    }
};