#include<iostream>
#include<deque>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int squared;
		cin >> squared;

		deque<int> people;
		deque<int> temp;
		for (int i = 0; i < pow(2, squared); ++i)
		{
			int n;
			cin >> n;
			people.push_back(n);
		}

		int answer{};

		for (int i = 0; i < squared; ++i)
		{
			int game = people.size();
			for (int j = 0; j < game / 2; ++j)
			{
				int a = people.front();
				people.pop_front();

				int b = people.front();
				people.pop_front();

				if (a > b)
				{
					temp.push_back(a);
					answer += a - b;
				}
				else
				{
					temp.push_back(b);
					answer += b - a;
				}
			}

			people = temp;
			temp.clear();
		}


		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}