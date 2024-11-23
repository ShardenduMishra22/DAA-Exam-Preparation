#include <bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int i, int j, string& res) {
    if (i >= str1.size() || j >= str2.size()) {
        return 0;
    }

    if (str1[i] == str2[j]) {
        res.push_back(str1[i]);
        return 1 + solve(str1, str2, i + 1, j + 1, res);
    }

    string temp1 = res, temp2 = res;
    int ans1 = solve(str1, str2, i + 1, j, temp1);
    int ans2 = solve(str1, str2, i, j + 1, temp2);

    if (ans1 > ans2) {
        res = temp1;
        return ans1;
    } else {
        res = temp2;
        return ans2;
    }
}

int main() {
    string str1 = "AGGTAYB";
    string str2 = "GXTXAYB";

    string res; // To store the LCS string

    // Calculate LCS length
    int length = solve(str1, str2, 0, 0, res);

    // Output the results
    cout << "Length of Longest Common Subsequence: " << length << endl;
    cout << "Longest Common Subsequence: " << res << endl;

    return 0;
}
