#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cellCount;  // Initialize in main loop for each test case

void dfs(vector<vector<char>>& v, int i, int j, string s, vector<vector<int>>& visited) {
    if (s == "1543") {
        cellCount++;
        return;
    }

    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || visited[i][j] == 1 || s.size() >= 4) {
        return;
    }

    // Mark the current cell as visited
    visited[i][j] = 1;

    // Move clockwise
    dfs(v, i, j + 1, s + v[i][j], visited);  // Right
    dfs(v, i + 1, j, s + v[i][j], visited);  // Down
    dfs(v, i, j - 1, s + v[i][j], visited);  // Left
    dfs(v, i - 1, j, s + v[i][j], visited);  // Up

    // Unmark the cell after backtracking
    visited[i][j] = 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Initialize grid
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        // Reset cell count for each test case
        cellCount = 0;

        // Perform DFS from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> visited(n, vector<int>(m, 0));
                dfs(v, i, j, "", visited);
            }
        }

        // Output the result for the current test case
        cout << cellCount << endl;
    }

    return 0;
}
