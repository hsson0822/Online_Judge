#include <string>
#include <vector>
#include <map>
#include <deque>
#include<iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    
    deque<pair<int,int>> onBridge;
    int bridgeWeight{};
    
    while (onBridge.size() != 0 || truck_weights.size() != 0)
    {

        if (onBridge.size() != 0)
        {
            if (onBridge.front().second >= bridge_length)
            {
                bridgeWeight -= onBridge.front().first;
                onBridge.pop_front();
            }
        }

        ++time;

        if (truck_weights.size() != 0)
        {
            if (bridgeWeight + truck_weights.front() <= weight)
            {
                bridgeWeight += truck_weights.front();
                onBridge.push_back(make_pair(truck_weights.front(), 0));
                truck_weights.erase(truck_weights.begin(), truck_weights.begin()+1);
            }
        }
        
        for (int i = 0; i < onBridge.size(); ++i)
            onBridge[i].second++;
        
    }
    return time;
}