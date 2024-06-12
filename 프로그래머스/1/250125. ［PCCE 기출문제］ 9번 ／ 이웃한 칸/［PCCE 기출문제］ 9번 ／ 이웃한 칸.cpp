#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dirX[] {1,0,-1,0};
    int dirY[] {0,1,0,-1};

    for(int i = 0 ; i < 4 ; ++i)
    {
        int nx = h + dirX[i];
        int ny = w + dirY[i];
        
        if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;
        
        if(board[h][w] == board[nx][ny])
            ++answer;
    }
    
    return answer;
}