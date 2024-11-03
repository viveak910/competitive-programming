#include<iostream>
using namespace std;
#include <vector>
#include <queue>

int main(){
    int m, n; 
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    pair<int, int> source, destination, moverule;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    cin >> moverule.first >> moverule.second;

    queue<pair<int, int>> q;
    q.push(source);
    int path = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[source.first][source.second] = 1;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            pair<int, int> temp = q.front();
            q.pop();

            if(temp == destination){
                cout << path << endl;
                return 0;
            }

            int x = temp.first + moverule.first;
            int y = temp.second + moverule.second;
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0 && !visited[x][y]){
                q.push({x, y});
                visited[x][y] = 1;
            }

            x = temp.first + moverule.second;
            y = temp.second - moverule.first;
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0 && !visited[x][y]){
                q.push({x, y});
                visited[x][y] = 1;
            }

            x = temp.first - moverule.second;
            y = temp.second + moverule.first;
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0 && !visited[x][y]){
                q.push({x, y});
                visited[x][y] = 1;
            }

            x = temp.first - moverule.first;
            y = temp.second - moverule.second;
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0 && !visited[x][y]){
                q.push({x, y});
                visited[x][y] = 1;
            }
        }
        path++;
    }

    cout << -1 << endl;
    return 0; 
}