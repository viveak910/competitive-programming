#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair
using namespace std;

// Function to perform BFS and return the farthest node and its distance
pair<int, int> bfs_farthest(const vector<vector<int>>& tree, int start) {
    int n = tree.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // (node, distance)
    q.push({start, 0});
    visited[start] = true;

    int farthest_node = start;
    int max_distance = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        // Update farthest node and max distance
        if (distance > max_distance) {
            farthest_node = node;
            max_distance = distance;
        }

        // Traverse neighbors
        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, distance + 1});
            }
        }
    }

    return {farthest_node, max_distance};
}

// Function to find the diameter of the tree
int find_tree_diameter(const vector<vector<int>>& tree ) {
    // Step 1: Find the farthest node from an arbitrary starting point (e.g., node 0)
    
    pair<int, int> first_bfs = bfs_farthest(tree, 0);

    // Step 2: Find the farthest node from the above farthest node
    pair<int, int> second_bfs = bfs_farthest(tree, first_bfs.first);

    // The diameter of the tree is the distance from the second BFS
    return second_bfs.second;
}

int main() {
    int n; 
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    int diameter = find_tree_diameter(tree);
    cout <<  3* diameter << endl;

    return 0;
}
