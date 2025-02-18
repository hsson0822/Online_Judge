#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int N = wallpaper.size();
    int M = wallpaper[0].size();
    
    int leftX = -1;
    int leftY = -1;
    int rightX = -1;
    int rightY = -1;
    
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                leftX = i;
                break;
            }
        }
        if(leftX != -1)
            break;
    }
    
    for(int j = 0 ; j < M ; ++j)
    {
        for(int i = 0 ; i < N ; ++i)
        {
            if(wallpaper[i][j] == '#')
            {
                leftY = j;
                break;
            }
        }
        if(leftY != -1)
            break; 
    }
    
    
    for(int i = N-1 ; i >= 0 ; --i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                rightX = i;
                break;
            }
        }
        if(rightX != -1)
            break;
    }
    
    for(int i = M-1 ; i >= 0 ; --i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            if(wallpaper[j][i] == '#')
            {
                rightY = i;
                break;
            }
        }
        if(rightY != -1)
            break;
    }
    
    answer.push_back(leftX);
    answer.push_back(leftY);
    answer.push_back(rightX+1);
    answer.push_back(rightY+1);
    
    return answer;
}