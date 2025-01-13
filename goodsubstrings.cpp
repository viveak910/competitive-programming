#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#define ll long long 

int main() {
    string s;
    string goodbad;
    cin >> s >> goodbad;
    ll k;
    cin >> k;
    
    ll n = s.length();
    ll uniqueCount = 0;
    unordered_set<string> uniqueSubstrings;

    for (int i = 0; i < n; i++) {
        int badCount = 0;
        string currentSubstring = "";
        
        for (int j = i; j < n; j++) {
            currentSubstring += s[j];
            if (goodbad[s[j] - 'a'] == '0') {
                badCount++;
            }
            if (badCount > k) {
                break;
            }
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstring);
                uniqueCount++;
            }
        }
    }

    cout << uniqueCount << endl;
    return 0;
}
