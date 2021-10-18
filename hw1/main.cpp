#include <iostream>
#include<vector>

#include "KMP.h"
#include "Aho_corasick.h"

using namespace std;

int N, M;
string pattern[MAX_N];

// Baker-Bird Algorithm
int main(int argc, char **argv) {
    // 파일 입출력을 위해 표준 입출력을 파일에 읽고 쓸 수 있게 함
    FILE* _1 = freopen(argv[1], "r", stdin);
    FILE* _2 = freopen(argv[2], "w", stdout);
    
    // input pattern (M, M)
    cin >> M >> N;
    for(int i=0;i<M;i++)
        cin >> pattern[i];
    
    // build Trie of pattern
    Trie* root = new Trie;
    for (int i = 0; i < M; ++i)
        pattern_order.push_back(root->Insert(pattern[i], i+1));
    
    // calculate pattern_order. ex. 12312
    pre_kmp(M);
    // create fail link in trie
    root->create_fail_link();
    
    string text;
    for(int i=0;i<N;i++){
        cin >> text;
        // calculate result of Aho-corasick, one row by onw row
        vector<int> Aho_result = row_Aho(text, root, N);
        // calculate result of N KMP simultaneously
        kmp(Aho_result, i);
    }
    
    return 0;
}
