#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string str;
		cin >> str;

		int score{};
		int correct{};

		for (char ch : str)
		{
			if (ch == 'O')
			{
				++correct;
				score += correct;
			}
			else
			{
				correct = 0;
			}
		}
		cout << score << endl;
	}

	return 0;
}