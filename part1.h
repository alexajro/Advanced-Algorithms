#include <iostream>
using namespace std;
#ifndef PART1_H
#define PART1_H

// Determine if one of the malicious code is found in the transmission.
// If it is found, return "true" and the position of the malicious code in the transmission.
// KMP implementation

// complexity: O(n)
// Finding the longest prefix that is also a suffix of the pattern
void preprocessing(string pattern, int length, int *lps){
    int len = 0;
    // act as a starting point
    lps[0] = 0;
    
    int i = 1;

    while(i < length){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

// complexity: O(n)
void KMP(string transmission, string maliciousCode){
    int n = transmission.length();
    int m = maliciousCode.length();
    int lps[m];

    // Preprocess the pattern (malicious code)
    preprocessing(maliciousCode, m, lps);

    int i = 0;  // index for transmission
    int j = 0;  // index for maliciousCode

    while (i < n) {
        //If the current character in the transmission matches the current character in the malicious code
        //Move to the next character to check if the next match
        if (transmission[i] == maliciousCode[j]) {
            i++;
            j++;
        }
        // If the whole pattern is found, return true
        if (j == m) {
            cout << "true, start at position " << i - j << endl;
            return; // Terminate the function once the full malicious code is found

        } else if (i < n && transmission[i] != maliciousCode[j]) {
            // If the current character in the transmission does not match the current character in the malicious code
            if (j != 0) {
                // Move to the character in the malicious code that matches the backwards of the current character in the transmission
                // Basing on the lps array
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << "false" << endl; // If the whole transmission is checked and no match is found
}



#endif