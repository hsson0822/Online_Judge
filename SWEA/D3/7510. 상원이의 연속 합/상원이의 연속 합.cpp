#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;

        int answer{};
        for (int i = 1; i <= n; ++i)
        {
            int sum{};
            for (int j = i; j <= n; ++j)
            {
                sum += j;
                if (sum == n)
                {
                    ++answer;
                    break;
                }
                else if (sum > n)
                    break;
            }
        }

        cout << "#" << test_case << " " << answer << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}