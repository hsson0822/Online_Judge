#include <string>
#include <vector>

using namespace std;

char field[51][51];
int x;
int y;

int N;
int M;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    N = park.size();
    M = park[0].size();
    
    for(int i = 0 ; i < park.size() ; ++i)
    {
        for(int j = 0 ; j < park[i].size() ; ++j)
        {
            field[i][j] = park[i][j];
            if(park[i][j] =='S')
            {
                x = i;
                y = j;
            }
        }
    }     

    for(string str : routes)
    {
        
        bool flag = false;
        
        if(str[0] == 'N')
        {
            if(x - (str[2]-'0') < 0) continue;
            for(int i = x ; i >= x - (str[2]-'0') ; --i)
            {
                if(park[i][y] == 'X')
                {
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                x -= (str[2]-'0');
        }
        else if (str[0] == 'S')
        {
            if(x + (str[2]-'0') >= N) continue;
            for(int i = x ; i <= x + (str[2]-'0') ; ++i)
            {
                if(park[i][y] == 'X')
                {
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                x += (str[2]-'0');
        }
        else if (str[0] == 'W')
        {
            if(y - (str[2]-'0') < 0) continue;
            for(int i = y ; i >= y - (str[2]-'0') ; --i)
            {
                if(park[x][i] == 'X')
                {
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                y -= (str[2]-'0');
        }
        else if (str[0] == 'E')
        {
            
            if(y + (str[2]-'0') >= M) continue;
            for(int i = y ; i <= y + (str[2]-'0') ; ++i)
            {
                if(park[x][i] == 'X')
                {
                    flag = true;
                    
                    break;
                }
            }
            
            if(!flag)
                y += (str[2]-'0');
                
        }
    }
    
    return {x,y};
}