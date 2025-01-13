#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 200001; 
int num_nodes; 
 
vector<int> adjacency_list[MAX_NODES];
long long subtree_size[MAX_NODES], distance_sum[MAX_NODES];

// DFS 1: Calculate the distance sum for the root node and subtree sizes
void calculate_distance_and_subtree_sizes(int current_node, int parent_node, long long current_depth) {
    // Update the total distance sum for the root node
    distance_sum[1] += current_depth;
    subtree_size[current_node] = 1; // Count the current node in its subtree

    for (int neighbor : adjacency_list[current_node]) {
        if (neighbor != parent_node) {
            // Recur for child nodes
            calculate_distance_and_subtree_sizes(neighbor, current_node, current_depth + 1);
            // Update the subtree size of the current node
            subtree_size[current_node] += subtree_size[neighbor];
        }
    }
}

// DFS 2: Calculate distance sums for all other nodes
void calculate_all_distances(int current_node, int parent_node) {
    for (int neighbor : adjacency_list[current_node]) {
        if (neighbor != parent_node) {
            // Update the distance sum for the child node based on the parent
            distance_sum[neighbor] = distance_sum[current_node] + num_nodes - 2 * subtree_size[neighbor];
            // Recur for child nodes
            calculate_all_distances(neighbor, current_node);
        }
    }
}

int main() {
    // Input: Number of nodes
    cin >> num_nodes;

    // Input: Edges of the tree
    for (int i = 1; i < num_nodes; i++) {
        int node_a, node_b;
        cin >> node_a >> node_b;
        adjacency_list[node_a].push_back(node_b);
        adjacency_list[node_b].push_back(node_a);
    }

    // Step 1: Calculate distance sum for the root node and subtree sizes
    calculate_distance_and_subtree_sizes(1, 0, 0);

    // Step 2: Calculate distance sums for all other nodes
    calculate_all_distances(1, 0);

    // Output: Distance sums for all nodes
    for (int i = 1; i <= num_nodes; i++) {
        cout << distance_sum[i] << " ";
    }
    cout << endl;

    return 0;
}
