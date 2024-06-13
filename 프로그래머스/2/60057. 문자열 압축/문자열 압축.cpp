#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 987654321;
    
    if(s.size() <= 1) return s.size();

    for (int i = s.size() - 1; i > 0; --i)
    {
        deque<string> vec;
        string temp = s;

        while (s.size() != 0)
        {
            if (temp.size() > i - 1)
                vec.push_back(temp.substr(0, i));
            else
                vec.push_back(temp.substr(0));

            if (temp.size() < i) break;

            temp = temp.substr(i, temp.size());
        }

        string ans;
        string s;
        int cnt{};
        for (int i = 0; i < vec.size(); ++i)
        {
            if (s == "")
            {
                s = vec[i];
                cnt = 0;
                continue;
            }

            if (s == vec[i])
            {
                ++cnt;
                continue;
            }
            else
            {
                if (cnt < 1)
                    ans += s;
                else
                    ans += to_string(cnt+1) + s;

                s = vec[i];
                cnt = 0;
            }

            if (i == vec.size() - 1)
                ans += s;
        }

        if (answer > ans.size())
            answer = ans.size();
    }

    return answer;
}