#include <iostream>
#include <vector>
using namespace std;
#ifndef PART2_H
#define PART2_H

// Function to preprocess the string by adding special characters between
// each pair of characters
// complexity: O(n)
string preprocess(string s)

{
    // Add a special character at the beginning and end of the string
    s = "^" + s + "$";
    // Insert a special character between each pair of characters
    for (int i = 1; i < s.length() - 1; i += 2)
        s.insert(i, "#");
    return s;

}

// Function to find the longest palindromic substring using Manacher's algorithm
// complexity: O(n)
pair<int,int> manacher(string s)
{
    // Preprocess the string
    s = preprocess(s);
    // Create a table to store the lengths of the palindromic substrings
    // centered at each character
    int n = s.length();
    vector<int> table(n,0);
    // Initialize variables to store the center and rightmost point of the
    // palindromic substring
    int center = 0;
    int right = 0;
    // Iterate through the string
    for (int i = 1; i < n - 1; i++)
    {
        // Find the mirrored index of the current character
        int mirror = 2 * center - i;
        // If the current character is within the palindromic substring
        // centered at the center, use the mirrored value from the table
        if (i < right)
            table[i] = min(right - i, table[mirror]);
        // Expand the palindromic substring centered at the current character
        // by checking the characters on either side
        while (s[i + 1 + table[i]] == s[i - 1 - table[i]])
            table[i]++;
        // Update the center and rightmost point of the palindromic substring
        // if necessary
        if (i + table[i] > right)
        {
            center = i;
            right = i + table[i];
        }
    }
    // Find the maximum value in the table
    int maxLength = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++)
    {
        // Check if the current element in the table is greater than the current maximum
        if (table[i] > maxLength)
        {
            maxLength = table[i];
            centerIndex = i;
        }
    }
    // Extract the longest palindromic substring from the original string
    int start = (centerIndex - maxLength) / 2;
    return make_pair(start, start + maxLength);
}

#endif