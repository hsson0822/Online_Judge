#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		vector<int> buildings;
		int count;
		cin >> count;

		for (int i = 0; i < count; ++i)
		{
			int n;
			cin >> n;
			buildings.push_back(n);
		}

		int see{};

		for (int i = 2; i < count-2; ++i)
		{
			int max = buildings[i];
			
			if (buildings[i] > buildings[i - 2])
			{
				if( max > buildings[i] - buildings[i - 2])
					max = buildings[i] - buildings[i - 2];
			}
			else
				continue;


			if (buildings[i] > buildings[i - 1])
			{
				if (max > buildings[i] - buildings[i - 1])
					max = buildings[i] - buildings[i - 1];
			}
			else
				continue;


			if (buildings[i] > buildings[i + 1])
			{
				if (max > buildings[i] - buildings[i + 1])
					max = buildings[i] - buildings[i + 1];
			}
			else
				continue;


			if (buildings[i] > buildings[i + 2])
			{
				if (max > buildings[i] - buildings[i + 2])
					max = buildings[i] - buildings[i + 2];
			}
			else
				continue;

			see += max;
		}

		cout << "#" << test_case << " " << see << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}