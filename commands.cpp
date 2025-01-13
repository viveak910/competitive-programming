#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void executeCommands(int n) {
    vector<string> pathStack;  // To track the current directory path

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        
        if (command == "pwd") {
            // Print the current path
            cout << "/";
            for (const string &dir : pathStack) {
                cout << dir << "/";
            }
            cout << endl;
        } else if (command == "cd") {
            string path;
            cin >> path;  // Read the path argument for cd

            // Determine if it's an absolute or relative path
            bool isAbsolute = (path[0] == '/');
            if (isAbsolute) {
                pathStack.clear();  // Start from the root for an absolute path
            }

            // Use a stringstream to split path by '/'
            stringstream ss(path);
            string segment;
            while (getline(ss, segment, '/')) {
                if (segment == "" || segment == ".") {
                    continue;  // Ignore empty or current directory (.)
                } else if (segment == "..") {
                    if (!pathStack.empty()) {
                        pathStack.pop_back();  // Move up a directory
                    }
                } else {
                    pathStack.push_back(segment);  // Move into the specified directory
                }
            }
        }
    }
}

int main() {
    fastIO();

    int n;
    cin >> n;  // Number of commands
    executeCommands(n);

    return 0;
}
