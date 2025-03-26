#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<string, int> person;
int table[51][51];
int point[51];
int presant[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    N = friends.size();
    for(int i = 0 ; i < friends.size() ; ++i)
        person[friends[i]] = i;
    
    for(int i = 0 ; i < gifts.size() ; ++i)
    {
        istringstream ss(gifts[i]);
        vector<string> vec;
        string s;
        while(getline(ss, s, ' '))
            vec.push_back(s);
        
        string A = vec[0];
        string B = vec[1];
        
        ++table[person[A]][person[B]];
        ++point[person[A]];
        --point[person[B]];
    }
    

    
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            if( i >= j) continue;
            
            if(table[i][j] > table[j][i])
                ++presant[i];
            else if(table[i][j] < table[j][i])
                ++presant[j];
            else
            {
                if(point[i] > point[j])
                    ++presant[i];
                else if(point[i] < point[j])
                    ++presant[j];
            }
        }
    }
    
    answer = *max_element(presant, presant+N);
    
    return answer;
}