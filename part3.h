#include <iostream>
#include <vector>
using namespace std;
#ifndef PART3_H
#define PART3_H

// complexity: O(n^2)
int longestCommonSubstring(const string A, const string B) {
    // Get the lengths of the input strings
    int m = A.size();
    int n = B.size();
    // Create a matrix to store lengths of longest common suffixes
    vector<vector<int>> M(m + 1, vector<int>(n + 1));
    int maximum = 0; // variable to store the length of the longest common substring
    // Fill the matrix
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If either of the strings has reached its end, set the value to 0
            if (i == 0 || j == 0) {
                M[i][j] = 0;
            }
            // If characters match, update the length of common substring
             else if (A[i - 1] == B[j - 1]) {
                M[i][j] = M[i - 1][j - 1] + 1;
                maximum = max(M[i][j], maximum);
            } 
            // If characters don't match, set the length to 0
            else {
                M[i][j] = 0;
            }
        }
    }

    if (maximum == 0) {
        // No common substring
        return 0;
    } else {
        return maximum;
    }
}

#endif