#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int changeTime{};

        string want;
        cin >> want;

        string num;
        for (int i = 0; i < want.size(); ++i)
            num += "0";

        for (int i = 0; i < want.size(); ++i)
        {
            if (want[i] != num[i])
            {
                char change;
                if (want[i] == '1')
                    change = '1';
                else
                    change = '0';

                for (int j = i; j < want.size(); ++j)
                {
                    num[j] = change;
                }

                ++changeTime;
            }
            if (want == num)
                break;
        }

        cout << "#" << test_case << " " << changeTime << "\n";
    }
    return 0;
}