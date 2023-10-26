#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    
   vector<int> picked;
    
    for(int now = 0 ; now < moves.size() ; ++now)
    {   
        for(int i = 0 ; i < board.size() ; ++i)
        {
            if(board[i][moves[now]-1] != 0)
            {
                picked.push_back(board[i][moves[now]-1]);
                board[i][moves[now]-1] = 0;
                break;
            }
        }
        
        if(picked.size() >= 2)
        {
            auto it = adjacent_find(picked.begin(), picked.end());
            
            if(it != picked.end())
            {
                picked.erase(it+1);
                picked.erase(it);
                answer += 2;
            }
        }
    }
    
    return answer;
}