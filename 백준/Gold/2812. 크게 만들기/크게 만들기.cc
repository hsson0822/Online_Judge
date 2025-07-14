#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    string str;
    cin>> str;

    vector<char> stack;

    for(char ch : str)
    {
        while(!stack.empty() && K > 0 && stack.back() < ch)
        {
            stack.pop_back();
            --K;
        }
        stack.push_back(ch);
    }

    while(K > 0)
    {
        stack.pop_back();
        --K;
    }

    for(char ch : stack)
        cout << ch;

    return 0;
}