#ifndef HW1_AHO_CORASICK_H
#define HW1_AHO_CORASICK_H

#define SIGMA 62

#include <string>
#include <vector>
#include <queue>

using namespace std;

/* convert character to index.
 * [a..z] is [ 0..25]
 * [A..Z] is [26..51]
 * [0..9] is [52..61]
 */
int chr2idx(char c){
    if('a' <= c && c <= 'z')
        return c - 'a';
    else if('A' <= c && c <= 'Z')
        return c - 'Z' + 26;
    else
        return c - '0' + 52;
}

// define Trie node
struct Trie {
public:
    int end_num;             // row number of pattern
    vector<Trie*> child;     // link to child nodes
    Trie* fail;              // fail link ⭐
    
    Trie() : end_num(-1), fail(nullptr) {
        child = vector<Trie*>(SIGMA, nullptr);
    }
    
    // insert N patterns
    int Insert(string pattern, int num) {
        Trie *now = this;
        for(auto& p : pattern){
            int idx = chr2idx(p);
            if (now->child[idx] == nullptr)
                now->child[idx] = new Trie;
            now = now->child[idx];
        }
        // assign end of pattern, and check duplicate
        if (now->end_num == -1)
            now->end_num = num;
        
        return now->end_num;
    }
    
    void create_fail_link() {
        queue<Trie *> q;
        Trie *root = this;
        q.push(root);
        
        // to obtain the fail link, run BFS by depth
        while (!q.empty()) {
            Trie *now = q.front();  q.pop();
            
            for(int i=0; i< SIGMA; i++){
                if(!now->child[i])
                    continue;
                Trie* next = now->child[i];
                
                // if root, fail link is root
                if (now == root)
                    next->fail = root;
                else { // else, find longest matched suffix
                    Trie *prev = now->fail;
                    while (prev != root && prev->child[i] == nullptr)
                        prev = prev->fail;
                    if (prev->child[i] != nullptr)
                        prev = prev->child[i];
                    next->fail = prev;
                }
                
                /* in original Aho-corasick, some patterns can be included in other patterns.
                 * but, in this problem, the length of all patterns are same,
                 * so following 2 lines aren't mean much.
                 */
                if (next->fail->end_num != -1)
                    next->end_num = next->fail->end_num;
                
                q.push(next);
            }
        }
    }
};

/* calculate result of Aho-corasick, one row by onw row
 * the result is matched pattern number,
 * 0 is not match, [1..M] is the row number of pattern
 */
vector<int> row_Aho(string text, Trie *root, int N) {
    Trie *now = root;
    
    vector<int> result(N, 0);
    
    for (int i = 0; i < N; ++i) {
        int idx = chr2idx(text[i]);
        while (now != root && now->child[idx] == nullptr)
            now = now->fail;
        if (now->child[idx] != nullptr)
            now = now->child[idx];
        if (now->end_num != -1) {
            result[i] = now->end_num;
        }
    }
    return result;
}

#endif //HW1_AHO_CORASICK_H
