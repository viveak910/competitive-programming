#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class TreeMatching {
private:
    vector<vector<int>> adj;  // Adjacency list
    vector<vector<int>> dp;   // dp[node][state] - state: 0=not taken, 1=taken
    
public:
    TreeMatching(int n) {
        adj.resize(n);
        dp.assign(n, vector<int>(2, -1));
    }
    
    void addEdge(int a, int b) {
        // Convert to 0-based indexing
        a--; b--;  // Since input is 1-based
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    void computeMatching(int node, int parent) {
        int notTaken = 0;
        int taken = 0;
        
        for (int child : adj[node]) {
            if (child == parent) continue;
            
            computeMatching(child, node);
            notTaken += max(dp[child][0], dp[child][1]);
        }
        
        taken = notTaken;
        
        for (int child : adj[node]) {
            if (child == parent) continue;
            
            int matchWithChild = notTaken - max(dp[child][0], dp[child][1]) + dp[child][0] + 1;
            taken = max(taken, matchWithChild);
        }
        
        dp[node][0] = notTaken;
        dp[node][1] = taken;
    }
    
    int getMaxMatching() {
        if (adj.empty()) return 0;
        computeMatching(0, -1);
        return max(dp[0][0], dp[0][1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    TreeMatching tree(n);
    
    // Read n-1 edges
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        tree.addEdge(x, y);  // addEdge will handle the conversion to 0-based indexing
    }
    
    cout << tree.getMaxMatching() << endl;
    
    return 0;
}