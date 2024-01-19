// =========================================================
// File: main.cpp
// Authors:
// Alexa Jimena Ramirez Ortiz - A00833943
// Bella Elisabet Perales Melendez y Alcocer - A00833423
// Date: 01/19/2024
// =========================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

#include "part1.h"
#include "part2.h"
#include "part3.h"

using namespace std;
// complexity: O(n)
void readTransmissions(vector<string> &transmissions){
    //Read transmissions
    ifstream file;
    file.open("transmission1.txt");
    string line;
    while(getline(file, line)){
        transmissions.push_back(line);
    }
    file.close();

    file.open("transmission2.txt");
    while(getline(file, line)){
        transmissions.push_back(line);
    }
    file.close();
}

// complexity: O(n)
void readMaliciousCodes(vector<string> &maliciousCodes){
    //Read malicious codes
    ifstream file;
    file.open("mcode1.txt");
    string line;
    while(getline(file, line)){
        maliciousCodes.push_back(line);
    }
    file.close();

    file.open("mcode2.txt");
    while(getline(file, line)){
        maliciousCodes.push_back(line);
    }
    file.close();

    file.open("mcode3.txt");
    while(getline(file, line)){
        maliciousCodes.push_back(line);
    }
    file.close();
}

int main(){
    vector<string> transmissions; 
    vector<string> maliciousCodes;
    //Read transmissions
    readTransmissions(transmissions);
    //Read malicious codes
    readMaliciousCodes(maliciousCodes);

    // Part 1: Search for malicious codes in transmissions
    cout << "transmission1.txt" << endl;
    for(int i = 0; i < maliciousCodes.size(); i++){
        cout << "code" <<i+1<<".txt - " ;
        KMP(transmissions[0], maliciousCodes[i]);
    } 
    cout << "transmission2.txt" << endl;
    for(int i = 0; i < maliciousCodes.size(); i++){
        cout << "code" <<i+1<<".txt - " ;
        KMP(transmissions[1], maliciousCodes[i]);
    } 

    cout<< "------------------------------------"<<endl;
    // Part 2: Find longest palindrome in transmissions
    pair<int, int> p = manacher(transmissions[0]);
    cout << "transmission1.txt:" << endl;
    cout << "mirrored code found, start at " << p.first << ", ended at " << p.second << endl;

    cout << "transmission2.txt:" << endl;
    p = manacher(transmissions[1]);
    cout << "mirrored code found, start at " << p.first << ", ended at " << p.second << endl;
    cout<< "------------------------------------"<<endl;
    // Part 3: Find longest common substring in transmissions
    cout<< "The longest common substring between transmission1.txt and transmission2.txt is "
    << longestCommonSubstring(transmissions[0], transmissions[1]) << " characters long." << endl;
    return 0;
}