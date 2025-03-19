#include <string>
#include <iostream>
#include <vector>

using namespace std;

void change(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    if(wallet[0] > wallet[1])
        change(wallet[0], wallet[1]);
    
    while(true)
    {
        if(bill[0] > bill[1])
            change(bill[0], bill[1]);
        
        if(bill[0] <= wallet[0] && bill[1] <= wallet[1])
            break;
        
        ++answer;
        bill[1] /= 2;
    }
    
    return answer;
}