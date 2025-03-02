#include <string>
#include <vector>
#include <iostream>

using namespace std;



void move(int num, int from, int to, int bypass, vector<vector<int>>& answer)
{
    if (num == 1) {
        answer.push_back({from, to});
        return ;
    }
    
	move(num - 1, from, bypass, to, answer);
    
    answer.push_back({from,to});
    
	move(num - 1, bypass, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;    
    move(n, 1, 3, 2, answer);
    
    return answer;
}