#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
vector<int> tree[MAXN];
int dist_from_u[MAXN], dist_from_v[MAXN];
int n;

// BFS function to calculate distances from a given node
pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest_node = start;
    int max_dist = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : tree[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > max_dist) {
                    max_dist = dist[neighbor];
                    farthest_node = neighbor;
                }
            }
        }
    }

    return {farthest_node, max_dist};
}

void calculate_distances(int start, int dist[]) {
    queue<int> q;
    fill(dist, dist + n + 1, -1);
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : tree[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Step 1: Find one endpoint of the diameter
    int u = bfs(1).first;

    // Step 2: Find the other endpoint of the diameter
    auto [v, diameter] = bfs(u);

    // Step 3: Calculate distances from u and v
    calculate_distances(u, dist_from_u);
    calculate_distances(v, dist_from_v);

    // Step 4: Answer queries for each node
    for (int i = 1; i <= n; ++i) {
        int new_diameter = max(diameter, max(dist_from_u[i], dist_from_v[i]) + 1);
        cout << new_diameter << "\n";
    }

    return 0;
}
