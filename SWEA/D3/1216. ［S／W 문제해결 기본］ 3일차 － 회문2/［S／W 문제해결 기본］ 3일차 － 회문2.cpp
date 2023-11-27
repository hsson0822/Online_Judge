#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    for (test_case = 1; test_case <= 10; ++test_case)
	{
		int size;
		cin >> size;

		vector<string> board;

		for (int i = 0; i < 100; ++i)
		{

			string s;
			cin >> s;
			board.push_back(s);
		}

		int answer = 0;


		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				string garo;

				for (int k = 0; k < 100 - j; ++k)
				{
					garo += board[i][j + k];

					string garoTemp{ garo.begin(), garo.end() };
					reverse(garoTemp.begin(), garoTemp.end());

					if (garo == garoTemp)
					{
						if (answer < garo.size())
							answer = garo.size();
					}
				}

			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				string sero;
				for (int k = 0; k < 100 - j; ++k)
				{
					sero += board[j + k][i];

					string seroTemp{ sero.begin(), sero.end() };
					reverse(seroTemp.begin(), seroTemp.end());

					if (sero == seroTemp)
					{
						if (answer < sero.size())
							answer = sero.size();
					}
				}
			}
		}

		cout << "#" << test_case << " " << answer << "\n";

	}
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}