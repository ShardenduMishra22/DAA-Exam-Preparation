#include <bits/stdc++.h>
using namespace std;

void computeLPS(vector<int>& lps, string pattern) {
    int m = pattern.size();
    lps[0] = 0;
    int len = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        lps[i] = len;
    }
}

void solve(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps(m);
    computeLPS(lps, pattern); // Corrected function call to compute LPS

    int i = 0, j = 0; // i is for text, j is for pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) { // A match is found
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) { // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    solve(text, pattern);
    return 0;
}
