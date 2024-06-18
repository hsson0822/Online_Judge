#include <string>
#include <map>
using namespace std;

map<string, int> route;
pair<int,int> dir[4] = {pair(0,-1),pair(1,0),pair(0,1),pair(-1,0)};

int solution(string dirs) {
    int answer = 0;
    
    pair<int,int> pos (pair(0,0));
    
    for(int i = 0 ; i < dirs.size() ; ++i)
    {
        int d;
        if(dirs[i] =='U')
            d = 0;
        else if (dirs[i] == 'R')
            d = 1;
        else if (dirs[i] == 'D')
            d = 2;
        else if (dirs[i] == 'L')
            d = 3;
        
        int nx = pos.first + dir[d].first;
        int ny = pos.second + dir[d].second;
        
        if(nx < -5 || ny < -5 || nx > 5 || ny > 5) continue;
        
        string A = to_string(pos.first) + to_string(pos.second)+to_string(nx) + to_string(ny);
        string B = to_string(nx) + to_string(ny)+to_string(pos.first) + to_string(pos.second);
        
        pos.first = nx;
        pos.second = ny;
        
        if(route[A] > 0 || route[B] >0) continue;
        
        route[A]++;
        route[B]++;
        ++answer;
        
    }
    
    return answer;
}