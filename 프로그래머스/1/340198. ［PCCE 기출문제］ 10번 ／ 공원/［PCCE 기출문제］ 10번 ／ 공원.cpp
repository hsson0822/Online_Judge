#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int M;

bool checkSeat(vector<vector<string>> park, int x, int y, int size)
{
    if(x + size > N || y +size > M) return false;
    
    for(int i = x ; i < x +size ; ++i)
    {
        for(int j = y ; j < y + size ; ++j)
        {
            if(park[i][j] != "-1")
                return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    N = park.size();
    M = park[0].size();
    cout << N << " " <<  M << endl;
    sort(mats.rbegin(), mats.rend());
    
    bool flag = false;
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            for(int m = 0 ; m < mats.size() ; ++m)
            {
                if(park[i][j] == "-1")
                {
                    if(checkSeat(park, i, j, mats[m]))
                        answer = max(answer,mats[m]);
                }                
            }   
        }
    }
    
    return answer;
}