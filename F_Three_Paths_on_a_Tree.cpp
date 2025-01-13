#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

// Global vectors for parent tracking and the adjacency list of the graph
vector<int> p; 
vector<vector<int>> g;

// DFS function to find the farthest node from a given vertex
pair<int, int> dfs(int v, int par = -1, int dist = 0) {
    p[v] = par;  // Set the parent of the current vertex
    pair<int, int> res = make_pair(dist, v);  // Initialize the result with the distance and vertex

    // Explore all the adjacent nodes
    for (auto to : g[v]) {
        if (to == par) continue;  // Skip the parent node
        res = max(res, dfs(to, v, dist + 1));  // Recursively find the farthest node
    }
    return res;  // Return the farthest node and its distance
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);  // For debugging: redirect input from file
    // freopen("output.txt", "w", stdout); // For debugging: redirect output to file
#endif

    int n;
    cin >> n;  // Read the number of vertices
    p = vector<int>(n);  // Initialize parent vector with size n
    g = vector<vector<int>>(n);  // Initialize graph as an adjacency list

    // Read the edges of the graph
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;  // Read edge between x and y
        --x, --y;  // Convert to 0-based indexing
        g[x].push_back(y);  // Add y to the adjacency list of x
        g[y].push_back(x);  // Add x to the adjacency list of y
    }

    // Find the farthest node from vertex 0 (first DFS)
    pair<int, int> da = dfs(0);
    // Find the farthest node from da.y (second DFS to find the diameter's endpoint)
    pair<int, int> db = dfs(da.y);

    // Reconstruct the diameter path
    vector<int> diam;
    int v = db.y;
    while (v != da.y) {
        diam.push_back(v);
        v = p[v];  // Backtrack to the parent of the current node
    }
    diam.push_back(da.y);  // Add the starting node (da.y) to the path

    // If the diameter length is equal to the number of vertices, print the full tree
    if (int(diam.size()) == n) {
        cout << n - 1 << " " << endl;  // Total edges = n - 1
        cout << diam[0] + 1 << " " << diam[1] + 1 << " " << diam.back() + 1 << endl;
    } else {
        // Otherwise, perform a BFS to find the farthest node from the diameter path
        queue<int> q;
        vector<int> d(n, -1);  // Distance array initialized to -1
        for (auto v : diam) {
            d[v] = 0;  // Distance from the diameter path nodes is 0
            q.push(v);  // Enqueue all diameter nodes
        }

        // BFS to calculate the maximum distance from any node in the diameter path
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto to : g[v]) {
                if (d[to] == -1) {  // If the node has not been visited
                    d[to] = d[v] + 1;  // Set its distance
                    q.push(to);  // Enqueue it for further exploration
                }
            }
        }

        // Find the farthest node from the diameter path
        pair<int, int> mx = make_pair(d[0], 0);
        for (int v = 1; v < n; ++v) {
            mx = max(mx, make_pair(d[v], v));  // Track the maximum distance and its corresponding node
        }

        // Output the result: total edges plus the farthest node's distance
        cout << int(diam.size()) - 1 + mx.x << endl;
        cout << diam[0] + 1 << " " << mx.y + 1 << " " << diam.back() + 1 << endl;
    }

    return 0;
}
