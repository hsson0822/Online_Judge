
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
		int N;
		int M;
		cin >> N >> M;

		vector<int> two;
		while (M != 0)
		{
			int k = M % 2;
			two.push_back(k);
			M /= 2;
		}

		cout << "#" << test_case << " ";
		if (N > two.size())
		{
			cout << "OFF" << endl;
			continue;
		}

		bool flag = true;
		for (int i = 0; i < N; ++i)
		{
			if (!two[i])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}