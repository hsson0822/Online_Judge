#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int day;
        int hour;
        int min;
        long total{};
        cin >> day >> hour >> min;
        total = day * 1440 + hour * 60 + min;

        long eleven = 11 * 1440 + 11 * 60 + 11;

        long answer{};

        if (total < eleven)
            answer = -1;
        else if (total == eleven)
            answer = 0;
        else
            answer = total - eleven;

        cout << "#" << test_case << " " << answer << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}