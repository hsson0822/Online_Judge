#include <string>
#include <vector>

using namespace std;

int N;
vector<pair<int,vector<int>>> table(1000);

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    N = schedules.size();
    
    for(int i = 0 ; i < schedules.size() ; ++i)
    {
        table[i].first = schedules[i];
        for(int j = 0 ; j < timelogs[i].size() ; ++j)
        {
            int today = startday + j;
            if(today == 6 || today == 7) continue;
                
            table[i].second.push_back(timelogs[i][j]);
        }
            
    }
    
    for(int i = 0 ; i < N ; ++i)
    {
        int late{};
        int H1 = table[i].first / 100;
        int M1 = table[i].first % 100;
        M1 += H1 * 60;
        
        for(int j = 0 ; j < 5 ; ++j)
        {
            if(table[i].first >= table[i].second[j]) continue;
            
            int H2 = table[i].second[j] / 100;
            int M2 = table[i].second[j] % 100;
            M2 += H2 * 60;
            
            if(M1 + 10 >= M2) continue;
            else ++late;
        }
        if(late == 0)
            ++answer;
    }
    
    return answer;
}