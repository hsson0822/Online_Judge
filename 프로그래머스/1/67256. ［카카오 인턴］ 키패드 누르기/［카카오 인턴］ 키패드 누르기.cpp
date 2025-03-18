#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

map<int,pair<int,int>> pos;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 11;
    
    int n = 1;
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            pos[n++] = {i,j};
        }
    }
    pos[0] = {3,1};
    pos[10] = {3,0};
    pos[11] = {3,2};
    
    for(int i : numbers)
    {
        if(i==1 || i==4 || i==7)
        {
            answer += 'L';
            left = i;
        }
        else if(i==3 || i == 6 || i == 9)
        {
            answer += 'R';
            right = i;
        } 
        else
        {
        float Llen = abs(pos[left].first - pos[i].first) + abs(pos[left].second - pos[i].second);
        float Rlen = abs(pos[right].first - pos[i].first) + abs(pos[right].second - pos[i].second);
            
            if(Llen < Rlen)
            {
                answer += 'L';
                left = i;
            }
            else if(Llen > Rlen)
            {
                answer += 'R';
                right = i;
            }
            else
            {
                if(hand == "right")
                {
                    answer += 'R';
                    right = i;
                }
                else
                {
                    answer += 'L';
                    left = i;
                }
            }
        }
        
    }
    
    return answer;
}