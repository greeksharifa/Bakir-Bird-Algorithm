#include<iostream>
#include<string>
#include<vector>

#define MAX_N 102

using namespace std;

int N, M;
string pattern[MAX_N];
string text[MAX_N];

vector<pair<int, int> > matched_list, answer_list;

int main(int argc, char **argv) {
    
    FILE* _ = freopen(argv[1], "r", stdin);
    
    // input
    cin >> M >> N;
    for(int i=0;i<M;i++)
        cin >> pattern[i];
    for(int i=0;i<N;i++)
        cin >> text[i];
    
    _ = freopen(argv[2], "r", stdin);
    
    // input answer(or output of Baker-bird)
    int r, c;
    while(scanf("%d %d", &r, &c) != EOF){
        answer_list.emplace_back(r, c);
    }
    
    // naively compare pattern and text
    for(int row=0;row<N-M+1;row++){
        for(int col=0;col<N-M+1;col++){
            bool matched = true;
            for(int i=0;i<M;i++){
                for(int j=0;j<M;j++){
                    if(pattern[i][j] != text[row+i][col+j]){
                        matched = false;
                        break;
                    }
                    if(!matched)
                        break;
                }
            }
            if(matched){
                matched_list.emplace_back(row+M-1, col+M-1);
            }
        }
    }

    _ = freopen(argv[3], "w", stdout);
    
    bool correct = true;
    /* compare two results.
     * both the order of matched position are ascending order,
     * so comparing the corresponding position is enough for checking.
     */
    if(matched_list.size() == answer_list.size()){
        for(int i=0;i<matched_list.size();i++){
            pair<int, int> matched = matched_list[i];
            pair<int, int> answer = answer_list[i];
            
            if((matched.first != answer.first) ||
               (matched.second != answer.second))
                correct = false;
        }
    }else{
        correct = false;
    }
    
    printf(correct? "yes\n" : "no\n");
    
    return 0;
}