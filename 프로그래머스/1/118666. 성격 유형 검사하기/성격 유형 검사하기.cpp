#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char,int> personal;

void setPoint(char A, char B, int point)
{
    if(point == 1)
        personal[A] += 3;
    else if(point == 2)
        personal[A] += 2;
    else if(point == 3)
        personal[A] += 1;
    else if(point == 5)
        personal[B] += 1;
    else if(point == 6)
        personal[B] += 2;
    else if(point == 7)
        personal[B] += 3;
}

char getPoint(char A, char B)
{
    if(personal[A] > personal[B])
        return A;
    else if (personal[A] < personal[B])
        return B;
    else
    {
        if(A > B)
            return B;
        else
            return A;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    personal['R'] = 0;
    personal['T'] = 0;
    personal['C'] = 0;
    personal['F'] = 0;
    personal['J'] = 0;
    personal['M'] = 0;
    personal['A'] = 0;
    personal['N'] = 0;
    
    for(int i = 0 ; i < survey.size() ; ++i)
        setPoint(survey[i][0], survey[i][1], choices[i]);
    
    answer += getPoint('R', 'T');
    answer += getPoint('C', 'F');
    answer += getPoint('J', 'M');
    answer += getPoint('A', 'N');
    
    return answer;
}