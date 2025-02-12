#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Leaf {
    int x, y;
    bool operator<(const Leaf &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    
    string commands;
    cin >> commands;
    
    vector<Leaf> leaves(N);
    for (int i = 0; i < N; i++) {
        cin >> leaves[i].x >> leaves[i].y;
    }
    
    // Sort leaves to allow efficient searching
    sort(leaves.begin(), leaves.end()); 
    
    Leaf freddy = leaves[0]; // Freddy starts from the first leaf
    set<Leaf> leafSet(leaves.begin(), leaves.end()); // Set to keep track of available leaves
    
    leafSet.erase(freddy); // Remove Freddy's starting leaf from the set
    
    // Process each command
    for (char command : commands) {
        Leaf nextLeaf;
        switch (command) {
            case 'A': nextLeaf = {freddy.x + 1, freddy.y + 1}; break;
            case 'B': nextLeaf = {freddy.x + 1, freddy.y - 1}; break;
            case 'C': nextLeaf = {freddy.x - 1, freddy.y + 1}; break;
            case 'D': nextLeaf = {freddy.x - 1, freddy.y - 1}; break;
        }
        
        // Look for the leaf in the specified direction
        auto it = leafSet.lower_bound(nextLeaf);
        if (it != leafSet.end() && (it->x == nextLeaf.x || it->y == nextLeaf.y)) {
            freddy = *it;
            leafSet.erase(it); // Freddy jumps to the new leaf and removes it from the set
        }
    }
    
    cout << freddy.x << " " << freddy.y << endl; // Output Freddy's final position
    return 0;
}
