#ifndef HW1_KMP_H
#define HW1_KMP_H

#include<iostream>
#include<string>
#include<vector>

#define MAX_N 102

using namespace std;

int fail[MAX_N], matched_pos[MAX_N];
vector<int> pattern_order;

// calculate fail function of pattern order
void pre_kmp(int size) {
    fail[0] = 0;
    int k = 0;
    for (int i = 1; i < size; i++) {
        while (k > 0 && pattern_order[k] != pattern_order[i]) {
            k = fail[k - 1];
        }
        if (pattern_order[k] == pattern_order[i]) {
            k = k + 1;
        }
        fail[i] = k;
    }
}

// calculate result of N KMP simultaneously
void kmp(vector<int> &Aho_result, int row) {
    for (int col = 0; col < Aho_result.size(); col++) {
        while (matched_pos[col] > 0 && pattern_order[matched_pos[col]] != Aho_result[col])
            matched_pos[col] = fail[matched_pos[col] - 1];
        
        if (pattern_order[matched_pos[col]] == Aho_result[col])
            matched_pos[col] = matched_pos[col] + 1;
        
        if (matched_pos[col] == (pattern_order.size())) {
            cout << row << ' ' << col << "\n";
            matched_pos[col] = fail[matched_pos[col] - 1];
        }
    }
}

#endif //HW1_KMP_H
