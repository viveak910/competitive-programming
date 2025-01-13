#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<int> st; // Stack to store the indices of '(' characters
    vector<int> dp(s.size(), 0); // dp[i] will store the length of the longest valid subsequence ending at index i
    int max_len = 0; // To store the maximum length of valid subsequences
    int count = 0;   // To count the number of subsequences with the maximum length

    // Traverse through the string
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            // Push the index of '(' onto the stack
            st.push(i);
        } else if (s[i] == ')') {
            // If there's a matching '(' in the stack, form a valid sequence
            if (!st.empty()) {
                int open_idx = st.top(); // Index of the matching '('
                st.pop();

                // Calculate the length of the valid sequence
                dp[i] = i - open_idx + 1 + (open_idx > 0 ? dp[open_idx - 1] : 0);

                // Update the maximum length and count
                if (dp[i] > max_len) {
                    max_len = dp[i];
                    count = 1;
                } else if (dp[i] == max_len) {
                    count++;
                }
            }
        }
    }

    // If no valid sequence is found, the default answer is 0 1
    if (max_len == 0) {
        cout << "0 1" << endl;
    } else {
        cout << max_len << " " << count << endl;
    }

    return 0;
}
