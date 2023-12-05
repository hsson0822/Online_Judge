#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int case_num;
        cin >> case_num;
        
        string wantFind;
        cin >> wantFind;
        
        string str;
        cin >> str;
        
        int count{};
        int pos{};
        auto iter = find(str.begin(), str.end(), wantFind[0]);

        while (iter != str.end())
        {
            string s;
            for (int i = 0; iter+1 < str.end() && i < wantFind.size(); ++i)
                s += (*(iter + i));

            if (s == wantFind)
                ++count;

            iter = find(iter+1, str.end(), wantFind[0]);
        }
                
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}