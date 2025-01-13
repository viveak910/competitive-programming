#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute DFS order and subtree sizes
void countsubtree(vector<vector<int>>& adj, vector<int>& dp, vector<int>& start, vector<int>& dfs, int node, int& index) {
    start[node] = index;         // Record the start index of this node in DFS order
    dfs[index++] = node;         // Add the node to the DFS order

    dp[node] = 1;                // Initialize subtree size to 1 (count itself)
    for (int neighbor : adj[node]) {
        if (dp[neighbor] == 0) { // If not visited
            countsubtree(adj, dp, start, dfs, neighbor, index);
            dp[node] += dp[neighbor]; // Add child's subtree size
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize adjacency list (1-based indexing)
    vector<vector<int>> adj(n + 1);

    // Read the edges
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i); // Add edge from parent to child
    }

    // Arrays for subtree sizes, DFS order, and start indices
    vector<int> dp(n + 1, 0);      // Subtree sizes
    vector<int> start(n + 1, 0);   // Start index in DFS order
    vector<int> dfs(n + 1);        // DFS order
    int index = 0;

    // Perform DFS from the root (node 1)
    countsubtree(adj, dp, start, dfs, 1, index);

    // Process queries
    while (q--) {
        int node, k;
        cin >> node >> k;

        if (k > dp[node]) {
            cout << -1 << endl; // Query exceeds subtree size
        } else {
            cout << dfs[start[node] + k - 1] << endl; // Output the k-th node in DFS order
        }
    }

    return 0;
}
