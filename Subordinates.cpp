#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and calculate subordinate counts
int dfs(int employee, vector< vector<int> >& tree, vector<int>& subordinate_count) {
    int count = 0;
    for (int subordinate : tree[employee]) {
        count += 1 + dfs(subordinate, tree, subordinate_count);
    }
    subordinate_count[employee] = count;
    return count;
}

int main() {
    int n;
    cin >> n;

    // Read the input and construct the tree
    vector< vector<int> > tree(n + 1); // Adjacency list for the company hierarchy
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }

    // Array to store the subordinate counts
    vector<int> subordinate_count(n + 1, 0);

    // Perform DFS starting from the general director (employee 1)
    dfs(1, tree, subordinate_count);

    // Output the subordinate counts for employees 1 to n
    for (int i = 1; i <= n; ++i) {
        cout << subordinate_count[i] << " ";
    }
    cout << endl;

    return 0;
}
