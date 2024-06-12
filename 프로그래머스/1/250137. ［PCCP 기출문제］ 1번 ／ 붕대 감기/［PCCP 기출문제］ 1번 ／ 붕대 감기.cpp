#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int healthNow = health;
    int time{};
    int cureTime{};

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    for (int i = 0; i < attacks.size(); ++i)
        PQ.push(pair(attacks[i][0], attacks[i][1]));

    while (!PQ.empty())
    {

        if(cureTime > 0)
            healthNow += bandage[1];

        if (cureTime >= bandage[0])
        {
            cureTime = 0;
            healthNow += bandage[2];
        }

        if (healthNow > health)
            healthNow = health;

        if (PQ.top().first == time)
        {
            healthNow -= PQ.top().second;
            cureTime = -1;
            PQ.pop();
        }

        ++time;
        ++cureTime;
        
        if (healthNow <= 0)
            return -1;

    }

    return healthNow;
}