#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int bae = max(n,m);
    while(!(bae % n ==0 && bae%m ==0))
    {
        bae += max(n,m);
    }
    
    int yak = min(n,m);
    
    while(!(n % yak == 0 && m % yak == 0))
    {
        --yak;
    }
    
    return {yak, bae};
}