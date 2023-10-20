#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    pair<int, int> dun[9];
    vector<int> v;
    
    for( int i = 0 ; i < dungeons.size() ; ++i)
    {
        dun[i+1] = {dungeons[i][0], dungeons[i][1]};
        v.push_back(i+1);
    }
    
    do
    {
        int temp = k;
        int count{};
        
        for(int i = 0 ; i < v.size() ; ++i)
        {
            if(temp >= dun[v[i]].first)
            {
                ++count;
                temp -= dun[v[i]].second;
            }
        }
        
        if(answer < count)
            answer = count;
        
    }while(next_permutation(v.begin(), v.end()));
  
    
    return answer;
}