#include <string>
#include <vector>

using namespace std;

int sum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int N = board.size();
    int M = board[0].size();
    int answer = 0;
    for(int i = 0 ; i < skill.size() ; ++i)
    {
        int category = skill[i][0];
        pair<int,int> start = {skill[i][1],skill[i][2]};
        pair<int,int> end = {skill[i][3],skill[i][4]};
        int damage = category==1 ? -skill[i][5] : skill[i][5];
        
        sum[start.first][start.second] += damage;
        sum[end.first+1][end.second+1] += damage;
        sum[start.first][end.second+1] -= damage;
        sum[end.first+1][start.second] -= damage;
    }
    
    for(int i = 0 ; i < N ; ++i) // 왼쪽에서 오른쪽 누적합
        for(int j = 0 ; j < M ; ++j)
            sum[i][j+1] += sum[i][j];
    
    for(int j = 0 ; j < M ; ++j) // 위에서 아래 누적합
        for(int i = 0 ; i < N ; ++i)
            sum[i+1][j] += sum[i][j];
    
    for(int i = 0 ; i <N ; ++i)
        for(int j = 0 ; j < M ; ++j)
            if(board[i][j] + sum[i][j] > 0)
                ++answer;
        
    return answer;
}