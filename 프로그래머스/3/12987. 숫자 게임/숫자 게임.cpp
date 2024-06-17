#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    deque<int> nA (A.begin(), A.end());
    deque<int> nB (B.begin(), B.end());
    
    sort(nA.rbegin(), nA.rend());
    sort(nB.rbegin(), nB.rend());
    
    while(!nB.empty())
    {
        if(nA.empty() || nB.empty()) break;
        
        if(nA[0] < nB[0])
        {
            ++answer;
            nA.pop_front();
            nB.pop_front();
        }
        else
        {
            nA.pop_front();
        }
        
    }
    
    return answer;
}