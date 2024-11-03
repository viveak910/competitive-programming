#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastIO(); 
    int t; 
    cin >> t; 
    while (t--) {
        int n; 
        cin >> n; // Number of notes
        vector<int> notes(n);
        
        for (int i = 0; i < n; i++) {
            cin >> notes[i]; // Read the notes
        }
        
        bool perfect = true; // Assume the melody is perfect
        for (int i = 1; i < n; i++) {
            int interval = abs(notes[i] - notes[i - 1]); // Calculate the interval
            if (interval != 5 && interval != 7) {
                perfect = false; // Mark as imperfect if interval is not 5 or 7
                break;
            }
        }
        
        cout << (perfect ? "YES" : "NO") << endl; // Output result
    }
    
    return 0;
}
