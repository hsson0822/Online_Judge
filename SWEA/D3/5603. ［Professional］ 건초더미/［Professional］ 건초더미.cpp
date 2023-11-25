#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int grassCount;
        cin >> grassCount;

        vector<int> grass;
        int sum{};

        for (int i = 0; i < grassCount; ++i)
        {
            int n;
            cin >> n;
            grass.push_back(n);
            sum += n;
        }

        int size = sum / grassCount;
        int moveCount{};

        for (int n : grass)
        {
            if (size > n)
                moveCount += size - n;
            else
                moveCount += n - size;
        }

        cout << "#" << test_case << " " << moveCount/2 << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}