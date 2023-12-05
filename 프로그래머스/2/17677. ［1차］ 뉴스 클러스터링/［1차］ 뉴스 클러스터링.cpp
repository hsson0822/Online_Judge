#include <string>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> strA;
    vector<string> strB;
    vector<string> gyo;
    vector<string> hap;

    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (!isalpha(str1[i])) continue;
        if (!isalpha(str1[i + 1])) continue;

        string s;
        s += toupper(str1[i]);
        s += toupper(str1[i + 1]);
        strA.push_back(s);
        hap.push_back(s);
    }

    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (!isalpha(str2[i])) continue;
        if (!isalpha(str2[i + 1])) continue;

        string s;
        s += toupper(str2[i]);
        s += toupper(str2[i + 1]);
        strB.push_back(s);
        hap.push_back(s);
    }
    
    for (int i= 0 ; i < strA.size(); ++i)
    {
        auto iterB = find(strB.begin(), strB.end(), strA[i]);
        if (iterB != strB.end())
        {
            gyo.push_back(strA[i]);

            auto iterC = find(hap.begin(), hap.end(), strA[i]);
            if (iterC != hap.end())
                hap.erase(iterC);

            strA.erase(strA.begin() + i , strA.begin() +i +1);
            strB.erase(iterB);
            --i;

        }
    }

    if (gyo.size() == 0 && hap.size() == 0)
        answer = 65536;
    else
    {
        answer = (double)gyo.size() / (double)hap.size() * 65536;
    }
    
    return answer;
}