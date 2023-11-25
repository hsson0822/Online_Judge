#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int D;
        cin >> N >> D;

        int answer{};
        
        int k = 2 * D + 1;

        answer += N / k;
        if (N % k != 0)
            ++answer;

        cout << "#" << test_case << " " << answer << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}