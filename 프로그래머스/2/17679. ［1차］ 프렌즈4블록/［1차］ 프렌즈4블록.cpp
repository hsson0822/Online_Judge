#include <string>
#include <vector>

using namespace std;

vector<string> boards;

bool check(int i , int j, char ch)
{
    if(boards[i][j] == ch && boards[i+1][j] == ch && boards[i][j+1] == ch && boards[i+1][j+1] == ch)
        return true;
    
    return false;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    boards = board;
    
    while(true)
    {
        vector<string> temp = boards;
        int cnt{};
        
        for(int i = 0 ; i < m-1 ; ++i)
        {
            for(int j = 0 ; j < n-1 ; ++j)
            {
                if(boards[i][j] != '0' && check(i,j, boards[i][j]))
                {
                    temp[i][j] = '1';
                    temp[i+1][j] = '1';
                    temp[i][j+1] = '1';
                    temp[i+1][j+1] = '1';
                    ++cnt;
                }
                    
            }
        }
    
        if(cnt == 0)
            break;
        
        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(temp[i][j] == '1')
                {
                    boards[i][j] = '0';
                    ++answer;
                }       
            }
        }
        
        for(int c = 0 ; c <= m ; ++c)
        {
            for(int i = m-1 ; i > 0 ; --i)
            {        
                for(int j = 0 ; j < n ; ++j)
                {
                    if(boards[i][j] == '0')
                    {
                        boards[i][j] = boards[i-1][j];
                        boards[i-1][j] = '0';
                    }
                }
            }
        }
    }
    
    return answer;
}