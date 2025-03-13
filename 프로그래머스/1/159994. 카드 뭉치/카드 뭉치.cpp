#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int card1Idx{};
    int card2Idx{};
    int goalIdx{};
    
    while(goalIdx < goal.size())
    {
        if(cards1[card1Idx] == goal[goalIdx])
        {
            ++card1Idx;
            ++goalIdx;
        }
        else if(cards2[card2Idx] == goal[goalIdx])
        {
            ++card2Idx;
            ++goalIdx;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}